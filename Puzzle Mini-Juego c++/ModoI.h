#include <bits/stdc++.h>
#include <functional>
using namespace std;


map<vector<vector<int> > , bool> visited;
map<vector<vector<int> > , vector<vector<int> > > parent;
vector<vector<int> > goal(3,vector<int> (3));

bool visit(vector<vector<int> > a){
	if(visited[a]==true)
		return true;
	else
		return false;
}

int manhattan(vector<vector<int> > a , int moves){  //Usamos el metodo manhattan para obtener la distancia mas optima (esto es una estructura de datos)
	int dist=moves;
	for(int i=0;i<3;i++){

		for(int j=0;j<3;j++){

			if(a[i][j]!=0){

				for(int k=0;k<3;k++){

					for(int l=0;l<3;l++){

						if(a[i][j]==goal[k][l])

							dist+=abs(i-k)+abs(j-l);
					}
				}
			}
		}
	}

	return dist;
}

bool safe(int i,int j){ // Esta funcion se utiliza para estar dentro de los parametros de nuestro tablero

	if(i>=0 && i<=2 && j>=0 && j<=2)
		return true;
	else
		return false;
}

int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};

vector<vector<vector<int> > > neighbours(vector<vector<int> > a){

	pair<int,int> pos;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){

			if(a[i][j]==0){

				pos.first=i;
				pos.second=j;
				break;
			}
		}
	}

	vector<vector<vector<int> > >ans;

	for(int k=0;k<4;k++){

		int cx = pos.first;
		int cy = pos.second;
		vector<vector<int> > n = a;

		if(safe(cx+dx[k],cy+dy[k])){

			swap(n[cx+dx[k]][cy+dy[k]],n[cx][cy]);
			ans.push_back(n);
		}
	}

	return ans;
}

typedef pair<vector<vector<int> > , int> state;

struct cmp{

	bool operator() (state &a, state &b){

		int am = manhattan(a.first,a.second);
		int bm = manhattan(b.first,b.second);
		return am<bm;
	}
};

void print_path(vector<vector<int> > s){ //Aqui va mostrando las soluciones

   if(parent.count(s))
   print_path(parent[s]);

	for(int i=0;i<3;i++){

		for(int j=0;j<3;j++){

			if(s[i][j]!=0){
				cout<<"[ " << s[i][j] <<" ]";
			}else
				cout << "[   ]";
		}
		cout<<endl;
   }

	cout<<endl;
	return;
}

void mostrar(vector<vector<int> > s){ //Aqui mostramos el tablero
	for(int i=0;i<3;i++){

		for(int j=0;j<3;j++){

			if(s[i][j]!=0){
				cout<<"[ " << s[i][j] <<" ]";
			}else
				cout << "[   ]";

		}
		cout<<endl;
   }
   cout << endl << endl;
}

void solucion(vector<vector<int> > a, int moves){ //Aqui realizamos el proceso de llegar a la soloucion final

	priority_queue<state,vector<state>,cmp > Q;
	Q.push(state(a,moves));

	while(!Q.empty()){

		vector<vector<int> > s = Q.top().first;
		Q.pop();

		visited[s]=true;
		//Sleep(500);
        cin.ignore();
        cin.get();
		cout<<endl;

		if(s==goal){
			print_path(s);
			break;
		}
		vector<vector<vector<int> > > ns = neighbours(s);
		vector<vector<vector<int> > >::iterator it;

		for(it=ns.begin();it!=ns.end();it++){

			mostrar(*it);
			cout<<endl;
			vector<vector<int> > temp = *it;

			if(!visit(temp)){

				parent.insert(pair<vector<vector<int> > , vector<vector<int> > >(temp,s));
				Q.push(state(temp,moves+1));
			}
		}

	}
	return;
 }


