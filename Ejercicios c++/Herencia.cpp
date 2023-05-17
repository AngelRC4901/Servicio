#include <bits/stdc++.h>

using namespace std;

class Persona{
		//PROTECTED para que los atributos private puedan ser manipulados por todas las clases hijas 
	private:
		string nom;
		int edad;
	public:
		Persona(string, int);
		void mostrar();
	
};

class Alumno : public Persona{
	private:
		int id;
		float notaF;
	public:
		Alumno(string, int, int, float);
		void mostrarA();
		
};

Persona::Persona(string n, int ed){
	nom = n;
	edad = ed;
}

Alumno::Alumno(string n, int ed, int _id, float nf) : Persona(n, ed){
	
	id = _id;
	notaF = nf; 
}

void Persona::mostrar(){
	
	cout << "\n Nombre: " << nom << endl;
	cout << "\n Edad: " << edad << endl;
}

void Alumno::mostrarA(){
	
	mostrar();
	
	cout << "\n El id es: " << id << endl;
	cout << "\n La nota final es: " << notaF << endl;
}

int main(){
	
	string al;
	char opc;
	int eda, id1;
	float notF;
	
	Alumno alum1(al, eda, id1, notF);
	
	do{
		cout << "\n Digite el nombre del alumno: "<< endl;
			fflush(stdin);
			getline( cin, al);
			
		cout << "\n Digite su edad: " << endl;
			cin >> eda;
		 
		 cout << "\n Digite su ID: " << endl;
		 	cin >> id1;
		
		cout << "\n Digite la nota final: " << endl;
			cin >> notF;
		
		Alumno alum1(al, eda, id1, notF);
		
		alum1.mostrarA();
		
		cout << "\n\n Desea ingresar otro alumno? s/n: " << endl;
			cin >> opc;
		
		system("pause");
		system("cls");
		
	}while(opc == 's' or opc == 'S');
	
	
	return 0;
}
