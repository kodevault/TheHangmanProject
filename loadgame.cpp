#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

long loadgame(char savefile[], int aux[]);

int main()
{
	int aux[10], i;
	char savefile[]={'s','a','v','e','g','a','m','e','.','t','x','t','\0'};
	
	loadgame(savefile, aux);
	
	printf("win: %i \n",aux[1]);
	printf("lose: %i \n",aux[2]);
	aux[1]++;
	aux[2]++;
	printf("win: %i \n",aux[1]);
	printf("lose: %i \n",aux[2]);

}
//-------------------------
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


