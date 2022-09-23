// Ahorcado
// Made in Mario Rueda

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h> 
#include <time.h>

long sacapalabras (char fichero[], char palabra[],int longitud); // Saca una palabra aleatoria de un fichero .txt
long diccionario (char fichero[], char palabra[],char definicion[]);
int checkstatus(int input, char output[]);
int checkWL(int input, char output[]);
long loadgame(char savefile[], int aux[]);
int salvaenes(char palabra[]);
long savegame(char savefile[], int aux[]);
int aux2save(int aux[], int win, int lose, int bestracha, int antivicio, int dia, int suficientexhoy, int ronda, int comodines);
int decidir();
int anticheats(char savefile[]);
int banner();
int minibanner();
int mainmenu(int currentconfig[]);
int monigote(int Intentos); 

int main() 
{	//char normal[]={'r','a','n','d','o','m','.','t','x','t','\0'};
	char NSFW[250][25] = {"abanto","abrazafarolas","acojonar","agilipollado","amamonado","anal","anormal","arrabalero","asquerosa","baboso","barriobajero","bastardo","bebecharcos","besugo","bocabuzon","bocachancla","bollera","bondage","borrachuzo","botarate","braguetazo","bujarra","bukkake","cabestro","cabezaalberca","cabezabuque","cabron","cachonda","cagada","cagarruta","calentorra","calenturiento","calientahielos","calientapollas","calzonazos","cantamañanas","capullo","caracaballo","caraculo","casquete","cazurro","cenutrio","ceporro","chichi","chingada","chocho","chochona","chuloputas","chumino","chupacables","chupapollas","chupoptero","cipote","cojones","comemierda","cornudo","correrse","corrida","coño","cuerpoescombro","culear","culero","culopollo","descerebrado","desequilibrada","desnudarse","drogata","empotrador","encular","enganchado","engañabobos","ereccion","estupido","facha","facoquero","falo","fanfosquero","fantoche","fariseo","farsante","filimincias","foligoso","follador","follar","fulana","furcia","gandul","gatillazo","gañan","gilipollas","gilipuertas","giraesquinas","gorrino","guarra","hijodeputa","hijoputa","hostia","ignorante","imbecil","impresentable","incesto","jiñarse","joder","kamasutra","lamebolas","lamecharcos","lameculos","lefazo","lerdo","machacarsela","machorra","malfollada","malnacido","malparida","mamada","mamahuevos","mamarracho","mamavergas","mameluco","mamon","mamporrero","mangante","marica","maricon","maricona","mariconazo","marimacho","mariposon","mastuerzo","masturbarse","meapilas","mendrugo","mentecato","mequetrefe","merluzo","mierda","mindundi","miserable","mocoso","mojigata","mojon","mongolito","mongolo","morralla","morroestufa","muerdesartenes","mugrosa","nalgas","negrata","negrero","orgasmo","orgia","pagafantas","paja","pajero","pajillero","palurdo","panoli","papafrita","paquete","pardillo","parguela","pasmarote","pataliebre","payaso","pazguato","pecholata","pecora","pedorra","peinabombillas","pelandrusca","pelele","pendejo","percebe","perroflauta","pesetero","petarda","pichabrava","pichafloja","pintamonas","piojoso","pirado","plomazo","pocasluces","polla","pollon","porculelo","porno","pornochacha","pornografia","porrero","porros","pringado","proxeneta","puerco","putas","putero","puticlub","putiferio","putilla","puton","ramera","rebañasandias","reinona","reputa","retrasado","roñosa","sabandija","sadomaso","sanguijuela","sarasa","sarnosa","sexo","sinvergüenza","soplapollas","striptease","subnormal","sudaca","tagarote","tanga","tarado","tarugo","tetas","tiralevitas","tocacojones","tocapelotas","tolai","tordo","tortillera","tragaleche","tragapollas","tragasables","truño","tusmuertos","voyeur","zamacuco","zambombo","zampabollos","zamugo","zangano","zarrapastroso","zascandil","zopenco","zoquete","zorra","zorripuerca","zorrona","zullenco","zurcefrenillos","zurullo"};
	//char NSFW[250][25] = {"abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso","abñanto","abrazañfarolas","acoñjonar","agilipoñllado","amamonñado","anñal","anormñal","arrañbalero","asquñerosa","babñoso",};
	char fich[]={'W','L','-','R','A','E','.','t','x','t','\0'};
	char wlrae[]={'W','L','-','R','A','E','.','t','x','t','\0'};
	char verbos[]={'v','e','r','b','o','s','.','t','x','t','\0'};
	char ingles[]={'i','n','g','l','e','s','.','t','x','t','\0'};
	char rae[]={'R','A','E','.','t','x','t','\0'};
	char savefile[]={'s','a','v','e','g','a','m','e','.','t','x','t','\0'};
	int i, ii, x, player=1, cycle=1, ronda=0, status, correctas, intentos=10, aux[10], acierto, puntos1=0, puntos2=0, hardmode=0, comodines=3;
	int racha=0, bestracha=0, longitud=5, nsfwmode=0, antivicio=0, fechavicio=0, fechavicioactivacion, suficientexhoy=0, aux4save[10],currentconfig[10];
	char play='S', letra, freeword, menu, letras[20], palabra[25], tryword[25], definicion[1024];
	time_t fechahora = time(NULL);	//esto y lo siguiente es una movida para importar el datetime del sistema
  	struct tm fechadia = *localtime(&fechahora);//esto y lo anterior es una movida para importar el datetime del sistema
//--------------------------------------------------------------------------------------------------------------------------------	

//PRECARGA DEL SAVEGAME	
	status=anticheats(savefile);	//Descifra (o cifra) el savegame y devuelve su estado actual
	if (status==0) 
	{
		status=anticheats(savefile);	//Si por algun motivo estaba descifrado y lo hemos cifrado, lo volvemos a descifrar
	}
	if (status==1) //Si esta descifrado, importamos los datos
	{	
		loadgame(savefile, aux);
		currentconfig[1]=puntos1=aux[1];	//acertadas
		currentconfig[2]=puntos2=aux[2];	//falladas
		currentconfig[3]=bestracha=aux[3];	//winstreak
		currentconfig[4]=antivicio=aux[4];	//1 o 0
		currentconfig[5]=fechavicio=aux[5];	//month day
		currentconfig[6]=hardmode;
		currentconfig[7]=1;			//diccionario 1 por defecto
		currentconfig[8]=5;			//longitud palabra por defecto
		suficientexhoy=aux[6];	//a trabajar
		ronda=aux[7];	//numero de ronda para el anticheats
		comodines=aux[8];	//comodines restantes
		anticheats(savefile); 				//volvemos a cifrar
		if (fechavicio-fechadia.tm_mday!=0)
		{	
			comodines=3;
			fechavicioactivacion=fechavicio;
			fechavicio=fechadia.tm_mday;
			suficientexhoy=0;
			ronda=0; 
		}
	}

//BANNER & MAIN MENU		
	banner();
	mainmenu(currentconfig);

	while(cycle==1)
	{	
		printf("\n  > ");
		fflush(stdin);
		scanf("%c", &menu);		
		menu=toupper(menu);  	
		
		switch (menu)			
		{
			case '0': //NEW GAME
				puntos1=0;
				puntos2=0;
				bestracha=0; 
				cycle=0;
				break;			
			case '1': //LOAD GAME
			/*	status=anticheats(savefile);	//Comprueba si el savefile esta cifrado
				if (status==0) 
					{
					status=anticheats(savefile);	//Si NO lo estaba, lo cifra
					}
				if (status==1)
				{	
					/*loadgame(savefile, aux);
					puntos1=aux[1];
					puntos2=aux[2];
					bestracha=aux[3];
					anticheats(savefile);*/ //EN PRINCIPIO ESTO SE OBVIA PQ YA HEMOS PRECARGADO LOS DATOS AL PRINCIPIO
					cycle=0;
				//}
			/*	else 
				{	
					printf("\n  No se encuentra o se ha corrompido el fichero savegame.txt");
					getch();
					break;
				}*/
				break;
			case '2':	//HARDMODE
				minibanner();
				printf("\n ----------------------------------------------------------------------");
				printf("\n  MODO DIFICIL: \n");
				printf("  En este modo tienes 5 intentos en lugar de 10. \n");
				printf("  Cada palabra que aciertes contara como 2. \n");
				printf("  Las palabras falladas seguiran contando como 1. \n");
				printf("  Este modo se desactivara si cierras el juego. \n");
				if (hardmode==1){ printf("  Estado actual: ACTIVADO. \n");	}
				else if (hardmode==0){ printf("  Estado actual: DESACTIVADO. \n");	}
				printf(" ----------------------------------------------------------------------\n");
				x=decidir();
				if(x==1)
				{
					currentconfig[6]=hardmode=1;
					printf("\n  MODO DIFICIL ACTIVADO!\n");
				}
				else if(x==0)
				{	
					currentconfig[6]=hardmode=0;
					printf("\n  Ok, cobarde...\n");
				}
				Sleep(500);
				mainmenu(currentconfig);
				break;			
				
			case '3':	//ANTIVICIO	
				minibanner();
				printf("\n ----------------------------------------------------------------------");
				printf("\n  MODO ANTI-VICIO: \n");
				printf("  Este modo te impide jugar mas de 10 partidas al dia. \n");
				printf("  Una vez activado, no podras desactivarlo hasta el dia siguiente. \n");
				printf("  No se desactivara aunque cierres el juego. \n");
				if (antivicio==1){ printf("  Estado actual: ACTIVADO. \n");	}
				else if (antivicio==0){ printf("  Estado actual: DESACTIVADO. \n");	}
				printf(" ----------------------------------------------------------------------\n");
				x=decidir();
				if(x==1)
				{
					currentconfig[4]=antivicio=1;
					fechavicio=fechadia.tm_mday;
					fechavicioactivacion=fechadia.tm_mday;
					printf("\n  MODO ANTI-VICIO ACTIVADO!\n");
				}
				else if(x==0 )
				{	
					if (fechavicioactivacion-fechadia.tm_mday!=0)
					{
						printf("\n  Ok, no soy yo quien te paga...\n");
						//printf("\n  MODO ANTI-VICIO DESACTIVADO!\n");
						currentconfig[4]=antivicio=0;
					}
					else if (fechavicioactivacion-fechadia.tm_mday==0)
					{
						printf("\n  Oh vaya! No se pudo desactivar el Anti-Vicio");
						printf("\n  Intentalo de nuevo ma%cana ;)\n",164);
					}
					
				}
				Sleep(500);
				mainmenu(currentconfig);
				break;	
				
			case '4':	// SELECCION DICCIONARIO		
				minibanner();
				printf("\n ----------------------------------------------------------------------");
				printf("\n  SELECCION DE DICCIONARIO. \n");
				printf("  Elige el origen de las palabras a adivinar: \n");
				printf("  1 - Diccionario de la Real Academia Espa%cola.\n",164);
				printf("  2 - Verbos y solo verbos en espa%col.  \n",164);
				printf("  3 - Palabras random del Ingles.\n");
				printf(" ----------------------------------------------------------------------");
				printf("\n  > ");
					
				fflush(stdin);
				scanf("%c", &menu);		//almacena un caracter en la variable menu
				//menu=toupper(menu);  	//convierte en mayuscula el caracter almacenado en la variable "menu"
				
				switch (menu)			
				{
				case '1': 
					strcpy(fich,wlrae);
					currentconfig[7]=1;
					break;			
				case '2':	
					strcpy(fich,verbos);
					currentconfig[7]=2;
					break;				
				case '3' :	
					strcpy(fich,ingles);
					currentconfig[7]=3;
					break;
				default:	
				printf("  Opcion no valida\n");
				fflush(stdin);
				}
				mainmenu(currentconfig);
				break;	
				
			case '5':	//WORD LENGH
				printf("\n  SELECCION DE LONGITUD MINIMA. ");
				printf("\n  Por defecto se establece en 5 caracteres. ");
				printf("\n  Elige un numero entre 0 y 12 para cambiarlo. \n");
				printf("\n  > ");
				fflush(stdin);
				fflush(stdin);
				scanf("%i", &longitud);	
				while( longitud > 12 )
				{	
					printf("\n  No te flipes... ");
					printf("\n  Elige un numero entre 0 y 12");
					printf("\n  > ");
					fflush(stdin);
					scanf("%i", &longitud);
				}		
				minibanner();
				printf("\n  Longitud minima establecida en %i caracteres. ", longitud);
				currentconfig[8]=longitud;
				printf("\n"); 
				mainmenu(currentconfig);
				break;	
//MENU HIDDEN OPTIONS					
			case 'X':	//NSFW MODE
				nsfwmode=1;
				minibanner();
				printf("\n ----------------------------------------------------------------------");
				printf("\n  MODO NSFW ACTIVADO. \n");
				printf("  Para desactivar este modo, sal del juego y vuelve a entrar. \n");
				printf(" ----------------------------------------------------------------------\n");
				mainmenu(currentconfig);
				break;	
			case 'C': //DEDICATORIA		  
				printf("\n ----------------------------------------------------------------------------------------------");
				printf("\n  FELIZ CUMPLEA%cOS!!\n",165);
				printf("\n  Este juego ha sido desarrollado exclusivamente para Estefan%ca L%cpez Santaella. ",161,162);
				printf("\n  Aunque prefiere que sus amigos la llamemos simplemente Estefania Con Tilde. \n");
				printf("\n  Creado con mucho cari%co y aprovechando como base un proyecto de fin de curso,",164);
				printf("\n  creo que ha quedado un programita bastante chulo y con muchas funciones, ");
				printf("\n  entre las que por supuesto NO he incluido el uso de tildes, faltar%ca mas...",161);
				printf("\n  Espero que te guste y que no me acabe echando la bronca Javi porque pierdes mucho el tiempo.");
				printf("\n  Un beso y un abrazo muy fuerte.");
				printf("\n                                                   ~ Mario Rueda // Diciembre 2022");
				printf("\n ----------------------------------------------------------------------------------------------\n");
				break;				
		
			default:	
				printf("  Opcion no valida\n");
				fflush(stdin);
		}	
	}

// DEFAULT GAME START && RESET DE VARIABLES<-------------------------------------------------------------------------------
	while(play=='S')
	{	ronda++; intentos=10;  correctas=0;  letra='\0';   letras[0]='\0';  x=0;  
		sacapalabras(fich,palabra,longitud);
		
// CUSTOM GAME OPTIONS
	if(hardmode==1) 
	{	intentos=5;}
	if(nsfwmode==1)
	{	
		strcpy(palabra,NSFW[rand()%250]);
		salvaenes(palabra);
		//printf("salvaeñes: %s",palabra);
		//getch();
	}
	if(antivicio==1 && ronda>10) 
	{	suficientexhoy=1;
		system("cls");
		printf("\n Ya has jugado suficiente por hoy...");
		goto ENDGAME;
	}
	
	fflush(stdin);
	//system("cls");	
		
// GAME ENGINE #1	
	for (i=0 ; i<strlen(palabra) ; i++)	// Por cada letra que tenga la palabra oculta...
		tryword[i]='_';					// ... asigna un '_'
		tryword[strlen(palabra)]='\0'; // Asigna el final de la cadena (fuera de bucle)
	
	while (intentos>0 && correctas<strlen(palabra))	//mientras queden intentos y las letras acertadas sean menos que la strlen
	{	acierto=0;		// vacia la variable de 'letra correcta'
		letras[x]=letra; // le pasa la letra escaneada al vector que almacena todas las letras
		x++;
		
// GAME INTERFACE			
		system("cls");
		printf("\n ----PUNTUACION------------------");
		printf("\n --------------------------------");
		printf("\n  Palabras acertadas: %d",puntos1);
		printf("\n  Mejor racha de aciertos: %d", bestracha);
		printf("\n  Palabras falladas: %d",puntos2);
		printf("\n  Aciertos consecutivos: %d",racha);
		if(comodines<3)
		{	printf("\n  Comodines usados: %i/3",3-comodines); }		
		printf("\n --------------------------------\n");
		printf("\n  La palabra tiene %d letras.",strlen(palabra)); 
		printf("\n  Intentos Restantes: %d \n",intentos);			
		printf("\n  Letras Probadas:");
		for (i=0 ; i<x ; i++)	
			printf("%c ",letras[i]); // pinta todas las letras que se han intentado
		//printf("> ");
		printf("\n  Palabra: %s  \n\n",tryword);  // pinta las letras descubiertas "E_EM_L_"
		monigote(intentos); // pinta el muñeco
		
		//printf("\n  !!!Ronda numero: %i\n  > ",ronda);
		//printf("\n  !!!LA PALABRA ES: '%s'\n  > ",palabra);	//-------###--------> DEBUGGER <-------------###------------------##-------#---
		fflush(stdin);
		scanf("%c", &letra); // escanea la letra
//COMODIN IF LETRA=? ELSE SIGUE PALANTE
		if(letra==63 && comodines>0) // 63=='?'
		{	//ii=0;
			while(freeword!=95) //95=='_'
			{	/*	ii=rand()%strlen(palabra);
					printf("\n ii1 %i",ii);*/
					ii=rand()%strlen(palabra);
					//printf("\n ii2 %i",ii);
					freeword=tryword[ii];
			}
			letra=palabra[ii];
			freeword=69;
			comodines--;					
			//printf("\n  comodin solucion: %c \n",palabra[ii]);
			//getch();		
		}

		letra=tolower(letra);
		
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
		if (racha>bestracha){bestracha=racha;}
		racha=0;
		system("cls");
		//Sleep(500);
		printf("\n  GAME ");
	//	Sleep(500);
		printf("OVER ");
	//	Sleep(500);
		printf("BITCH\n");
	//	Sleep(500);
		printf("  _____     \n");
		printf("  |/  |     \n");	
		printf("  |  /O\\     \n");
		printf("  |  (|)   \n");
		printf("  |  / \\   \n");
		printf("  |_______\n\n  ");	
		printf("La palabra era: '%s'\n",palabra);
		if (currentconfig[7]!=3)
		{ diccionario(rae,palabra,definicion); }
	}
	
	// WIN		
	else 
	{	puntos1++;
		racha++;
		if(hardmode==1) 
		{	puntos1++;}
		if (racha>bestracha){bestracha=racha;}
		system("cls");
		printf(" ------------------------------------------------------------------------------");
		printf("\n  ENHORABUENA!!! Adivinaste: '%s'\n", palabra);
		if (currentconfig[7]!=3)
		{ diccionario(rae,palabra,definicion); }//diccionario(rae,palabra,definicion);
		
	}
	
	ENDGAME:// ENDGAME		
	
	printf("\n ------------------------------------------------------------------------------"); 
	printf("\n\n  Y ahora que...?:\n\n");  
	printf("  X - Guardar y salir.\n");
	if(suficientexhoy!=1) 
	{
		printf("  S - Guardar y seguir jugando \n");
		printf("\n  Pulsa Enter para seguir jugando\n  > ");
	}
	
	fflush(stdin);	
	fflush(stdin);
	scanf("%c", &menu);		//almacena un caracter en la variable menu
	menu=toupper(menu);  	//convierte en mayuscula el caracter almacenado en la variable "menu"
	
	switch (menu)			// crea un bucle, segun el caracter almacenado entrara por un case u otro
	{
	//case 'x':			
	case 'X': 	//save&exit
		aux2save(aux4save, puntos1, puntos2, bestracha, antivicio, fechavicio,suficientexhoy,ronda,comodines);
		savegame(savefile, aux4save);
		anticheats(savefile);
		exit(0);			

	case 'S':	//save&play
		aux2save(aux4save, puntos1, puntos2, bestracha, antivicio, fechavicio,suficientexhoy,ronda,comodines);
		savegame(savefile, aux4save);
		anticheats(savefile);
		printf("\n\n  Recuerda que no es necesario guardar la partida en cada turno\n\n");
		getch();
		break;
		
	default:	// PLAY AGAIN
		break;
	}	  
}
}
//---- FUNCIONES ----//--------------//-----------------------//-----------------------//-----------------------//-----------------------
//---- FUNCIONES ----//--------------//-----------------------//-----------------------//-----------------------//-----------------------
//---- FUNCIONES ----//--------------//-----------------------//-----------------------//-----------------------//-----------------------
//---- FUNCIONES ----//--------------//-----------------------//-----------------------//-----------------------//-----------------------
//---- FUNCIONES ----//--------------//-----------------------//-----------------------//-----------------------//-----------------------
int mainmenu(int currentconfig[])
{
	/*	currentconfig[1]=puntos1=aux[1];	//acertadas
		currentconfig[2]=puntos2=aux[2];	//falladas
		currentconfig[3]=bestracha=aux[3];	//winstreak
		currentconfig[4]=antivicio=aux[4];	//1 o 0
		currentconfig[5]=fechavicio=aux[5];	//month day
		currentconfig[6]=hardmode=aux[6]
		currentconfig[7]	diccionario */
	char aux4status[12];
	int aux;
	
	//minibanner();
	printf("  \n");  
	printf("  0 - Nueva partida. \n");
	printf("\n  1 - Continuar. \n");
	printf("       >Aciertos: %i  -  Fallos: %i  -  Mejor racha: %i \n",currentconfig[1],currentconfig[2],currentconfig[3]);
	//printf("       > \n");
	printf("\n  2 - Modo Dificil. \n");
	aux=currentconfig[6];
	checkstatus(aux,aux4status);
	printf("       >Estado: %s.  \n", aux4status);
	printf("\n  3 - Modo Anti-Vicio. \n");
	aux=currentconfig[4];
	checkstatus(aux,aux4status);
	printf("       >Estado: %s.  \n", aux4status );
	printf("\n  4 - Seleccionar Diccionario. \n");
	aux=currentconfig[7];
	checkWL(aux,aux4status);
	printf("       >Actual: %s \n", aux4status);
	printf("\n  5 - Establecer longitud minima de la palabra. \n");
	printf("       >Actual: %i  \n",currentconfig[8]);
  //printf("  C - Feliz Cumpleaños  \n",longitud);
  //printf("  X - NSFWmode \n");	
  
  
}
//-----------------------
int checkstatus(int input, char output[])
{
	char onn[]={'A','c','t','i','v','a','d','o','\0'};
	char off[]={'D','e','s','a','c','t','i','v','a','d','o'};
	char err[]={'I','n','p','u','t',' ','E','r','r','o','r'};
	
	if(input==1)
	{	strcpy(output,onn);	}
	else if(input==0)
	{	strcpy(output,off); }	
	else
	{	strcpy(output,err); }
		
}
//-----------------------
int checkWL(int input, char output[])
{
	char rae[]={'R','A','E',' ','C','o','m','p','l','e','t','o'};
	char verbos[]={'S','o','l','o',' ','v','e','r','b','o','s'};
	char ingles[]={'I','n','g','l','e','s','\0'};
	char err[]={'I','n','p','u','t',' ','E','r','r','o','r'};
	
	if(input==1)
	{	strcpy(output,rae);	}
	else if(input==2)
	{	strcpy(output,verbos); }
	else if(input==3)
	{	strcpy(output,ingles); }	
	else
	{	strcpy(output,err); }
		
}
//-----------------------
long sacapalabras (char fichero[], char palabra[], int longitud)
{
	FILE *texto;	
	long num_pal=0;	
    int i, ii=0, aux, x=0, multiplier;
    char ok='n';
	srand(time(NULL));

    texto=fopen (fichero, "r");	

	while ((fscanf(texto,"%s",palabra))!=EOF)
	num_pal++;	// me da el numero de palabras del fichero, esta dentro del while
	
	rewind(texto);	
	
	multiplier=num_pal/32767; // 32767 es el num maximo generado por el random
	aux=multiplier*rand();
	aux=multiplier*rand();	// si no esta dos veces no funciona, no se randomiza
	//printf("RANDOM:%i",aux);
	//getch();
	//aux=3*rand();	
	//aux=3*rand();	// si no esta dos veces no funciona, no se randomiza
	
	while(ok!='s')
	{	//aux=rand();
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
		else if(strlen(palabra)>=longitud)
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
//-----------------------
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
							//printf("\n\n  ##########");
							//printf("\n  RESULTADO");
							//printf("\n  R-Palabra: %s",palabra);
							printf("\n  Definicion: %s",definicion);
							//printf("  ##########");
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
	{	//printf("\n  lines: %i ",lines);
		//printf("\n  aux: %i ",aux);
		//printf("\n  Lamentablemente, la palabra '%s' no ha sido encontrada en el diccionario integrado...",palabra);
		printf("\n  Lamentablemente, no ha sido encontrada en el diccionario integrado...",palabra);
		printf("\n  Pero seguro que Google si sabe su significado!\n");
	}
	//getch();
    fclose (texto);
}
//-----------------------
int decidir()
{	
	char answer;
	
	//printf ("\n  Activar este modo?");
		
	printf ("\n\n  Que prefieres? \n");
	printf ("\n  A - Activar ");
	printf ("\n  D - Desactivar ");
	printf ("\n    - Mantenerlo como estaba.\n  > ");
	fflush(stdin);
	scanf ("%c", &answer);
 	answer=toupper(answer);
	
	if (answer == 'A') 
	{	return 1; }
	else if (answer == 'D') 
	{	return 0; }
	else  
	{	return 9; }
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
	
	if(ciphered==1)	{return 1;}  //FICHERO DESCIFRADO ");	} 
	if(ciphered==0)	{return 0;}  // FICHERO CIFRADO "); }
	//Sleep(1000);*/
	//return 0;
}
//-----------------------
int salvaenes(char palabra[])
{	// Las ñ que vienen de dentro del codigo ocupan un solo caracter y no 2 como las que vienen desde el txt
	int i=0;//,x=0;
	
	for (i=0;i<=strlen(palabra);i++)//,x++)
	{		//printf("III: %i\n",i);
			//printf("XXX: %i\n",x);
			//printf("palabradei: %i\n",palabra[i]);
			//getch();
				if(palabra[i]==-15)
				{ 
				//i++;
				palabra[i]=164; 
				}
				palabra[i]=tolower(palabra[i]);
				//palabra[x]=tolower(palabra[i]);
				
	}			//printf("letra: %i\n",palabra[x]);
	//getch();
}	
//-----------------------
long loadgame(char savefile[],int aux[]) // ESTO SE PUEDE HACER CON UN while/FOR EN LUGAR DE ELSE IF
{
	FILE *original;
    int i=0;
    char palabra[10]; 
		
	original=fopen(savefile, "r"); 
	
	while((fscanf(original,"%s",palabra))!=EOF)
	{	
		aux[i]=atoi(palabra);
		i++;
	}
	 /*	if (i==1) 	
		{
			aux[i]=atoi(palabra);	// WINS
		}
		else if (i==2) 	
		{
			aux[i]=atoi(palabra);	// LOSES
		}
		else if (i==3) 	
		{
			aux[i]=atoi(palabra);	// winstreak
		}
//		else if (i==X) AQUI AÑADIMOS EL RESTO DE LINEAS A CARGAR DESDE EL SAVEGAME
		i=i+1;
		
}*/
	
	fclose (original); 
	return (0);
}

//-----------------------
int aux2save(int aux[], int win, int lose, int bestracha, int antivicio, int dia, int enought, int ronda,int comodines)
{
	aux[0]='#';
	aux[1]=win;
	aux[2]=lose;
	aux[3]=bestracha;
	aux[4]=antivicio;
	aux[5]=dia;
	aux[6]=enought;
	aux[7]=ronda;
	aux[8]=comodines;
	
}
//-----------------------
long savegame(char savefile[], int aux[])
{
	FILE *original;
    int i;
    char cabecera='#', nl=13; 
		
	original=fopen(savefile, "w"); 
	for(i=0;i<5;i++)				//#####
	{	fputc(cabecera, original);}
	fputc(nl, original);
	fprintf(original,"%d",aux[1]);	//WIN
	fputc(nl, original);
	fprintf(original,"%d",aux[2]); 	//LOSE
	fputc(nl, original);
	fprintf(original,"%d",aux[3]);	//STREAK
	fputc(nl, original);
	fprintf(original,"%d",aux[4]);	//ANTIVICIO
	fputc(nl, original);
	fprintf(original,"%d",aux[5]);	//fechavicio
	fputc(nl, original);
	fprintf(original,"%d",aux[6]);	//a trabajar
	fputc(nl, original);	
	fprintf(original,"%d",aux[7]);	//num ronda para antivicio
	fputc(nl, original);
	fprintf(original,"%d",aux[8]);	//comodines
	fputc(nl, original);
	for(i=0;i<5;i++)				//#####
	{	fputc(cabecera, original);}
	
	fclose (original); 
	return (0);
}
//-----------------------
int banner()
{		//printf(" \n");
		printf("                                                                    ________ \n");
		printf("  ##   ## ####### ###	 ## ######## ###     ### ####### ###	##  | /    |	   \n");
		printf("  ##   ## ##   ## ####	 ## ##	  ## ####   #### ##   ## ####	##  |/    /O\\    	\n");	
		printf("  ####### ####### ## ##	 ## ##       ##	## ## ## ####### ## ##	##  |     (|)   	\n");
		printf("  ####### ####### ##  ## ## ##  #### ##	 ###  ## ####### ##  ## ##  |     / \\  	\n");
		printf("  ##   ## ##   ## ##   #### ##    ## ##	  #   ## ##   ## ##   ####  |        	\n");
		printf("  ##   ## ##   ## ##	### ######## ##       ## ##   ## ##    ###  |_________       \n");	
		printf("################################################################################ \n");
		printf("                                               v3.12.95  Estefi's Bday Update\n\n");
		//getch(); 			
}		
//-----------------------
int minibanner()
{	system("cls");
	//printf("\n");
	printf("\n  -=|HANGMAN EXPRESS|=-                         v3.12.95  Estefi's Bday Update\n\n");
}
//-----------------------
int monigote(int Intentos)
{
if(Intentos==10)	
{
printf("            \n");
printf("            \n");
printf("            \n");
printf("            \n");
printf("            \n");
printf("          \n\n  > ");
}
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
printf("  _____       \n");
printf("  |/        \n");	
printf("  |         \n");
printf("  |         \n");
printf("  |         \n");
printf("  |_______\n\n  > ");
}
else if(Intentos==3)	
{
printf("  _____       \n");
printf("  |/  |     \n");	
printf("  |         \n");
printf("  |         \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");	
}
else if(Intentos==2)	
{
printf("  _____       \n");
printf("  |/  |     \n");	
printf("  |  /O\\   \n");
printf("  |         \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");	
}
else if(Intentos==1)	
{
printf("  _____       \n");
printf("  |/  |     \n");	
printf("  |  /O\\   \n");
printf("  |  (|)    \n");
printf("  |  	    \n");
printf("  |_______\n\n  > ");
}}
	
