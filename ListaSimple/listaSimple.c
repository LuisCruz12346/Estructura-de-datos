#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int contenido;
	struct nodo *siguiente; 
} Nodo;	

typedef struct lista{
	 Nodo *inicio;
	 Nodo *final; 
} Lista;

// Creamos un nodo
Nodo* crearNodo(int entrada);

//Crear una lista
Lista* crearLista();

// Anadir un nodo a la lista
void anadirNodoALista(Lista *lista, int contenido);

// Liberar memoria de la lista
void liberarLista(Lista *lista);


int main(){
	
	Lista *lista1 = crearLista();
	
	anadirNodoALista(lista1 , 3);
	anadirNodoALista(lista1 , 4);
	
	Nodo *nodo = lista1 -> inicio;
	while(nodo){
		printf("%d\n", nodo -> contenido);
		nodo = nodo -> siguiente;	
	}
	
	liberarLista(lista1);
	
	free(lista1);
	
	return 0;
}

/*	*** Creacion de nodo ***
	1. Reservamos el espacio en memoria para los contenidos
	2. Ingresamos los contenidos
	3. Regresamos el nodo creado
*/
Nodo* crearNodo(int entrada){
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo -> contenido = entrada;
	nodo -> siguiente = NULL;
	return nodo;
}

/*	*** Creacion de lista ***
	1. Reservamos el espacio en memoria para los contenidos
	2. Definimos la direccion prederminada
	3. Regresamos la lista creada
*/
Lista* crearLista(){
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	lista -> inicio = NULL;
	lista -> final = NULL;
	return lista;
}

/*	*** Liberar espacio lista ***
	1. Se selecciona el nodo inicial
	2. Se guarda el nodo siguiente de manera temporal
	3. Se libera el nodo actual
	4. Se obtiene el nodo actual del auxiliar
*/
void liberarLista(Lista *lista){
	Nodo *nodo = lista -> inicio;
	Nodo *aux;
	while(nodo){
		aux = nodo -> siguiente; 
		free(nodo);
		nodo = aux;
	}
}

/*	*** Añadir un nodo a una lista ***
	1. Creamos y obtenemos la direccion del nodo creado
	2. Verifamos si existen elementos en la lista, sino este es el inicial
	3. Si si existen entonces se añade al final de la lista. 
*/
void anadirNodoALista(Lista *lista, int contenido){
	Nodo *nodo = crearNodo(contenido);
	
	if((lista -> inicio) == NULL){
		lista -> inicio = nodo;
	}else{
		lista -> final -> siguiente = nodo;
	}
	lista -> final = nodo;
	
}

