/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Característica del programa: 
Generar el archivo main de la lista circular
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// List structure
typedef struct CList {
    int size;
    Node* head;
    void (*destroy)(void *data);
} CList;

// Functions
Node* createNode(int data);
void clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, Node *node, int data);
int clist_rem_next(CList *list, Node *node, int *data);
void displayList(CList *list);

// Main function
int main() {
    CList list;
    clist_init(&list, NULL);

    // Insert elements
    clist_ins_next(&list, NULL, 10);
    clist_ins_next(&list, list.head, 20);
    clist_ins_next(&list, list.head->next, 30);

    printf("List after insertion: ");
    displayList(&list);

    // Remove an element
    int removed_data;
    clist_rem_next(&list, list.head, &removed_data);
    printf("List after removing node with data %d: ", removed_data);
    displayList(&list);

    // Clean up
    clist_destroy(&list);
    return 0;
}

// Function to create a node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Initialize the list
void clist_init(CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

// Destroy the list
void clist_destroy(CList *list) {
    while (list->size > 0) {
        int data;
        clist_rem_next(list, list->head, &data);
        if (list->destroy != NULL) {
            list->destroy(&data);
        }
    }
}

// Insert next node
int clist_ins_next(CList *list, Node *node, int data) {
    Node* new_node = createNode(data);
    if (new_node == NULL) return -1;

    if (list->size == 0) {
        list->head = new_node;
    } else {
        new_node->next = node->next;
        new_node->prev = node;
        node->next->prev = new_node;
        node->next = new_node;
    }

    if (node == NULL || list->size == 0) {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    } else {
        new_node->next = node->next;
        node->next->prev = new_node;
        node->next = new_node;
        new_node->prev = node;
    }

    list->size++;
    return 0;
}

// Remove next node
int clist_rem_next(CList *list, Node *node, int *data) {
    if (list->size == 0 || node == NULL) return -1;

    Node* old_node = node->next;
    *data = old_node->data;

    if (list->size == 1) {
        list->head = NULL;
    } else {
        node->next = old_node->next;
        old_node->next->prev = node;
        if (old_node == list->head) {
            list->head = old_node->next;
        }
    }

    free(old_node);
    list->size--;
    return 0;
}

// Display the list
void displayList(CList *list) {
    if (list->size == 0) return;

    Node* current = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

