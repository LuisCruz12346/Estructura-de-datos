#include<iostream>
#include<vector>

#define esNumero(a) ((a > 47) && (a < 58))    

using namespace std;

void ordena(vector<int>& arreglo_entrada, int indiceActual);
void ladoMasGrande(vector<int>& arreglo_entrada);
int tamanoArreglo;


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
	
	tamanoArreglo = arreglo_entrada.size() - 1;
	
	
	ladoMasGrande(arreglo_entrada);
	
	imprimirVector(arreglo_entrada);
	
	return 0;
}

void ladoMasGrande(vector<int>& arreglo_entrada){
	ordena(arreglo_entrada , 0);
	int swap;
	int indice;
	
	while(tamanoArreglo){
		
		swap = 	arreglo_entrada[tamanoArreglo];
		arreglo_entrada[tamanoArreglo] = arreglo_entrada[0];
		arreglo_entrada[0] = swap;
		tamanoArreglo--;
	
		indice = 0; 
		if((tamanoArreglo > 0) && (arreglo_entrada[1] > arreglo_entrada[indice]) )
			indice = 1;
		if((tamanoArreglo > 1) &&(arreglo_entrada[2] > arreglo_entrada[indice]) )
			indice = 2;
		
		swap = 	arreglo_entrada[0];
		arreglo_entrada[0] = arreglo_entrada[indice];
		arreglo_entrada[indice] = swap;
		
		ordena(arreglo_entrada , indice);
	}
}


void ordena(vector<int>& arreglo_entrada, int indiceActual){
	if(((indiceActual << 1) + 1) > tamanoArreglo) // Si no tiene hijos es una hoja
		return;
	
	// Manda los demas hijos
	ordena(arreglo_entrada , ((indiceActual << 1) + 1));
	ordena(arreglo_entrada , ((indiceActual << 1) + 2) );
	
	// Validamos si algun valor tiene un valor mayor
	int swap = indiceActual;
	if(arreglo_entrada[((indiceActual << 1) + 1)] >  arreglo_entrada[swap])
		swap = ((indiceActual << 1) + 1);
	if( (((indiceActual << 1) + 2) <= tamanoArreglo) && (arreglo_entrada[((indiceActual << 1) + 2)] >  arreglo_entrada[swap]))
		swap = ((indiceActual << 1) + 2);
	// Hacemos el swap
	int temp= arreglo_entrada[indiceActual];
	arreglo_entrada[indiceActual] = arreglo_entrada[swap];
	arreglo_entrada[swap] = temp;
	
}
