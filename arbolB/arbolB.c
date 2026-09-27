#include <stdio.h>
#include <stdlib.h>
#include "arbolBplus.h"

ArbolB_plus* creacionArbol(int orden){
	ArbolB_plus *arbol = (ArbolB_plus *)malloc(sizeof(ArbolB_plus));
	arbol -> raiz =  NULL;
	arbol -> orden = orden;
	return arbol;
}

Nodo* creacionNodo(int orden){
	Nodo *nodo_one = (Nodo *)malloc(sizeof(Nodo));
	nodo_one->Pi = (Nodo **)calloc(orden + 1, sizeof(Nodo *));
	nodo_one->Ki = (int *)calloc(orden, sizeof(int)); 
	nodo_one->k = 0;
	nodo_one->orden= orden;
	return nodo_one; 
}

void insertarValorArbol(int valor, ArbolB_plus* arbol){
	if(arbol -> raiz != NULL){
		insertarValorAArbol(valor,arbol -> raiz);
	}else{
		Nodo *nodo_one = creacionNodo(arbol -> orden);
		nodo_one->Ki[0] = valor;
		nodo_one->k = 1;
	}
}
// Que regrese el valor, si es null, no hay nada que ingresar
int insertarValorAArbol(int valor, Nodo* nodo){
    if(nodo->Pi[0] == NULL) {
    	return insertarValorNodo(nodo, valor);
    }
    
    int i = busquedaBinaria(valor, nodo->k - 1, nodo->Ki);
    // Si en el caso base de regresa un numero diferente de 0, significa que afectara a su padre
    int r = insertarValorAArbol(valor, nodo->Pi[i]); 
//Dependiendo si en su hijo hubo un cambio entonces el padre lo recibira y respondera con diferente de 0 si hubo un split, ahora en su nodo
    if(r) {  
    	return insertarValorNodo(nodo, valor);
    }
    return 0;
}


int busquedaBinaria(int valor, int limiteDerecho, int *valores){
	int limiteIzquierdo = 0;
	int mitad;
	while(limiteIzquierdo != limiteDerecho){
		mitad = (limiteIzquierdo + limiteDerecho) >> 1;
		if(valores[mitad] == valor){
			return mitad; // Si es igual se regresa el nodo anterior
		}
		if(valor > valores[mitad]){
				limiteIzquierdo = mitad + 1;
			}
		else 
			limiteDerecho = mitad;
	}

	return valor>valores[limiteIzquierdo] ? limiteIzquierdo + 1 : limiteIzquierdo;
}

void borrarNodo(Nodo* nodo){
    if(nodo == NULL)
        return;

    if(nodo->Pi[0] != NULL){
        for(int i = 0; i <= nodo->k; i++){
            borrarNodo(nodo->Pi[i]);
        }
    }

    free(nodo->Pi);
    free(nodo->Ki);
    free(nodo);
}

void borrarArbol(ArbolB_plus* arbolB_plus){
	borrarNodo(arbolB_plus -> raiz);
	free(arbolB_plus);
}


int insertarValorNodo(Nodo *nodo, int valor){
	int i = nodo->k;
	for(; i>0 && (nodo->Ki[i - 1]>valor); i--){
		nodo->Ki[i] = nodo->Ki[i - 1];
		nodo->Pi[i + 1] = nodo->Pi[i]; // Por eso contemplo un espacio mas de Pi para estructurar despues
	}
	nodo->Ki[i] = valor;
	nodo->k++;
	// Si es igual al orden, entonces parte en dos el arreglo y regresa el valor a insertar en el arreglo padre
	if(nodo->k == nodo->orden){
		int regreso = nodo->Ki[nodo->k >> 1]; // Guardo el valor a regresar 
		int kw = 0 ;
		Nodo *nuevo_nodo= creacionNodo(nodo->orden); // Creamos un nodo nuevo
		nodo->Ki[(nodo->k >> 1)] = 0; // Eliminamos la mitad
		// Pasamos los hijos al nuevo nodo y borramos la info pasada del actual despues de la mitad
		int j = (nodo->k >> 1) + 1;
		for(; j<nodo->orden;j++ , kw++){
			nuevo_nodo -> Pi[kw] = nodo->Pi[j];
			nuevo_nodo -> Ki[kw] = nodo->Ki[j];
			nodo->Pi[j] = NULL;
			nodo->Ki[j] = 0; 
		}
		// Pasamos el ultimo hijo que falta
		nuevo_nodo -> Pi[kw + 1] = nodo->Pi[j + 1];
		nodo->Pi[j + 1] = NULL;
		// Los guardamos en un bufer
		// Si me regresa un  numero diferente de 0, en la funcion de la raiz entonces me crea un nodo
		//  y me aguarda como hijos ambos bufers, pero si me regresa un numero en un nodo que no es raiz, 
		//  entonces solo me guarda el mas grande
		//  bufer_bajo = *nodo;
		//  bufer_alto = *nuevo_nodo;
		return regreso;
	}
	return 0;
}

int main(){
	int valores[] = {3, 6, 9};
		
	return 0;
}



