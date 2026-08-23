#include<iostream>
#include<vector>
#include <string> 
#include <queue>

using namespace std;
class Grafo{
	int numeroPuntos;
	bool isBidireccional;
	
	// Matriz de adyacencia, dentro de la matriz de adyacencia se guarda el costo por su traslado  
	vector<vector<int>> matriz_adyacencia;
	
	// Lista de adyacencia
	vector<vector<int>> lista_adyacencia;
	
	// Manejamos una liga de visitados;
	vector<bool> visitados;
	
	// Manejamos una liga de las distancias
	vector<int> distancias;
	
	// Manejamos el camino de cada uno
	vector<string> recorridos_mas_cortos;
	
	public:
		// Se contempla una matriz de adyacencia de tamaño: n x n
		
		Grafo(int n, bool isBidi) : numeroPuntos(n)
					, lista_adyacencia(n)
					, distancias(n)
					, visitados(n)
					, recorridos_mas_cortos(n)
					, matriz_adyacencia(n, vector<int>(n))
					, isBidireccional(isBidi){};
		
		void asociarPunto(int punto, int extremo, int peso);
		
		void imprimirAsociaciones();
		
		void dijkstra(int vertice_inicio, int vertice_final);
		
};


void Grafo::asociarPunto(int punto, int extremo, int peso){ 
	if ((punto > (numeroPuntos - 1)) || (extremo > (numeroPuntos - 1)))
		return;
	
	// No se aceptan con distancias de 0, por lo mientras, ya que valido de forma rapida
	if(!(matriz_adyacencia[punto][extremo])){
		matriz_adyacencia[punto][extremo] = peso;
		lista_adyacencia[punto].push_back(extremo);
	}	
	
	if(isBidireccional){
		if(!(matriz_adyacencia[extremo][punto])){
			matriz_adyacencia[extremo][punto] = peso;
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

void Grafo::dijkstra(int vertice_inicio, int vertice_final){
	queue<int> cola;
	int peso_resultante_tras_paso;
	
	visitados.assign(numeroPuntos, false); 
	distancias.assign(numeroPuntos, 10000);
	recorridos_mas_cortos.assign(numeroPuntos, "");
	
	distancias[vertice_inicio] = 0;
	recorridos_mas_cortos[vertice_inicio] = to_string(vertice_inicio) +  " ";
	
	visitados[vertice_inicio] = true;
	cola.push(vertice_inicio);
	while(!cola.empty()){
		for (int vecino : lista_adyacencia[cola.front()]){
			peso_resultante_tras_paso = (distancias[cola.front()] + matriz_adyacencia[cola.front()][vecino]);
			if(peso_resultante_tras_paso < distancias[vecino]){
				distancias[vecino] = peso_resultante_tras_paso;
				recorridos_mas_cortos[vecino] = recorridos_mas_cortos[cola.front()] + to_string(vecino) + " "; 	
			}
			if(!(visitados[vecino])) {
				visitados[vecino] = true;
				cola.push(vecino);
			}	
		}	
		cola.pop();
	}
	
	cout << "El recorrido segun dijkstra: " << recorridos_mas_cortos[vertice_final] << endl;
	
}

int main(){
	// Ejemplo 1: De la carpeta entradas
	// Ejemplo para el grafo propuesto dentro de la pagina
	/*
	Grafo g(7, true);
	g.asociarPunto(0, 2, 3);
	g.asociarPunto(0, 3, 4);
	g.asociarPunto(0, 4, 4);
	g.asociarPunto(1, 2, 2);
	g.asociarPunto(1, 5, 2);
	g.asociarPunto(2, 4, 4);
	g.asociarPunto(2, 5, 5);
	g.asociarPunto(2, 6, 5);
	g.asociarPunto(3, 4, 2);
	g.asociarPunto(4, 6, 5);
	g.asociarPunto(5, 6, 5);
	
	g.dijkstra(3, 5);
	
	*/ 
	// Ejemplo 2: De la carpeta entradas
	// Ejemplo para el ultimo ejemplo dentro de la pagina	 
	Grafo f(7, true);
	f.asociarPunto(0, 1, 2);
	f.asociarPunto(0, 2, 6);
	f.asociarPunto(1, 3, 5);
	f.asociarPunto(2, 3, 8);
	f.asociarPunto(3, 4, 10);
	f.asociarPunto(3, 5, 15);
	f.asociarPunto(4, 5, 6);
	f.asociarPunto(4, 6, 2);
	f.asociarPunto(5, 6, 6);
	
	f.dijkstra(0, 6);
	
	return 0;
}
