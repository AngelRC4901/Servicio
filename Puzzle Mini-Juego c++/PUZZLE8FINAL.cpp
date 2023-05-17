#include <bits/stdc++.h>
#include <vector>
#include "ModoI.h"
#include <functional>

using namespace std;

const int dimension = 3;

class Jugador{
	private:
		string contra;
		int ano,mes,dia;
		string nom;

	public:
		Jugador();
		void Capturar();
        string nombre();

};

Jugador::Jugador(){
	this -> contra = ' ';
	this -> ano = 0;
	this -> mes = 0;
	this -> dia = 0;
	this -> nom = ' ';
}

void Jugador::Capturar(){
    string aux;
    int aux_alpha = 0;
    int aux_digit = 0;
    ofstream datos;

    int j = 0;
	cout << "\t\t\t|Nombre de Jugador|" << endl;
    cout << "Nombre: ";
        cin >> this->nom;

    datos.open("Datos.txt", ios::app);
    datos << this->nom << endl;

    cout << endl;
    do{
        cout << "\t\t\t| Password | " << endl;
        cout << "Password (Minimo 1 letra y 1 numero): ";
            cin >> aux;
        for(int i = 0; i < aux.size(); i++){

            if(isdigit(aux[i]))
                aux_digit++;
            if(isalpha(aux[i]))
                aux_alpha++;
        }
        if(aux_alpha > 0 && aux_digit > 0)
            j++;
        else{
            cout << "\n\t\t\t|| Password no valida ||" << endl;
            cin.ignore();
            cin.get();
            //system("pause");
            system("clear");
        }
        datos<<aux<<endl;
    } while (j == 0);
    this -> contra = aux;
    cout << "\n\t\t\t| F. Nacimiento |" << endl;

    cout << "Dia: ";
        cin >> this -> dia;
    datos<<this->dia<<"/";

    cout << "\nMes: ";
        cin >> this -> mes;
    datos<<this->mes<<"/";

    cout <<"\nAno: ";
        cin >> this -> ano;
	datos<<this->ano<<"\n"<<endl;

    cout << endl;

    cout << "Digite una tecla para continuar... ";
    datos.close();
}

void llenar(int mat[dimension*dimension]){
	for(int i = 0; i < (dimension*dimension);i++){
		mat[i]=i;
	}
}

void copiar(int numeros[dimension*dimension], int copia[dimension*dimension]){
	for(int i = 0;i < (dimension*dimension);i++){
		copia[i]=numeros[i];
	}
}

void aleatorio(int copia[dimension*dimension]){
    srand(time(0));

	int veces=(rand()%(dimension*dimension))+ (dimension*dimension);
	int pos1,pos2,aux;
	int limite=dimension*dimension;
	for(int i = 0;i < veces;i++){
		pos1=rand()%limite--;
		pos2=rand()%limite++;

		aux=copia[pos1];
		copia[pos1]=copia[pos2];
		copia[pos2]=aux;
	}
}

void imprimir(int mat[dimension][dimension]){
	for(int i = 0;i < dimension;i++){
		for(int j = 0;j < dimension;j++){
			if(mat[i][j]!= 0){
				cout <<	 "[ " << mat[i][j] << " ]";
			}
			else
                cout << "[   ]";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Busca0(int mat[dimension][dimension], int x, int y){
	for(int i = 0;i < dimension;i++){
		for(int j = 0;j < dimension;j++){
			if(mat[i][j]==0){
				x=i;
				y=j;
				break;
			}
		}
	}
}

void llenarM(int mat[dimension][dimension], int aux[dimension]){
	int cont=0;
	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
			mat[i][j]=aux[cont];
			cont++;
		}
	}
}

int getY(int mat[dimension][dimension]){
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			if(mat[i][j] == 0)	return i;
		}
	}
}

int getX(int mat[dimension][dimension]){
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			if(mat[i][j] == 0) return j;
		}
	}
}

void llenar(int img[dimension][dimension]){
    int cont = 1;

    for (int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            img[i][j] = cont;
            cont++;
        }
    }
}

void impM(int img[dimension][dimension]){
    for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){

			if(img[i][j] != 0)
				cout << "[ " << img[i][j] << " ]";
			else
				cout << "[   ]";
		}
		cout << endl;
	}
}

bool comparar(int mat[dimension][dimension], int img [dimension][dimension]){
    int i,j;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension;j++){
            if(mat[i][j] != img[i][j])
                return false;
        }
    }
    return true;
}

