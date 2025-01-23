#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node {
    unsigned int code;
    char status[25];
    struct _node *next;
} NodeHash;

void inicializeList(ListHash *list) {
    if (list) {
        list->start = NULL;
        list->tam = 0;
    }
}

void insertIntoList(ListHash *list, unsigned int code, const char *status) {
    NodeHash *node = (NodeHash *)malloc(sizeof(NodeHash));
    if (node) {
        node->code = code;
        strncpy(node->status, status, sizeof(node->status) - 1);
        node->status[sizeof(node->status) - 1] = '\0';
        node->next = list->start;
        list->start = node;
        list->tam++;
    } else {
        fprintf(stderr, "Error: Failed to insert in the list!\n");
    }
}

void updateRoomStatus(ListHash *list, unsigned int code, const char *newStatus) {
    NodeHash *aux = list->start;

    while (aux) {
        if (aux->code == code) {
            strncpy(aux->status, newStatus, sizeof(aux->status) - 1);
            aux->status[sizeof(aux->status) - 1] = '\0';
            printf("\nSuccess: Room with code '%d' updated!\n", code);
            return;
        } else {
            printf("\nERROR: Room with code '%d' not found\n", code);
        }
        aux = aux->next;
    }

}

char *searchList(ListHash *list, unsigned int code) {
    NodeHash *aux = list->start;

    while (aux) {
        if (aux->code == code)
            return aux->status;
        aux = aux->next;
    }

    return NULL;
}

void printList(ListHash *list) {
    NodeHash *aux = list->start;

    while (aux) {
        printf("[%d: %s] -> ", aux->code, aux->status);
        aux = aux->next;
    }
    printf("NULL");
}

void initializeHashTable(ListHash *t, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        inicializeList(&t[i]);
    }
}

int hashFunction(unsigned int code, unsigned int size) {
    return code % size;
}

void insertIntoHashTable(ListHash *t, unsigned int code, const char *status, unsigned int size) {
    int id = hashFunction(code, size);
    insertIntoList(&t[id], code, status);
}

void updateStatusIntoHashTable(ListHash *t, unsigned int code, const char *newStatus, unsigned int size) {
    int id = hashFunction(code, size);
    updateRoomStatus(&t[id], code, newStatus);
}

char *searchStatusIntoHashTable(ListHash *t, unsigned int code, unsigned int size) {
    int id = hashFunction(code, size);
    return searchList(&t[id], code);
}

void printHashTable(ListHash *t, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        printf("%d = ", i);
        printList(&t[i]);
        puts("\n");
    }
}

void freeList(ListHash *list) {
    NodeHash *current = list->start;
    while (current) {
        NodeHash *temp = current;
        current = current->next;
        free(temp);
    }
    list->start = NULL;
    list->tam = 0;
}

void freeHashTable(ListHash *t, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        freeList(&t[i]);
    }
}
