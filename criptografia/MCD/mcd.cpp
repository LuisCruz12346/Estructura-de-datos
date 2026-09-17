#include<iostream>
#include<vector>

using namespace std;

#define esNumero(a) ((a > 47) && (a < 58)) 

int convertirANumero(char* argv){
	int resultado = 0, i = 0;
	while(argv[i]){
		if(esNumero(argv[i]))
			resultado = (resultado * 10) + (argv[i] - '0');
		else
			return 1; // Los numeros mal formados se convierten a 1
		i++;
	}
	return resultado;
}

int algoritmoEuclides(vector<int>& arreglo_entrada,int indiceLimiteIzquierdo, int indiceLimiteDerecho){
	if(indiceLimiteIzquierdo == indiceLimiteDerecho)
		return arreglo_entrada[indiceLimiteIzquierdo];
	
	int temp = ((indiceLimiteDerecho + indiceLimiteIzquierdo) >> 1); 
	int a = algoritmoEuclides(arreglo_entrada, indiceLimiteIzquierdo , temp); // Izquierda
	int b = algoritmoEuclides(arreglo_entrada , (temp + 1) , indiceLimiteDerecho ); // Derecha	
	
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
    	}
    	
    	return a;
	
}


int main(int argc, char* argv[]){
	if (argc < 3){
		cout << "La estructura es: ./Executable V1 V2 VN" << endl;
		return 0;
	}
	vector<int> arreglo_entrada;
	for(int i = 1; i < argc; i++ )
		arreglo_entrada.push_back(convertirANumero(argv[i])); 
	
	int tamano = (arreglo_entrada.size()) - 1;
	
	
	int mcd = algoritmoEuclides(arreglo_entrada , 0 ,tamano);
	
	cout << "El mcd es : " << mcd << endl;
	
	return 0;
}
