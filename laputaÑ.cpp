#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h> 
#include <time.h>
#include <math.h>
// ñ= -61 -111
long sacapalabras (char fichero[], char palabra[]); // Saca una palabra aleatoria de un fichero .txt
long loadgame(char savefile[], int aux[]);
long savegame(char savefile[], int win, int lose, int bestracha);
int anticheats(char savefile[]);
int banner();
int monigote(int Intentos); // Pinta el muñeco en base al numero de intentos restantes


int main() // Void main()
{
	char play='S', letra, menu, letras[20], palabra[25], tryword[25];// nombre1[10], nombre2[10];
	char fich[]={'l','i','b','r','o','.','t','x','t','\0'};
	
	sacapalabras(fich,palabra);
	printf("\n  La palabra es: '%s'",palabra);
	
		
	
}
long sacapalabras (char fichero[], char palabra[])
{
	FILE *texto;	
	long num_pal=0;	
    int i, aux, x=0;
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
			for (i=0;i<=strlen(palabra);i++,x++)
			{	printf("III: %i\n",i);
				printf("XXX: %i\n",x);
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
	fclose (texto); 

	return (num_pal);
}
