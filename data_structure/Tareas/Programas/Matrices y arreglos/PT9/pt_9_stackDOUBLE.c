/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Característica del programa: 
Modifique el archivo main para que acepte dobles.
*/


#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*
   Print stack
*/
static void print_stack(const Stack *stack) {
    ListNode *node;
    double *data;
    int size, i;
    
    // Verifica el tamaño de la pila
    fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));

    i = 0;
    node = list_head(stack); // Asegúrate de que list_head está bien definida en list.h

    // Recorre cada nodo en la pila
    while (i < size) {
        data = list_data(node); // Obtiene los datos en el nodo actual
        
        // Verifica si data es NULL para evitar errores
        if (data == NULL) {
            fprintf(stderr, "Error: Null data encountered in stack node.\n");
            return;
        }

        // Imprime el valor del nodo
        fprintf(stdout, "stack[%03d]=%.3f, %p -> %p\n", i, *data, node, node->next);
        node = list_next(node); // Obtén el siguiente nodo
        i++;
    }
}

int main(int argc, char const *argv[]) {
    Stack stack;
    double *data;
    int i;

    // Inicializa la pila y verifica que no haya errores
    stack_init(&stack, free);

    fprintf(stdout, "\nPushing 10 elements\n");

    for (i = 1; i <= 10; i++) {  // Cambiado a <= para 10 elementos
        data = (double *)malloc(sizeof(double));
        
        // Verifica la asignación de memoria
        if (data == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return 1;
        }

        *data = i * 1.50;

        // Intenta apilar el elemento y verifica que no haya errores
        if (stack_push(&stack, data) != 0) {
            fprintf(stderr, "Error: Failed to push element onto stack.\n");
            return 1;
        }
    }
    print_stack(&stack);

    fprintf(stdout, "\nPopping 3 elements\n");
    for (i = 0; i < 3; i++) {
        if (stack_pop(&stack, (void **)&data) == 0) {
            free(data); // Libera el dato desapilado
        } else {
            fprintf(stderr, "Error: Failed to pop element from stack.\n");
            return 1;
        }
    }
    print_stack(&stack);

    fprintf(stdout, "\nPushing 320.657 and 765.230\n");

    // Apilar 320.657
    data = (double *)malloc(sizeof(double));
    if (data == NULL) return 1;
    *data = 320.657;
    if (stack_push(&stack, data) != 0) {
        fprintf(stderr, "Error: Failed to push 320.657 onto stack.\n");
        return 1;
    }

    // Apilar 765.230
    data = (double *)malloc(sizeof(double));
    if (data == NULL) return 1;
    *data = 765.230;
    if (stack_push(&stack, data) != 0) {
        fprintf(stderr, "Error: Failed to push 765.230 onto stack.\n");
        return 1;
    }

    print_stack(&stack);

    // Verifica el elemento superior sin desapilar
    data = stack_peek(&stack);
    if (data != NULL) {
        fprintf(stdout, "\nPeeking at the top element [value]=%.3f\n", *data);
    } else {
        fprintf(stdout, "\nPeeking at the top element [value]=NULL (Stack is empty)\n");
    }
    print_stack(&stack);

    fprintf(stdout, "\nPopping all elements\n");
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, (void **)&data) == 0) {
            free(data);
        } else {
            fprintf(stderr, "Error: Failed to pop element from stack.\n");
            return 1;
        }
    }

    // Revisa el tope de la pila después de vaciarla
    data = stack_peek(&stack);
    if (data != NULL) {
        fprintf(stdout, "\nPeeking at the top element [value]=%.3f\n", *data);
    } else {
        fprintf(stdout, "\nPeeking at the top element [value]=NULL (Stack is empty)\n");
    }
    print_stack(&stack);

    // Destruye la pila
    fprintf(stdout, "\nDestroying the stack\n");
    stack_destroy(&stack);

    return 0;
}

