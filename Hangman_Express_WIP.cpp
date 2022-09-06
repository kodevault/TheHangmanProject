// Ahorcado
// Made in Mario Rueda

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h> 
#include <time.h>
#include <math.h>

long sacapalabras (char fichero[], char palabra[]); // Saca una palabra aleatoria de un fichero .txt
long loadgame(char savefile[], int aux[]);
long savegame(char savefile[], int win, int lose);
int anticheats(char savefile[]);
int banner();
int monigote(int Intentos); // Pinta el muñeco en base al numero de intentos restantes


int main() // Void main()
{
	int i, x, player=1, cycle=1, ronda=0, status, correctas, intentos=10, aux[10], acierto, puntos1=0, puntos2=0;
	char play='S', letra, menu, letras[20], palabra[25], tryword[25], nombre1[10], nombre2[10];
	char fich[]={'l','i','b','r','o','.','t','x','t','\0'};
	char savefile[]={'s','a','v','e','g','a','m','e','.','t','x','t','\0'};

	banner();
	printf("                                                v3.12.95 'Estefi's Bday Update'\n\n");
	printf("  \n");  
	printf("  0 - Nueva partida \n");
	printf("  1 - Continuar \n");
	printf("  2 - Modo dificil: \n");
	//printf("  X- NSFWmode -not implemented yet\n");	

while(cycle==1)
{	printf("\n  >");
	fflush(stdin);
	scanf("%c", &menu);		//almacena un caracter en la variable menu
	menu=toupper(menu);  	//convierte en mayuscula el caracter almacenado en la variable "menu"
	
	switch (menu)			
	{
		case '0': //NEW GAME		  
			
			cycle=0;
			break;			
		case '1': //LOAD GAME
			status=anticheats(savefile);
			if (status==0) 
				{
				//printf("  rerun\n");
				//getch();
				status=anticheats(savefile);
				//printf("  rerun done\n");
				//getch();
				}
			if (status==1)
			{	//printf("  ahorasi\n");
				loadgame(savefile, aux);
				puntos1=aux[1];
				puntos2=aux[2];
				anticheats(savefile);
				cycle=0;
			}
			else 
			{	
				printf("\n  No se encuentra o se ha modificado el fichero savegame.txt");
				getch();
				break;
			}
			break;
		case '2':
			printf("HARDMODE \n");
			
			break;			
		case 'X':
			printf("PORN MODE \n");
			cycle=0;
			break;		
			
		default:	// Entrara por esta opcion si el caracter introducido no es ninguno de los anteriores
			printf("  Opcion no valida\n");
			fflush(stdin);
		}	
}

// GAME START && RESET DE VARIABLES	
while(play=='S')
{	ronda++, intentos=10;  correctas=0;  letra='\0';   letras[0]='\0';  x=0;  
	sacapalabras(fich,palabra);

	fflush(stdin);
	system("cls");	
		
	// MISC		
	for (i=0 ; i<strlen(palabra) ; i++)	// Por cada letra que tenga la palabra oculta...
		tryword[i]='_';					// ... asigna un '_'
		tryword[strlen(palabra)]='\0'; // Asigna el final de la cadena (fuera de bucle)
	
	while (intentos>0 && correctas<strlen(palabra))	
	{	acierto=0;	
		letras[x]=letra; // le pasa la letra escaneada al vector que almacena todas las letras
		x++;
		
		// INTERFACE			
		system("cls");
		printf("\n  La palabra tiene %d letras. \t\t\t  Palabras acertadas: %d\n",strlen(palabra), puntos1);
		printf("  Intentos Restantes: %d \t\t\t  Palabras falladas: %d\n",intentos, puntos2);	
		printf("  Letras Probadas:");
			for (i=0 ; i<x ; i++)	
				printf("%c ",letras[i]); // pinta todas las letras que se han intentado
		printf("\n\n  Palabra: %s  \n\n  ",tryword);  // pinta las letras descubiertas "E_EM_L_"
		monigote(intentos); // pinta el muñeco
//		printf("La palabra es: '%s'",palabra);
		fflush(stdin);
		scanf("%c", &letra); // escanea la letra
		
		// MAGIC HAPPENZ HERE	(Comprueba si hay coincidencias)
		for (i=0 ; i<strlen(palabra) ; i++)
			if (letra==palabra[i] && letra!=tryword[i]) 
			{	tryword[i]=letra;
				acierto++;
				correctas++;
			}
		
			if (i==strlen(palabra) && acierto==0) //(fuera de bucle)
				intentos--;	// Resta un intento si tras recorrer toda la palabra no habia letras correctas	
	}

	// GAME OVER		
	if (intentos==0)
	{	puntos2++;
		system("cls");
		//Sleep(500);
		printf("\n  GAME ");
		Sleep(500);
		printf("OVER ");
		Sleep(500);
		printf("BITCH\n");
		Sleep(500);
		printf("  _____     \n");
		printf("  |/  |     \n");	
		printf("  |  /O\\     \n");
		printf("  |  (|)   \n");
		printf("  |  / \\   \n");
		printf("  |_______\n\n  ");	
		printf("La palabra era: '%s'",palabra);
	}
	
	// WIN		
	else 
	{	puntos1++;
		system("cls");
		printf("\n  PREMIO!!! Adivinaste '%s'", palabra);
		fflush(stdin);
	}
	
	// PLAY AGAIN		

	
	printf("\n\n  Y ahora que...?:\n\n");  
	printf("  X - Guardar y salir.\n");
	printf("  S - Guardar y seguir jugando \n");
	printf("\n  Pulsa Enter para seguir jugando\n  >");
		
	fflush(stdin);
	scanf("%c", &menu);		//almacena un caracter en la variable menu
	menu=toupper(menu);  	//convierte en mayuscula el caracter almacenado en la variable "menu"
	
	switch (menu)			// crea un bucle, segun el caracter almacenado entrara por un case u otro
	{
	case 'x':			
	case 'X': 	//save&exit
		savegame(savefile, puntos1, puntos2);
		anticheats(savefile);
		exit(0);			
		
	case 's':
	case 'S':	//save&play
		savegame(savefile, puntos1, puntos2);
		anticheats(savefile);
		printf("\n\n  Recuerda que no es necesario guardar la partida en cada turno\n\n");
		getch();
		break;

		
	default:	// Entrara por esta opcion si el caracter introducido no es ninguno de los anteriores
	printf("\n\n  patata frita:\n\n");
		break;
	}	
		//getch();   
}
}
/*	printf("\n\n  Jugar otra vez?\n\n");
	getch();  
*/



