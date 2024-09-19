
/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Características del programa: 
  Basado en el anterior codigo .exe has el siguiente programa:
 Deberá generar la lista en tiempo de ejecución.
 Deberá hacer 4 funciones de insercción adicionales con los siguientes datos: D, R, o y 9, en cualquier región de la estructura
 Deberá hacer 4 funciones para eliminar en distintas locaciones de la estructura.
*/

#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la lista enlazada
typedef struct Nodo {
    char dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(char valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar al inicio
void insertarInicio(Nodo** cabeza, char valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Función para insertar al final
void insertarFinal(Nodo** cabeza, char valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para insertar despues de un nodo dado
void insertarDespues(Nodo* prevNodo, char valor) {
    if (prevNodo == NULL) {
        printf("El nodo anterior no puede ser NULL.\n");
        return;
    }
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = prevNodo->siguiente;
    prevNodo->siguiente = nuevoNodo;
}

// Funcion para insertar en una posicion específica
void insertarEnPosicion(Nodo** cabeza, char valor, int posicion) {
    if (posicion == 0) {
        insertarInicio(cabeza, valor);
        return;
    }
    Nodo* temp = *cabeza;
    int i;
    for ( i = 0; temp != NULL && i < posicion - 1; i++) {
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("Posición fuera de rango.\n");
        return;
    }
    insertarDespues(temp, valor);
}

// Función para eliminar al inicio
void eliminarInicio(Nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    Nodo* temp = *cabeza;
    *cabeza = (*cabeza)->siguiente;
    free(temp);
}

// Función para eliminar al final
void eliminarFinal(Nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    Nodo* temp = *cabeza;
    Nodo* prev = NULL;
    while (temp->siguiente != NULL) {
        prev = temp;
        temp = temp->siguiente;
    }
    if (prev != NULL) {
        prev->siguiente = NULL;
    } else {
        *cabeza = NULL;
    }
    free(temp);
}

// Función para eliminar un nodo dado
void eliminarNodo(Nodo** cabeza, char valor) {
    if (*cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    Nodo* temp = *cabeza;
    Nodo* prev = NULL;
    while (temp != NULL && temp->dato != valor) {
        prev = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("El valor no esta en la lista.\n");
        return;
    }
    if (prev == NULL) {
        *cabeza = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }
    free(temp);
}

// Funcion para eliminar en una posición específica
void eliminarEnPosicion(Nodo** cabeza, int posicion) {
    if (*cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    Nodo* temp = *cabeza;
    if (posicion == 0) {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }
    Nodo* prev = NULL;
     int i;
    for (i = 0; temp != NULL && i < posicion; i++) {
        prev = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("Posicion fuera de rango.\n");
        return;
    }
    prev->siguiente = temp->siguiente;
    free(temp);
}

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%c -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

// Función principal
int main() {
    Nodo* lista = NULL;

    // Insertando elementos iniciales
    insertarFinal(&lista, 'A');
    insertarFinal(&lista, 'B');
    insertarFinal(&lista, 'C');

    printf("Lista original:\n");
    imprimirLista(lista);

    // Insertando nuevos elementos (D, R, o, 9)
    insertarInicio(&lista, 'D'); // Insertar 'D' al inicio
    insertarFinal(&lista, 'R');  // Insertar 'R' al final
    insertarEnPosicion(&lista, 'o', 2); // Insertar 'o' en la posición 2
    insertarDespues(lista->siguiente, '9'); // Insertar '9' después del segundo nodo

    printf("\nLista despues de inserciones:\n");
    imprimirLista(lista);

    // Eliminando elementos en distintas posiciones
    eliminarInicio(&lista);  // Eliminar al inicio
    eliminarFinal(&lista);   // Eliminar al final
    eliminarEnPosicion(&lista, 1); // Eliminar en la posición 1
    eliminarNodo(&lista, 'B');     // Eliminar el nodo con valor 'B'

    printf("\nLista despues de eliminaciones:\n");
    imprimirLista(lista);

    return 0;
}

