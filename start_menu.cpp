// Compilable
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	char menu; 		
	int cycle=1;
	
	printf("  Este es tu menu: \n\n");  
	printf("  0- Nueva partida \n");
	printf("  1- Continuar \n");
	printf("  2- Hardmode -not implemented yet\n  ");
	//printf("  X- NSFWmode -not implemented yet\n");	

while(cycle==1)
{	scanf("%c", &menu);		//almacena un caracter en la variable menu
	menu=toupper(menu);  	//convierte en mayuscula el caracter almacenado en la variable "menu"
	
	switch (menu)			// crea un bucle, segun el caracter almacenado entrara por un case u otro
	{
	//case 'A':				// El case 'X' determina que caracter necesitas para entrar a cada opcion, se pueden crear varios
	case '0': 			  // case 'X' para entrar con diferentes respuestas a una misma opcion, se pueden usar numeros o letras
		printf("NEW GAME\n"); 
		cycle=0;
		break;			// IMPRESCINDIBLE, hasta que no llega al break no sale del case en el que haya entrado
		
	//case 'B':
	case '1':
		printf("LOAD GAME\n");
		cycle=0;
		break;
		
	//case 'C':
	case '2':
		printf("HARDMODE \n");
		cycle=0;
		break;
		
	case 'X':
		printf("PORN MODE \n");
		cycle=0;
		break;		
		
	default:	// Entrara por esta opcion si el caracter introducido no es ninguno de los anteriores
		printf("  Opcion no valida\n");
	}	
}
	//	getch();   
}
		 
