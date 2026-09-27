#ifndef ARBOLESB
#define ARBOLESB

typedef struct nodo{
	struct nodo **Pi; // Un arreglo de los punteros siempre va a ser de tamaño fijo, de tamaño M + 1, para dejar una para la division
	int *Ki; // Un arreglo de M - 1 valores. Pero se deja uno mas para detectar el split 
	int k; // Numero de claves actuales 
	int orden; // Indica el orden de el arbol. 
}Nodo;

typedef struct hoja{
	struct hoja *siguiente;
	int *valores; // Se tienen C-1 valores			
}Hoja;

typedef struct arbolB_plus{
	Nodo *raiz;
	int orden;
}ArbolB_plus;

// Creacion de un arboB_plus
ArbolB_plus* creacionArbol(int orden);

// Creacion de un nodo
Nodo* creacionNodo();

// Creacion de una hoja
Hoja* creacionHoja();

// Buscar el nodo a insertar
int insertarValorAArbol(int valor, Nodo* nodo);

// Busqueda Binaria, me regresa la ubicacion del valor K. 
int busquedaBinaria(int valor, int limiteDerecho, int *valores);

// Insertar valor arbol
void insertarValorArbol(int valor, ArbolB_plus* arbol);

// Borrar nodo
void borrarNodo(Nodo* nodo);

// Borrar arbol
void borrarArbol(ArbolB_plus* arbolB_plus);

// Se imprime por niveles
void imprimirArbol(ArbolB_plus* arbolB_plus);

// Insertar valor en el nodo
int insertarValorNodo(Nodo *nodo, int valor);

#endif