//---- FUNCIONES ----//
long sacapalabras (char fichero[], char palabra[])
{
	FILE *texto;	
	long num_pal=0;	
    int i, aux;
    char ok='n';
	srand(time(NULL));

    texto=fopen (fichero, "r");	

	while ((fscanf(texto,"%s",palabra))!=EOF)
		num_pal++;	// me da el numero de palabras del fichero, esta dentro del while

	rewind(texto);	
	aux=3*rand();	
	aux=3*rand();	// si no esta dos veces no funciona, no se randomiza
	
	while(ok!='s')
	{	for (i=0;i<aux;i++) 
		{
			fscanf(texto,"%s",palabra);
		}
		if(strlen(palabra)>=5)
			for (i=0;i<=strlen(palabra);i++)
				palabra[i]=tolower(palabra[i]);
			ok='s';				
	}
	fclose (texto); 

	return (num_pal);
}
//-----------------------
int anticheats(char savefile[])
{	
	char ch, ciphcheck;
	int ciphered=1, i=0, plaintxt=0; 
	int hex=0x420;    
	FILE *original, *temp;
			
	original=fopen(savefile, "r"); 
	temp=fopen("temp.txt", "w");
 
	for(i=0; i<5; i++)		// este FOR averigua si el fichero esta o no cifrado
	{
		ciphcheck=fgetc(original);
		
		if(ciphcheck == 35 )  // si es '#'
		{	
			plaintxt++;
			if (plaintxt==5)
			{	
				ciphered=0;
				break;		
			}
		}
	}
	
	fseek(original, 0, SEEK_SET);	
	
	while(1)	// con este WHILE vamos leyendo el fichero original caracter a caracter y escribiendo en el temporal
	{	
		ch=fgetc(original);
		
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
//-----------------------
long loadgame(char savefile[],int aux[])
{
	FILE *original;
    int i=0;
    char palabra[10]; 
		
	original=fopen(savefile, "r"); 

	while((fscanf(original,"%s",palabra))!=EOF)
	{	
		//if (i==0) printf ("##: %s\n",palabra);
	 	if (i==1) 	
		{
			aux[i]=atoi(palabra);	// WINS
			//printf("win: %i \n",*win);
			//printf("win: %i \n",aux[i]);
		}
		else if (i==2) 	
		{
			aux[i]=atoi(palabra);	// LOSES
			//printf("lose: %i \n",lose);
		}
//		else if (i==X) AQUI AÑADIMOS EL RESTO DE LINEAS A CARGAR DESDE EL SAVEGAME
		i=i+1;
}
	
	fclose (original); 
	return (0);
}

//-----------------------
long savegame(char savefile[], int win, int lose)
{
	FILE *original;
    int i;
    char cabecera='#', nl=13; 
		
	original=fopen(savefile, "w"); 
	for(i=0;i<5;i++)
	{	fputc(cabecera, original);}
	fputc(nl, original);
	fprintf(original,"%d",win);
	fputc(nl, original);
	fprintf(original,"%d",lose);
	fputc(nl, original);
	for(i=0;i<5;i++)
	{	fputc(cabecera, original);}
	
	fclose (original); 
	return (0);
}
//-----------------------
int banner()
{		printf(" \n");
		printf("                                                                    ________ \n");
		printf("  ##   ## ####### ###	 ## ######## ###     ### ####### ###	##  | /    |	   \n");
		printf("  ##   ## ##   ## ####	 ## ##	  ## ####   #### ##   ## ####	##  |/    /O\\    	\n");	
		printf("  ####### ####### ## ##	 ## ##       ##	## ## ## ####### ## ##	##  |     (|)   	\n");
		printf("  ####### ####### ##  ## ## ##  #### ##	 ###  ## ####### ##  ## ##  |     / \\  	\n");
		printf("  ##   ## ##   ## ##   #### ##    ## ##	  #   ## ##   ## ##   ####  |        	\n");
		printf("  ##   ## ##   ## ##	### ######## ##       ## ##   ## ##    ###  |_________       \n");	
		printf("################################################################################ \n");
		//getch(); 			
}		
//-----------------------
int monigote(int Intentos)
{
if(Intentos==9)	
{
printf("            \n");
printf("            \n");
printf("            \n");
printf("            \n");
printf("            \n");
printf("  |_______\n\n  > ");
}
else if(Intentos==8)
{
printf("            \n");
printf("            \n");
printf("            \n");
printf("            \n");
printf("  |         \n");
printf("  |_______\n\n  > ");
}
else if(Intentos==7)
{
printf("            \n");
printf("            \n");
printf("            \n");
printf("  |         \n");
printf("  |         \n");
printf("  |_______\n\n  > ");
}
else if(Intentos==6)	
{
printf("            \n");
printf("            \n");
printf("  |         \n");
printf("  |         \n");
printf("  |         \n");
printf("  |_______\n\n  > ");	
}
else if(Intentos==5)	
{
printf("            \n");
printf("  |/        \n");	
printf("  |         \n");
printf("  |         \n");
printf("  |         \n");
printf("  |_______\n\n  > ");
}	
else if(Intentos==4)	
{
printf("_____       \n");
printf("  |/        \n");	
printf("  |         \n");
printf("  |         \n");
printf("  |         \n");
printf("  |_______\n\n  > ");
}
else if(Intentos==3)	
{
printf("_____       \n");
printf("  |/  |     \n");	
printf("  |         \n");
printf("  |         \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");	
}
else if(Intentos==2)	
{
printf("_____       \n");
printf("  |/  |     \n");	
printf("  |  /O\\     \n");
printf("  |         \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");	
}
else if(Intentos==1)	
{
printf("_____       \n");
printf("  |/  |     \n");	
printf("  |  /O\\     \n");
printf("  |  (|)   \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");
}}
	
