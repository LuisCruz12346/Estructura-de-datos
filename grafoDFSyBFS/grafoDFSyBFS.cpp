#include<iostream>
#include<vector> 
#include <queue>

using namespace std;

class Grafo{
	int numeroPuntos;
	bool isBidireccional;
	
	// Manejo de punteros por partes del compilador, no utilizando new.
	
	// Matriz de adyacencia 
	vector<vector<int>> matriz_adyacencia;
	// Lista de adyacencia
	vector<vector<int>> lista_adyacencia;
	
	// Manejamos una liga de visitados;
	vector<bool> visitados;
	
	public:
		// Utilizando una lista de inicializacion para evitar la doble reasignacion
		// Se contempla una matriz de adyacencia de tamaño: n x n
		
		Grafo(int n, bool isBidi) : numeroPuntos(n), lista_adyacencia(n), visitados(n), matriz_adyacencia(n, vector<int>(n)), isBidireccional(isBidi){};
		
		void asociarPunto(int punto, int extremo);
		
		void imprimirAsociaciones();
		
		void busqueda(int vertice_inicio);
		
		void DFS(int vertice_inicio);
		
		void BFS(int vertice_inicio);
		
			
};


void Grafo::asociarPunto(int punto, int extremo){ 
	if ((punto > (numeroPuntos - 1)) || (extremo > (numeroPuntos - 1)))
		return;
	
	
	if(!(matriz_adyacencia[punto][extremo])){
		matriz_adyacencia[punto][extremo] = 1;
		lista_adyacencia[punto].push_back(extremo);
	}	
	
	if(isBidireccional){
		if(!(matriz_adyacencia[extremo][punto])){
			matriz_adyacencia[extremo][punto] = 1;
			lista_adyacencia[extremo].push_back(punto);
		}
	}
}

void Grafo::imprimirAsociaciones(){
	for(int i = 0; i < numeroPuntos; i++){
		cout << i << ": "; 
		for (int vecino : lista_adyacencia[i])
			cout << vecino << " ";
		cout << endl;
	}
}

void Grafo::busqueda(int vertice_inicio){
			visitados.assign(numeroPuntos, false); 
			cout << "Busqueda por profundidad: ";
			DFS(vertice_inicio);
			cout <<  endl;
			visitados.assign(numeroPuntos, false); 
			cout << "Busqueda por Anchura: ";
			BFS(vertice_inicio);
			cout <<  endl;
		}
		
void Grafo::DFS(int vertice_inicio){
	cout << vertice_inicio << " ";
	visitados[vertice_inicio] = true;
	for (int vecino : lista_adyacencia[vertice_inicio])
		if(!(visitados[vecino])) // Caso base cuando el punto ya fue visitado
			DFS(vecino);
}

void Grafo::BFS(int vertice_inicio){
	queue<int> cola;
	cout << vertice_inicio << " ";
	visitados[vertice_inicio] = true;
	cola.push(vertice_inicio);
	while(!cola.empty()){
		for (int vecino : lista_adyacencia[cola.front()]){
			if(!(visitados[vecino])) {
				cout << vecino << " ";
				visitados[vecino] = true;
				cola.push(vecino);	
			}
		}	
		cola.pop();
	}
}

int main(){
	// El orden de chequeo se realiza en funcion del ingreso 
	
	/*
	Grafo g(4, false);
	g.asociarPunto(0, 1); 
	g.asociarPunto(0, 2); 
	g.asociarPunto(1, 2); 
	g.asociarPunto(2, 0); 
	g.asociarPunto(2, 3); 
	g.asociarPunto(3, 3);
	*/
	//g.imprimirAsociaciones();
	
	
	
	Grafo g(12, false);
	g.asociarPunto(0, 1); 
	g.asociarPunto(0, 6); 
	g.asociarPunto(0, 7); 
	g.asociarPunto(1, 2); 
	g.asociarPunto(1, 5); 
	g.asociarPunto(2, 3);
	g.asociarPunto(2, 4); 
	g.asociarPunto(7, 8); 
	g.asociarPunto(7, 11); 
	g.asociarPunto(8, 9); 
	g.asociarPunto(8, 10); 
	
	//g.imprimirAsociaciones();
	
	
	g.busqueda(0);
	
	return 0;
}
