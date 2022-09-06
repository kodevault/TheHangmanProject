#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>
/*
fichero con formato fijo y cifrado basico
if char [x]=###### cifra; else descifra y rebobina

banner-menu-load
descifra-read2variable-cifra
endgame menu
x para guardar y salir
s para guardar
else keep playing

scan again; char[X]= acertadas; char [Y]= falladas;best racha...
endgame:

*/
int anticheats(char savefile[]);

int main()
{
	char savefile[]={'s','a','v','e','g','a','m','e','.','t','x','t','\0'};
	int PoC;
	
	PoC=anticheats(savefile);
	
	if(PoC==1)	{printf("FICHERO DESCIFRADO ");	} 
	if(PoC==0)	{printf("FICHERO CIFRADO ");	}
	
//printf("  000xxx000 \n");	
}

//----
int anticheats(char savefile[])
{	
	char ch, ciphcheck;
	int ciphered=1, i=0, plaintxt=0; 
	int hex=0x420;    
	FILE *original, *temp;
			
	original=fopen(savefile, "r"); 
	temp=fopen("temp.txt", "w");
 
//	ciphcheck=fgetc(original);
//	printf("  lel %i \n",ciphcheck);
/*	printf("  -%i- \n", original);
	ciphcheck=fgetc(original);
//	
	printf("  000xxx000 \n");
	printf("  %i \n",ciphcheck);
	printf("  000xxx000 \n");
	
	printf("  0000000000 \n");
*/	
	for(i=0; i<5; i++)		// este FOR averigua si el fichero esta o no cifrado
	{
		//printf("  1111111111 \n");
		ciphcheck=fgetc(original);
		//printf("  %i \n",ciphcheck);
		//printf("  2222222222 \n");
		
		if(ciphcheck == 35 )  // si es '#'
		{	//printf("  %i \n",ciphcheck);
			plaintxt++;
			if (plaintxt==5)
			{	//printf("  plaintext \n");	
				ciphered=0;
				break;		
			}
		}
	}
	//printf("  333333 \n");
	fseek(original, 0, SEEK_SET);	// como previamente hemos leido parte del fichero para ver si estaba o no cifrado, volvemos a colocar el buffer al principio del mismo
	//printf("  4444 \n");
	while(1)	// con este WHILE vamos leyendo el fichero original caracter a caracter y escribiendo en el temporal
	{	
		ch=fgetc(original);
		//printf("  entra while %c \n",ch);
		
		if(ch==EOF)		// si ch == End Of File, forzamos salida
		{	//printf("  EOF!!!!!!!!!!!!!! \n");
			break;
		}
		else if(ch=='\n')	// si ch es salto de linea
		{	//printf("  CH13 \n");
			fputc(ch, temp); // conservamos dicho salto sin cifrar ya que es el que nos marca cuando cambiamos de cifrado
		}
		else	// cifrar/descifrar y escribir
		{	
			if(ciphered==1)	
			{//printf("  es cifered \n");
				ch=ch-hex;
				//printf("\n patata %i ",ch);
				//getch();
			}
			else if(ciphered==0)
			{
				ch=ch+hex;
			}
			fputc(ch, temp);						
		}
	}
	//printf("  WILE OK \n");			
	fclose(original);	
	fclose(temp);

	original=fopen(savefile, "w");
	temp=fopen("temp.txt", "r");
		
	while(1) // este WHILE va machacando el fichero original con lo que hemos almacenado en el temporal
	{	
		ch=fgetc(temp);
		if(ch==EOF)
		{	
			fclose(temp);
			remove ("temp.txt");	// borramos el temporal para no dejar basura por ahi
			fclose(original);
			break;
		}
		else
		{	
			fputc(ch, original);
		}
	}
	
	if(ciphered==1)	{return 1;}  //FICHERO DESCIFRADO ");	} // si estaba cifrado, ya no lo esta, y viceversa
	if(ciphered==0)	{return 0;}  // FICHERO CIFRADO "); }
	//Sleep(1000);*/
	//return 0;
}

