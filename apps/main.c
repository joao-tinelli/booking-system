#include <stdio.h>
#include <string.h>

#include "avl.h"
#include "heap.h"
#include "hash.h"
#include "log.h"

#define TAM_HASH_TABLE 5

int main()
{
    NodeAVL *root_avl = NULL;
    NodeHeap *root_heap = NULL;
    ListHash hashTable[TAM_HASH_TABLE];

    initializeHashTable(hashTable, TAM_HASH_TABLE);

    FILE *file = fopen("./input/input-1.txt", "r");

    char line_file[100], line_name[20];
    unsigned int room_code, room_capacity, room_priority, new_priority;

    if (file == NULL)
    {
        perror("Error opening file.\n");
        return 0;
    }

    // Reading the input file
    while (fgets(line_file, sizeof(line_file), file) != NULL)
    {
        sscanf(line_file, "%s", line_name);

        if (strcmp(line_name, "CRIAR_SALA") == 0) {
            sscanf(line_file, "%*s %d %d", &room_code, &room_capacity);

            root_avl = insertRoom(root_avl, room_code, room_capacity);
            insertIntoHashTable(hashTable, room_code, "disponivel", TAM_HASH_TABLE);

            // log
            avlTreeLog("INSERT_AVL_TREE", room_code, room_capacity);
            logOfHashTableFunctions("INSERT_HASH_TABLE", room_code, "disponivel");
                                     
        } else if (strcmp(line_name, "RESERVAR_SALA") == 0) {
            sscanf(line_file, "%*s %d %d", &room_code, &room_priority); 

            insert(&root_heap, room_code, room_priority);        
            updateStatusIntoHashTable(hashTable, room_code, "bloqueada", TAM_HASH_TABLE);       

            // log
            heapLog("INSERT_HEAP", room_code, room_priority);   
            logOfHashTableFunctions("UPDATE_STATUS_HASH_TABLE", room_code, "bloqueada");                                             
            
        } else if (strcmp(line_name, "BLOQUEAR_SALA") == 0) {
            sscanf(line_file, "%*s %d", &room_code);

            updateStatusIntoHashTable(hashTable, room_code, "bloqueada", TAM_HASH_TABLE);  

            // log
            logOfHashTableFunctions("UPDATE_STATUS_HASH_TABLE", room_code, "bloqueada");    

        } else if (strcmp(line_name, "DESBLOQUEAR_SALA") == 0) {
            sscanf(line_file, "%*s %d", &room_code);

            updateStatusIntoHashTable(hashTable, room_code, "disponivel", TAM_HASH_TABLE);      
            
            // log
            logOfHashTableFunctions("UPDATE_STATUS_HASH_TABLE", room_code, "disponivel");                                                  // **Joga na hash como 'disponivel'  
                                                       
        } else if (strcmp(line_name, "CANCELAR_RESERVA") == 0) {
            sscanf(line_file, "%*s %d", &room_code);

            room_priority = findPriorityByCode(root_heap, room_code);            
            findAndRemoveByPriority(root_heap, room_priority);     // Removendo a reserva
            updateStatusIntoHashTable(hashTable, room_code, "disponivel", TAM_HASH_TABLE); 

            // log
            heapLog("SEARCH_PRIORITY_HEAP", room_code, room_priority);
            heapLog("CANCEL_RESERVATION_HEAP", room_code, room_priority);
            logOfHashTableFunctions("UPDATE_STATUS_HASH_TABLE", room_code, "disponivel");       
            
        } else if (strcmp(line_name, "LISTAR_SALAS") == 0){
            puts("\nAvailable rooms:");                        
            showAVLTree(root_avl, 0); 
            puts("");

            // log
            avlTreeLog("SHOW_AVL_TREE", 0, 0);                                                     

        } else if (strcmp(line_name, "CONSULTAR_SALA") == 0){
            sscanf(line_file, "%*s %d", &room_code); 

            char *status = searchStatusIntoHashTable(hashTable, room_code, TAM_HASH_TABLE);   
            printf("Room %d: %s\n", room_code, status); 

            // log
            logOfHashTableFunctions("SEARCH_STATUS_HASH_TABLE", room_code, status);                                                      
                                                                
        } else if (strcmp(line_name, "ATUALIZAR_PRIORIDADE") == 0) {
            sscanf(line_file, "%*s %d %d", &room_code, &new_priority); 

            room_priority = findPriorityByCode(root_heap, room_code);
            findAndRemoveByPriority(root_heap, room_priority);   
            insert(&root_heap, room_code, new_priority);         

            // log
            heapLog("SEARCH_PRIORITY_HEAP", room_code, room_priority);
            heapLog("CANCEL_RESERVATION_HEAP", room_code, room_priority);
            heapLog("INSERT_HEAP", room_code, room_priority);
        } else {
            perror("Problem reading the line...");
        }
    }
    // Closing the file
    fclose(file);

    printf("\nHASH (table):\n");
    printHashTable(hashTable, TAM_HASH_TABLE);

    puts("HEAP (Reservations):");
    printInOrder(root_heap);

    return 0;
}