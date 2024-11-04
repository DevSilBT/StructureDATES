/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Característica del programa: 
  Generar el archivo main de la lista doblemente ligada
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;


Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    return nuevoNodo;
}


void insertarInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevoNodo;
        *cabeza = nuevoNodo;
    }
}


void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}


void liberarLista(Nodo* cabeza) {
    Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* cabeza = NULL;

    
    insertarInicio(&cabeza, 10);
    insertarInicio(&cabeza, 20);
    insertarInicio(&cabeza, 30);

    
    printf("Lista: ");
    imprimirLista(cabeza);

    
    liberarLista(cabeza);

    return 0;
}
