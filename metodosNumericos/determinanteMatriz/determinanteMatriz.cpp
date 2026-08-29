/*
	Basado en el algoritmo  Barreis pero con optimizaciones.  
*/

#include<iostream>
#include<vector>

#define esNumero(a) ((a > 47) && (a < 58)) 

using namespace std;

int determinante(vector<int>& v, int n);
void intercambiarFila(vector<int>& v, int fila, int tamanoMatriz);

void imprimirMatriz(const vector<int>& v, int n){
	int i = 1;
	for (int x : v){
			cout << x << "\t";
		if(!(i % n))
			cout << endl;
		i++;
	} 	
}

int convertirANumero(char* argv){
	int resultado = 0, i = 0;
	int negativo = 1;
	if (argv[i] == '-'){
		negativo = -1;
		i++;
	}
	while(argv[i]){
		if(esNumero(argv[i]))
			resultado = (resultado * 10) + (argv[i] - '0');
		else
			return 0; // Los numeros mal formados se convierten a 0
		i++;
	}
	return negativo * resultado;
}


int main(int argc, char* argv[]){
	if (argc < 3){
		cout << "La estructura es: ./Executable N Valor1 ValorN" << endl;
		return -1;
	}
	int n = convertirANumero(argv[1]);
	if( argc < (n * n + 2)){
		cout << "Ingresar todos los elementos de la matriz" << endl;
		return -1;
	}
	
	if (n == 1){
		cout << "El determinante es: " << argv[2] << endl;
		return 0;
	}
	
	vector<int> matriz;
	
	for(int i = 2; i < argc; i++ )
		matriz.push_back(convertirANumero(argv[i]));
	
	//imprimirMatriz(matriz, n);
	
	// Verificamos
	
	cout <<  "El determinante es: " << determinante(matriz, n) << endl;
		
	return 0;
}

int determinante(vector<int>& v, int n){
	int tamanoMatriz = n;
	int ubicacion_pivote = 0;
	int ubicacion_esquina_pivote = 1;
	int pivote = 1;
	int a_rc, a_ij , a_ic, a_rj; 
	while(n>2){
		// Vamos achicando la matriz. 
		a_rc = v[ubicacion_pivote * tamanoMatriz  + ubicacion_pivote];
		if(!a_rc){ // Se busca la primera fila con el pivote diferente de 0
			int fila = ubicacion_pivote;
			while( fila < tamanoMatriz && !(v[fila * tamanoMatriz  + ubicacion_pivote]) )
				fila++; 
			if( fila ==  tamanoMatriz)
				return 0;
			intercambiarFila(v, fila - 1, tamanoMatriz );
			a_rc = v[ubicacion_pivote * tamanoMatriz  + ubicacion_pivote];
		}
		for(int i = ubicacion_esquina_pivote; i < tamanoMatriz; i++){
			a_ic = v[i * tamanoMatriz + ubicacion_pivote];
			for(int j = ubicacion_esquina_pivote; j < tamanoMatriz ; j++){
					a_ij = v[i * tamanoMatriz + j];		
					a_rj = v[ubicacion_pivote * tamanoMatriz + j];
					v[i * tamanoMatriz + j] = ((a_rc * a_ij - a_ic * a_rj) / pivote);
			}
		}
		pivote = a_rc;
		ubicacion_pivote++;
		ubicacion_esquina_pivote++;
		n--;
	}
	// a b
	// c d
	int a = v[ubicacion_pivote* tamanoMatriz + ubicacion_pivote]
		, d = v[(ubicacion_pivote + 1) * tamanoMatriz + (ubicacion_pivote +1)]
		, c = v[(ubicacion_pivote + 1) * tamanoMatriz + ubicacion_pivote]
		, b = v[ubicacion_pivote * tamanoMatriz + (ubicacion_pivote + 1)];
	
	return ((a*d - b*c) / pivote);
}

void intercambiarFila(vector<int>& v, int fila, int tamanoMatriz){
	int temp;
	for(int i = 0; i < tamanoMatriz; i++ ){
		temp = -(v [fila * tamanoMatriz + i]);
		v[fila * tamanoMatriz + i] = (v[(fila + 1) * tamanoMatriz + i]);
		v[(fila + 1) * tamanoMatriz + i] = temp;
	}
}
