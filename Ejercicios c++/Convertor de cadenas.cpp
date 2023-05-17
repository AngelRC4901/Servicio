#include <bits/stdc++.h>

using namespace std;

void modifica(char cadena[]);


int main(){
	
char cadena[50];

printf(" Introduzca la cadena: \n");
	fflush(stdin);
	gets(cadena);	


modifica(cadena);
	

	return 0;
}

void modifica(char cadena[]){
	
	int Tam1 = strlen(cadena);
	
	for( int i = 0; i < Tam1; i++){
		//verifica si es minuscula y cambia a mayuscula
		if ( islower (cadena[i])){ 		// islower verifica - tolower cambia
			cadena[i] = toupper ( cadena [i]);  	// isupper verifica - toupper cambia
		}
		//verifica si es mayuscula y cambia a miniscula 
		if ( isupper (cadena[i])){
			cadena [i] = tolower ( cadena [i]);
		}
		//verifica si es un diptongo y cambia a un #
		if (isdigit (cadena[i])){
			cadena[i] = '#';
		}
		//verifica si hay un espacio y cambia un _
		if (isspace (cadena[i])){
			cadena[i] = '_';
		}
		switch (cadena[i]){
			case 'a':
			case 'A': cadena [i] = '4';
				break;
			case 'e':
			case 'E': cadena [i] = '3';
				break;
			case 'i':
			case 'I': cadena [i] = '1';
				break;
			case 'o':
			case 'O': cadena [i] = '0';
				break;
			case 'u':
			case 'U': cadena [i] = '6';
				break;
		}
	}
	printf( " Cadena resultante: %s \n", cadena);
}
