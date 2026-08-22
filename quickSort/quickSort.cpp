#include<iostream>
#include<vector>
#define esNumero(a) ((a > 47) && (a < 58))    

using namespace std;

void divideArreglo(vector<int>& arreglo_entrada ,int indiceLimiteIzquierdo, int indiceLimiteDerecho); // Le paso los limites
int quickSort(vector<int>& arreglo_entrada ,int indiceLimiteIzquierdo, int indiceLimiteDerecho);

void imprimirVector(const vector<int>& v){
	for (int x : v) 
        	cout << x << " ";
        cout << endl;
}

int convertirANumero(char* argv){
	int resultado = 0, i = 0;
	while(argv[i]){
		if(esNumero(argv[i]))
			resultado = (resultado * 10) + (argv[i] - '0');
		else
			return 0; // Los numeros mal formados se convierten a 0
		i++;
	}
	return resultado;
}


int main(int argc, char* argv[]){
	if (argc < 2){
		cout << "La estructura es: ./Executable Valor1 ValorN" << endl;
		return 0;
	}
	
	vector<int> arreglo_entrada;
	for(int i = 1; i < argc; i++ )
		arreglo_entrada.push_back(convertirANumero(argv[i]));
	
	int tamano = (arreglo_entrada.size()) - 1;
	
	int mitad = quickSort(arreglo_entrada , 0, tamano);
	divideArreglo(arreglo_entrada , 0 , ((mitad - 1) < 0) ? 0 : (mitad - 1)); // Si es menor al limite izquierdo entonces asigna el limite izquierdo
	divideArreglo(arreglo_entrada , ((mitad + 1) > tamano) ? tamano : (mitad + 1) , tamano); // Si es mayor al limite derecho entonces asigna el limite derecho
	
	
	imprimirVector(arreglo_entrada);
		
	return 0;
}

void divideArreglo(vector<int>& arreglo_entrada ,int indiceLimiteIzquierdo, int indiceLimiteDerecho){
	if(indiceLimiteIzquierdo == indiceLimiteDerecho)
		return;
	int mitad = quickSort(arreglo_entrada , indiceLimiteIzquierdo, indiceLimiteDerecho);
	divideArreglo(arreglo_entrada , indiceLimiteIzquierdo , ((mitad - 1) < indiceLimiteIzquierdo) ? indiceLimiteIzquierdo : (mitad - 1)); 
	divideArreglo(arreglo_entrada , ((mitad + 1) > indiceLimiteDerecho) ? indiceLimiteDerecho : (mitad + 1) , indiceLimiteDerecho); 
	
}

// Voy a regresar el indice del pivote al ordenar
int quickSort(vector<int>& arreglo_entrada ,int indiceLimiteIzquierdo, int indiceLimiteDerecho){	
	int pivote = indiceLimiteDerecho; // Un pequeño ajuste es poner el modo aleatorio que seleccione el pivote y lo ponga al ultimo y hacer lo mismo
	int limite = indiceLimiteDerecho + 1;
	int swap;
	int mayor=0;
	
	while(indiceLimiteIzquierdo < limite){
		if(arreglo_entrada[indiceLimiteIzquierdo] > arreglo_entrada[pivote]){
			mayor++;
		}else{
			swap = arreglo_entrada[indiceLimiteIzquierdo - mayor]; 
			arreglo_entrada[indiceLimiteIzquierdo - mayor] = arreglo_entrada[indiceLimiteIzquierdo];
			arreglo_entrada[indiceLimiteIzquierdo] = swap;
		}
		indiceLimiteIzquierdo++;
	}
	return 	((indiceLimiteIzquierdo - 1) - mayor);
}
