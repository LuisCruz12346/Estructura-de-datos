#include<iostream>
#include<vector>

using namespace std;

#define esNumero(a) ((a > 47) && (a < 58))    

void divideArreglo(vector<int>& arreglo_entrada , vector<int>& arreglo_salida ,int indiceLimiteIzquierdo, int indiceLimiteDerecho); // Le paso los limites
void combinaArreglo(vector<int>& arreglo_entrada , vector<int>& arreglo_salida ,int indiceLimiteIzquierdo, int indiceLimiteDerecho); // Le paso los limites


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
	
	imprimirVector(arreglo_entrada);
	
	vector<int> arreglo_salida = arreglo_entrada;
	
	int tamano = (arreglo_entrada.size()) - 1;
	int indice_mitad = ((tamano) >> 1);
	divideArreglo(arreglo_entrada , arreglo_salida, 0 , indice_mitad ); // Comenzar con la izquierda
	divideArreglo(arreglo_entrada , arreglo_salida, indice_mitad + 1 , tamano);  // Comenzar con la derecha 
	combinaArreglo(arreglo_entrada, arreglo_salida, 0, tamano);
	
	//imprimirVector(arreglo_entrada);
	imprimirVector(arreglo_salida);
	
	return 0;
}


void divideArreglo(vector<int>& arreglo_entrada , vector<int>& arreglo_salida ,int indiceLimiteIzquierdo, int indiceLimiteDerecho){
	if(indiceLimiteIzquierdo == indiceLimiteDerecho)
		return;
	int temp = ((indiceLimiteDerecho + indiceLimiteIzquierdo) >> 1); 
	divideArreglo(arreglo_salida, arreglo_entrada, indiceLimiteIzquierdo , temp); // Izquierda
	divideArreglo(arreglo_salida, arreglo_entrada , (temp + 1) , indiceLimiteDerecho ); // Derecha
	
	combinaArreglo(arreglo_salida, arreglo_entrada, indiceLimiteIzquierdo, indiceLimiteDerecho); //
	
	return;
}

void combinaArreglo(vector<int>& arreglo_entrada , vector<int>& arreglo_salida ,int indiceLimiteIzquierdo, int indiceLimiteDerecho){
	int j = ((indiceLimiteDerecho + indiceLimiteIzquierdo) >> 1) + 1;
	
	int i = indiceLimiteIzquierdo;
	int mitadFija =  j;
	 indiceLimiteDerecho++;
	 
	while( (indiceLimiteIzquierdo <  mitadFija ) && (j <  indiceLimiteDerecho ) ){
		if(arreglo_entrada[indiceLimiteIzquierdo] > arreglo_entrada[j]) arreglo_salida[i]  = arreglo_entrada[j++];
		else arreglo_salida[i]  = arreglo_entrada[indiceLimiteIzquierdo++];
		i++;
	}
	
	while(j < indiceLimiteDerecho){
		arreglo_salida[i]  = arreglo_entrada[j];
		j++;
		i++;
	}
		
	while(indiceLimiteIzquierdo < mitadFija){
			arreglo_salida[i]  = arreglo_entrada[indiceLimiteIzquierdo];
			indiceLimiteIzquierdo++;
			i++;
		}
	
}
