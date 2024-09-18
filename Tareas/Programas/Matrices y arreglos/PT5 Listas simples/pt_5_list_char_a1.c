#include <stdio.h>
#include <stdlib.h>

/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Características del programa: 
Modifique el archivo ex1_list.c para que en lugar de aceptar números enteros, ahora acepte caracteres.
Deberá llenarse con al menos 10 caracteres de forma previa
Deberá contar con 4 funciones para añadir los siguientes valores en distintas locaciones de la estructura: A, W, T, M; pueden ser insertados en la cabeza, o en cualquier parte de la lista
Deberá contar con 4 funciones para eliminar en distintas locaciones de la estructura como la cabeza o cualquier región
*/


// Estructura de nodo
struct Nodo {
    char data;
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(char valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->data = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al inicio
void insertarCabeza(struct Nodo** cabeza, char valor) {
    struct Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Función para insertar un nodo al final
void insertarFinal(struct Nodo** cabeza, char valor) {
    struct Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    struct Nodo* temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

// Función para insertar un nodo en una posición específica
void insertarPosicion(struct Nodo** cabeza, char valor, int posicion) {
    if (posicion == 0) {
        insertarCabeza(cabeza, valor);
        return;
    }
    struct Nodo* temp = *cabeza;
    int i;
    for (i = 0; temp != NULL && i < posicion - 1; i++) {
        temp = temp->siguiente;
    }
    if (temp == NULL || temp->siguiente == NULL) {
        insertarFinal(cabeza, valor);
    } else {
        struct Nodo* nuevoNodo = crearNodo(valor);
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

// Funciones específicas para insertar los caracteres
void insertarA(struct Nodo** cabeza, int posicion) {
    insertarPosicion(cabeza, 'A', posicion);
}

void insertarW(struct Nodo** cabeza, int posicion) {
    insertarPosicion(cabeza, 'W', posicion);
}

void insertarT(struct Nodo** cabeza, int posicion) {
    insertarPosicion(cabeza, 'T', posicion);
}

void insertarM(struct Nodo** cabeza, int posicion) {
    insertarPosicion(cabeza, 'M', posicion);
}

// Función para eliminar el nodo en la cabeza
void eliminarCabeza(struct Nodo** cabeza) {
    if (*cabeza == NULL) return;
    struct Nodo* temp = *cabeza;
    *cabeza = (*cabeza)->siguiente;
    free(temp);
}

// Función para eliminar el nodo en la cola
void eliminarFinal(struct Nodo** cabeza) {
    if (*cabeza == NULL) return;
    if ((*cabeza)->siguiente == NULL) {
        free(*cabeza);
        *cabeza = NULL;
        return;
    }
    struct Nodo* temp = *cabeza;
    while (temp->siguiente->siguiente != NULL) {
        temp = temp->siguiente;
    }
    free(temp->siguiente);
    temp->siguiente = NULL;
}

// Función para eliminar el nodo en una posición específica
void eliminarPosicion(struct Nodo** cabeza, int posicion) {
    if (*cabeza == NULL) return;
    if (posicion == 0) {
        eliminarCabeza(cabeza);
        return;
    }
    struct Nodo* temp = *cabeza;
    int i;
    for ( i= 0; temp != NULL && i < posicion - 1; i++) {
        temp = temp->siguiente;
    }
    if (temp == NULL || temp->siguiente == NULL) return;
    struct Nodo* siguienteNodo = temp->siguiente->siguiente;
    free(temp->siguiente);
    temp->siguiente = siguienteNodo;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* cabeza = NULL;

    // Llenar la lista con 10 caracteres de forma previa
    char valoresIniciales[] = {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    int i;
    for ( i = 0; i < 10; i++) {
        insertarFinal(&cabeza, valoresIniciales[i]);
    }

    printf("Lista inicial:\n");
    imprimirLista(cabeza);

    // Insertar caracteres A, W, T, M en distintas locaciones
    insertarA(&cabeza, 0);  // Insertar A en la cabeza
    insertarW(&cabeza, 5);  // Insertar W en la posición 5
    insertarT(&cabeza, 7);  // Insertar T en la posición 7
    insertarM(&cabeza, 3);  // Insertar M en la posición 3

    printf("\nLista después de las inserciones:\n");
    imprimirLista(cabeza);

    // Eliminar caracteres en distintas locaciones
    eliminarCabeza(&cabeza);   // Eliminar en la cabeza
    eliminarPosicion(&cabeza, 4); // Eliminar en la posición 4
    eliminarFinal(&cabeza);    // Eliminar en la cola

    printf("\nLista después de las eliminaciones:\n");
    imprimirLista(cabeza);

    return 0;
}

