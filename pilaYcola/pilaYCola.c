#include <stdio.h>
#include <stdlib.h>

// 	## Estructuras
// Nodo
typedef struct nodo{
	char contenido;
	struct nodo *anterior;
	struct nodo *siguiente;
} Nodo;

// Pila
typedef struct _pila{
	Nodo *inicio;
	Nodo *final;
}Pila;

//	## Funciones
// Crear un nodo
Nodo* crear_nodo(char contenido);

// Crear una pila
Pila* crear_pila();

// Insertar un nodo a la pila
void insertar_en_pila(Pila* pila, char contenido);

// Eliminar un miembro a la pila
void eliminar_en_pila(Pila* pila);

// Inserta un nodo en forma de cola
void insertar_en_cola(Pila* pila, char contenido);

// Eliminar un miembro a la cola
void eliminar_en_cola(Pila* pila);



int main(){
	
	Pila *pila = crear_pila();
	// 7 6 4 3 5
	// 5 7 3 6 4
	insertar_en_pila(pila, '3');
	insertar_en_cola(pila, '4');
	insertar_en_pila(pila, '5');
	insertar_en_cola(pila, '6');
	insertar_en_cola(pila, '7');
	
	
	printf("%c\n" , pila -> final -> contenido);
	eliminar_en_pila(pila);
	printf("%c\n" , pila -> inicio -> contenido);
	eliminar_en_cola(pila);
	printf("%c\n" , pila -> final -> contenido);
	eliminar_en_pila(pila);
	printf("%c\n" , pila -> inicio -> contenido);
	eliminar_en_cola(pila);
	printf("%c\n" , pila -> final -> contenido);
	eliminar_en_pila(pila);
	
	
	free(pila);
		
	return 0;
}

Nodo* crear_nodo(char contenido){
	Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo -> contenido = contenido;
	nodo -> anterior = NULL;
	nodo -> siguiente = NULL;
	return nodo;
}

Pila* crear_pila(){
	Pila* pila = (Pila *)malloc(sizeof(Pila));
	pila -> inicio = NULL;
	pila -> final = NULL;
	return pila;
}


void insertar_en_pila(Pila* pila, char contenido){
	Nodo *nodo = crear_nodo(contenido);
	if(!(pila -> inicio)) 
		pila -> inicio = nodo;
	else{ 
		nodo -> anterior = pila -> final;
		pila -> final -> siguiente = nodo;
	}
	pila -> final = nodo;
}

 
void eliminar_en_pila(Pila* pila){
	if(!(pila -> inicio)) // Ya esta vacio
		return;
	Nodo *nodoFinal = pila -> final -> anterior;
	if(!(nodoFinal)){ // Si es un solo elemento
		free(pila -> final);
		pila -> inicio = NULL;
		pila -> final = NULL;
		return;
	}
	nodoFinal -> siguiente = NULL;
	free(pila -> final);
	pila -> final = nodoFinal;
	 	
}


void insertar_en_cola(Pila* pila, char contenido){
	Nodo *nodo = crear_nodo(contenido);
	if(!(pila -> inicio)){
		pila -> inicio = nodo;
		pila -> final = nodo;
	}
	else{
		nodo -> siguiente = pila -> inicio;
		pila -> inicio -> anterior = nodo;
		pila -> inicio = nodo;
	}
}

// |
// n
void eliminar_en_cola(Pila* pila){
	if(!(pila -> inicio)) // Ya esta vacio
		return;
	Nodo *nodoInicial = pila -> inicio -> siguiente;
	if(!(nodoInicial)){ // Si existe solo un elemento
		free(pila -> inicio);
		pila -> inicio = NULL;
		pila -> final = NULL;		
		return;
	}
	nodoInicial -> anterior = NULL;
	free(pila -> inicio);
	pila -> inicio = nodoInicial;
}
