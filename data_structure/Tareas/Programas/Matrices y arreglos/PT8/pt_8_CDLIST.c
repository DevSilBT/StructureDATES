/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Característica del programa: 
Generar el archivo header, source y main de la lista doblemente ligada circular
*/

#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

// Función auxiliar para imprimir la lista circular doblemente ligada
static void print_cdlist(const CDList *cdlist) {
    CDListNode *node = cdlist_head(cdlist);
    int *data, size = cdlist_size(cdlist), i = 0;

    fprintf(stdout, "Circular double list size: %d\n", size);

    while (i < size) {
        data = cdlist_data(node);
        fprintf(stdout, "Node[%03d] = %03d, %p -> %p\n", i, *data, node, node->next);
        node = cdlist_next(node);
        i++;
    }
    printf("\n");
}

int main() {
    CDList cdlist;
    CDListNode *node;
    int *data, i;

    // Inicializar la lista
    cdlist_init(&cdlist, free);

    // Llenar la lista circular
    node = cdlist_head(&cdlist);
    for (i = 0; i < 10; i++) {
        data = (int *)malloc(sizeof(int));
        *data = i + 1;
        if (cdlist_ins_next(&cdlist, node == NULL ? cdlist_head(&cdlist) : node, data) != 0)
            return 1;
        node = cdlist_head(&cdlist);
    }

    print_cdlist(&cdlist);

    // Insertar un nuevo elemento en la cabeza
    printf("Inserting 26 at the head\n");
    data = (int *)malloc(sizeof(int));
    *data = 26;
    if (cdlist_ins_next(&cdlist, cdlist_head(&cdlist), data) != 0)
        return 1;
    print_cdlist(&cdlist);

    // Eliminar el nodo después del nodo cabeza
    printf("Removing the node after the head\n");
    if (cdlist_remove(&cdlist, cdlist_head(&cdlist), (void **)&data) != 0)
        return 1;
    print_cdlist(&cdlist);

    // Destruir la lista
    printf("Destroying the list\n");
    cdlist_destroy(&cdlist);

    return 0;
}

