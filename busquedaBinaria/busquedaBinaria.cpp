#include<iostream>
#include<vector>
#include <string>
#include <algorithm> 

using namespace std;

int busqueda;

void imprimirVector(const vector<int>& v){
	for (int x : v) 
        	cout << x << " ";
        cout << endl;
}

int busquedaBinaria(const vector<int>& arreglo_entrada,int indiceLimiteIzquierdo, int indiceLimiteDerecho, int busqueda){
	int mitad;
	while(indiceLimiteIzquierdo != indiceLimiteDerecho){
		mitad = (indiceLimiteIzquierdo + indiceLimiteDerecho) >> 1;
		if(arreglo_entrada[mitad] == busqueda)
			return 1;
		if(busqueda > arreglo_entrada[mitad])
			indiceLimiteIzquierdo = mitad + 1;
		else 
			indiceLimiteDerecho = mitad;
	}
	return (arreglo_entrada[indiceLimiteIzquierdo] == busqueda) ? 1 : 0;
}


int main(int argc, char* argv[]){
	if (argc < 3){
		cout << "La estructura es: ./Executable Valor1 ValorN ValorABuscar" << endl;
		return 0;
	}
	int tam = argc - 1;
	vector<int> arreglo_entrada;
	for(int i = 1; i < tam; i++ )
		arreglo_entrada.push_back((stoi(argv[i])));
	
	sort(arreglo_entrada.begin(), arreglo_entrada.end());
	
		
	imprimirVector(arreglo_entrada);	
	
	cout << ((busquedaBinaria(arreglo_entrada, 0, argc - 3, stoi(argv[tam])) ? "Si" : "NO")) << endl;
	
	return 0;
}
