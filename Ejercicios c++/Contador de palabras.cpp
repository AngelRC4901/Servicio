#include <bits/stdc++.h>

using namespace std;

int main (){

	string cadena = "";
	int cont = 0;

	cout << " Introduzca la cadena: \n";
	getline(cin, cadena);

	for (int i = 0; i < cadena.length(); i++){
		if (cadena[i] == ' '){
			cont++;
		}
	}

	cout << " La cantidad de palabras es: " << cont << endl;


	return 0;
}