void mov(int mat[dimension][dimension], int img[dimension][dimension],int y,int x){

	char c ,e;

	do{

	cout<<"\nDigite el movimiento W A S D: ";

	c = getchar();
	e = getchar();
	c = toupper(c);
		switch(c){
			case 'W':
				if(y >= 1){
					mat [y][x] = mat [y-1][x];
					mat[y-1][x] = 0;
					if(y>1){
						cout<<"Pruebe moviendo arriba"<<endl;
						system("pause");
					}

					if(y==1){
						cout<<"Pruebe moviendo abajo"<<endl;
						system("pause");
					}

					imprimir(mat);
					y--;

				}
				else{
					cout << "FUERA DE LOS LIMITES: \n";


					if(y<1){
						cout<<"Pruebe moviendo abajo"<<endl;

					}

					cin.ignore();
					cin.get();
					//system("pause");
				}
				system("clear");
				imprimir(mat);
				impM(img);

				break;

			case 'S':
				if(y <= 1){
					mat [y][x] = mat [y+1][x];
					mat[y+1][x] = 0;

					if(y<1){
						cout<<"Pruebe moviendo abajo"<<endl;
						system("pause");
					}
					if(y==1){
						cout<<"Pruebe moviendo arriba"<<endl;
						system("pause");
					}

					imprimir(mat);
					y++;
				}
				else{
					cout << "FUERA DE LOS LIMITES: \n";

					if(y>1){
						cout<<"Pruebe moviendo arriba"<<endl;

					}
                    cin.ignore();
					cin.get();
					//system("pause");
				}
				system("clear");
				imprimir(mat);
				impM(img);
				break;

			case 'D':
				if(x <= 1){
					mat [y][x] = mat [y][x+1];
					mat[y][x+1] = 0;

					if(x<1){
						cout<<"Pruebe moviendo a la derecha"<<endl;
						system("pause");
					}
					if(x==1){
						cout<<"pruebe moviendo a la izquierda"<<endl;
						system("pause");
					}

					imprimir(mat);
					x++;
				}
				else{
					cout << "FUERA DE LOS LIMITES: \n";

					if(x>=1){
						cout<<"Pruebe moviendo a la izquierda"<<endl;

					}
                    cin.ignore();
					cin.get();
					//system("pause");
				}
				system("clear");
				imprimir(mat);
				impM(img);
				break;

			case 'A':
				if(x >= 1){
					mat [y][x] = mat [y][x-1];
					mat[y][x-1] = 0;

					if(x>1){
						cout<<"Pruebe moviendo a la izquierda"<<endl;
						system("pause");
					}
					if(x==1){
						cout<<"pruebe moviendo a la derecha"<<endl;
						system("pause");
					}

					imprimir(mat);
					x--;
				}
				else{
					cout << "FUERA DE LOS LIMITES: \n";
					if(x<=1){
						cout<<"Pruebe moviendo a la derecha"<<endl;

					}
                    cin.ignore();
					cin.get();
					//system("pause");
				}
				system("clear");
				imprimir(mat);
				impM(img);
				break;

			case '0':
				break;

			default:
				cout << "ERROR ";
				break;

		}
		cout << " Caracter: \n" << c << endl;

	}while (c != '0' && comparar(mat,img) == false);
}

void instrucciones(){
	cout<<"\t\t\t\t\t\t8-Puzzle\n"<<endl;
	cout<<"\t8-Puzzle es un juego sencillo en el cual deberas llegar a la figura que se muestra en pantalla"<<endl;
	cout<<"\tcon las TECLAS W, A, S, D, con estas podras desplazarte dentro de tu tablero y con el 0 podras"<<endl;
	cout<<"\tsalir del juego en cualquier momento de tu quieras."<<endl;
}


void menu(){
    Jugador j;
    int y,x,n = 2,m = 2;
    char op;
	int num[dimension*dimension];
	int aux[dimension*dimension];
	int mat[dimension][dimension];
    int img[dimension][dimension];
    vector<vector<int> > a(3,vector<int> (3));

	do{
		cout << "\n\t MENU \t\n";
		cout << "\n\t1... Registrarse";
		cout << "\n\t2... Juego Aleatorio";
		cout << "\n\t3... Juego Inteligente";
		cout << "\n\t4... Instrucciones";
		cout << "\n\t5... Salir";
		cout << "\nEscribe la opcion: \n";
			cin >> op;
		switch(op){

			case '1':
                    system("clear");
                    j.Capturar();

					cin.ignore();
					cin.get();
					//system("pause");
					system("clear");
				break;

			case '2':

                    system("clear");

					fflush(stdin);
                    llenar(num);

					fflush(stdin);
                    copiar(num,aux);
                    aleatorio(aux);
                    llenarM(mat,aux);

                    y = getY(mat);
                    x = getX(mat);

                    mat[y][x];

                    imprimir(mat);

                    llenar(img);
                    img[n][m] = 0;
                    impM(img);

                    mov(mat,img,y,x);

					cout << endl;
					cout << "\n\t Completaste el Puzzle FELICIDADES :D " << endl;
					cout << "Presione una tecla para continuar...";
                    cin.ignore();
					cin.get();
					//system("pause");
					system("clear");
				break;

			case '3':

					cout<<"Ingrese la figura que desea acomodar (1 a 9): "<<endl;
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							cout<<"[ "<<i+1<<" ][ "<<j+1<<" ]: ";
							cin>>a[i][j];
						}
					}

					system("clear");

					cout<<"Solucion...\n\n";

					goal[0][0] = 1;
					goal[0][1] = 2;
					goal[0][2] = 3;
					goal[1][0] = 4;
					goal[1][1] = 5;
					goal[1][2] = 6;
					goal[2][0] = 7;
					goal[2][1] = 8;
					goal[2][2] = 0;

					solucion(a,0);
					cout << endl;
                    cin.ignore();
					cin.get();
					//system("pause");
					system("clear");
				break;

			case '4':

					system("clear");
					instrucciones();

					cout << endl;
                    cin.ignore();
					cin.get();
					//system("pause");
					system("clear");

				break;
			case '5':

					cout << "\n Gracias !!!";

				break;
			default:
					cout << "\nSeleccion invalida!!\n";
					system("clear");
				break;
		}
	}while (op != '5');
}

int main(){

    menu();

	return 0;
}
