#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node {
    unsigned int code;
    char status[25];
    struct _node *next;
} NodeHash;

typedef struct {
    NodeHash *start;
    unsigned int tam;
} ListHash;

void inicializeList(ListHash *list) {
    list->start = NULL;
    list->tam = 0;
}

void insertIntoList(ListHash *list, unsigned int code, char *status) {
    NodeHash *node = (NodeHash*) malloc(sizeof(NodeHash));

    if (node) {
        node->code = code;
        strcpy(node->status, status);
        node->next = list->start;
        list->start = node;
        list->tam++;
    } else {
        perror("Error: Failed to insert in the list!\n");
    }
}

void updateRoomStatus(ListHash *list, unsigned int code, char *newStatus) {
    NodeHash *aux = list->start;

    while (aux && aux->code != code) {
        aux = aux->next;
    }

    if (aux) {
        strcpy(aux->status, newStatus);
        printf("\nSuccess: Room with code '%d' updated!\n", code);
    } else {
        printf("\nERROR: Room with code '%d' not found\n", code);
    }
}

char *searchList(ListHash *list, unsigned int code) {
    NodeHash *aux = list->start;

    while (aux && aux->code != code) {
        aux = aux->next;
    }

    return aux ? aux->status : NULL;
}

void printList(ListHash *list) {
    NodeHash *aux = list->start;

    while (aux) {
        printf("[%d: %s] -> ", aux->code, aux->status);
        aux = aux->next;
    }
    printf("NULL");
}

void inicializeHashTable(ListHash t[], unsigned int size) {
    for (int i = 0; i < size; i++) {
        inicializeList(&t[i]);
    }
}

int hashFunction(unsigned int code, unsigned int size) {
    return code % size;
}

void insertIntoHashTable(ListHash t[], unsigned int code, char *status, unsigned int size) {
    int id = hashFunction(code, size);
    insertIntoList(&t[id], code, status);
}

void updateStatusIntoHashTable(ListHash t[], unsigned int code, char *newStatus, unsigned int size) {
    int id = hashFunction(code, size);
    updateRoomStatus(&t[id], code, newStatus);
}

char *searchStatusIntoHashTable(ListHash t[], unsigned int code, unsigned int size) {
    int id = hashFunction(code, size);
    printf("-> Indice gerado: %d.\n", id);
    return searchList(&t[id], code);
}

void printHashTable(ListHash t[], const unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("%d = ", i);
        printList(&t[i]);
        puts("");
    }
}
