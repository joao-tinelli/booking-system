#include "log.h"
#include <stdio.h>
#include <string.h>


void avlTreeLog(char *function, const unsigned int code, const unsigned int capacity) {
    FILE *arq_log = fopen("./output/saida.txt", "a");
    if (arq_log == NULL){
        perror("Erro ao abrir o arquivo dde log.");
        return;
    }

    if (strcmp(function, "INSERT_AVL_TREE"))
        fprintf(arq_log, "%s %d %d\n", function, code, capacity);

    else if (strcmp(function, "INSERT_AVL_TREE"))
        fprintf(arq_log, "%s %d %d\n", function, code, capacity);
    
    else if (strcmp(function, "SHOW_AVL_TREE"))
        fprintf(arq_log, "%s\n", function);
}

void heapLog(char *function, const unsigned int code, const unsigned int priority) {
     FILE *arq_log = fopen("./output/saida.txt", "a");
    if (arq_log == NULL){
        perror("Erro ao abrir o arquivo dde log.");
        return;
    }

    if (strcmp(function, "INSERT_HEAP"))
        fprintf(arq_log, "%s %d %d\n", function, code, priority);

    if (strcmp(function, "CANCEL_RESERVATION_HEAP"))
        fprintf(arq_log, "%s %d\n", function, priority);

    if (strcmp(function, "SEARCH_PRIORITY_HEAP"))
        fprintf(arq_log, "%s %d\n", function, code);

    if (strcmp(function, "UPDATE_PRIORITY_HEAP"))
        fprintf(arq_log, "%s %d\n", function, priority);
}

void logOfHashTableFunctions(const char *function, const unsigned int code, const char *status) {
    FILE *arq_log = fopen("./output/saida.txt", "a");
    if (arq_log == NULL){
        perror("Erro ao abrir o arquivo dde log.");
        return;
    }

    if (strcmp(function, "INSERT_HASH_TABLE"))
        fprintf(arq_log, "%s %d %s\n", function, code, status);

    if (strcmp(function, "UPDATE_STATUS_HASH_TABLE"))
        fprintf(arq_log, "%s %d %s\n", function, code, status);

    if (strcmp(function, "SEARCH_STATUS_HASH_TABLE"))
        fprintf(arq_log, "%s %d %s\n", function, code, status);
    
    if (strcmp(function, "SHOW_HASH_TABLE"))
        fprintf(arq_log, "%s %d %s\n", function, code, status);
}