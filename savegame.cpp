#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

long savegame(char savefile[], int win, int lose);

int main()
{
	int aux[10], i, win=666, lose=240;
	char savefile[]={'s','a','v','e','g','a','m','e','.','t','x','t','\0'};
	
	savegame(savefile, win, lose);
/*	
	printf("win: %i \n",aux[1]);
	printf("lose: %i \n",aux[2]);
	aux[1]++;
	aux[2]++;
	printf("win: %i \n",aux[1]);
	printf("lose: %i \n",aux[2]);
*/
}
//-------------------------
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


