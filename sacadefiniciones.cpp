#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h> 
#include <time.h>
//#include <math.h>

 /*
 scan primera letra palabra>
 scan diccionario, if primera letra de la linea != palabra; i++>if primera letra ==1ra letra palabra; 
 scan palabra while char!= ',' o '.'> if palabra==palabra; read until /n and print
*/
long sacapalabras (char fichero[], char palabra[], int longitud);
long diccionario (char fichero[], char palabra[],char definicion[]); // Saca una palabra aleatoria de un fichero .txt

//---------------
int main() 
{
	int longitud=6;
	char palabra[25], definicion[1024];
	char fich[]={'l','i','b','r','o','.','t','x','t','\0'};
	char rae[]={'R','A','E','.','t','x','t','\0'};

while(1)
{
		sacapalabras(fich,palabra,longitud);
//	printf("\n  0-Palabra: %s",palabra);
//	printf("\n  1st-Palabra: %c",palabra[0]);
	
	diccionario(rae,palabra,definicion);}
}
//---------------

long diccionario (char fichero[], char palabra[], char definicion[])
{
	FILE *texto;		
    int i, equal=0, found=0, lines=0,aux=0;
    int maxchars=1024;

    texto=fopen (fichero, "r");	
    while (fgets (definicion, maxchars, texto)!=NULL)
	 { lines++;	}
	 
    rewind(texto); 
    
    while (fgets (definicion, maxchars, texto))		//Escanea lineas completas
	{	aux++;
	//printf("\n  aux: %i not found",aux);
		/*printf("\n  Palabra: %s",palabra);
		printf("\n  1st-Palabra: %c",palabra[0]);
        printf("\n  Definicion: %s",definicion);
        printf("\n  1st-Definicion: %c",definicion[0]);
		getch();*/
		if(palabra[0]==definicion[0])
		{	
			equal=0;
			for(i=0;i<=strlen(palabra);i++)
			{	
				if(palabra[i]!=definicion[i]) {i=99;}
				else if(palabra[i]==definicion[i])
				{
					equal++;
					if(equal==strlen(palabra) )
					{
						if(definicion[i+1]==1 || definicion[i+1]==2 || definicion[i+1]==',' || definicion[i+1]=='.') 						
						{
							printf("\n\n  ##########");
							printf("\n  RESULTADO");
							printf("\n  R-Palabra: %s",palabra);
							printf("\n  R-Definicion: %s",definicion);
							printf("  ##########");
							found=1;
							aux=0;
							//fclose (texto);
						//	getch();
						}
					}
				}
			}				
		}		
	}
	if(aux>=lines)	
	{	printf("\n  lines: %i ",lines);
		printf("\n  aux: %i ",aux);
	printf("\n  404Palabra: %s not found",palabra);}
	getch();
    fclose (texto);
}

//***************************************
long sacapalabras (char fichero[], char palabra[], int longitud)
{
	FILE *texto;	
	long num_pal=0;	
    int i, ii=0, aux, x=0;
    char ok='n';
	srand(time(NULL));

    texto=fopen (fichero, "r");	

	while ((fscanf(texto,"%s",palabra))!=EOF)
	num_pal++;	// me da el numero de palabras del fichero, esta dentro del while
	rewind(texto);	
	
	//aux=3*rand();	
	//aux=3*rand();	// si no esta dos veces no funciona, no se randomiza
	
	while(ok!='s')
	{	aux=rand();
		//aux=3*rand();
		//printf("RANDOM:%i",aux);
		//getch();
		for (i=0;i<aux;i++) 
		{
			fscanf(texto,"%s",palabra);
			//printf("%s",palabra);
		}
		ii=ii+i;
		//printf("\nIIIII:%i \n",ii);
		//printf("NUMPALABRAS:%i \n",num_pal);
		//getch();
		if (ii>=num_pal) 
		{ 
			rewind(texto); 
			ii=0;
		}
		else if(strlen(palabra)<=longitud)
		{
			for (i=0;i<=strlen(palabra);i++,x++)
			{	//printf("III: %i\n",i);
				//printf("XXX: %i\n",x);
				if(palabra[i]==-61)
				{ 
				i++;
				palabra[i]=164; 
				}
				palabra[x]=tolower(palabra[i]);
				//printf("letra: %i\n",palabra[x]);
			}	
			ok='s';	
		}
	}
	fclose (texto); 

	//////return (num_pal);
}
