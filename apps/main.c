#include <stdio.h>
#include <string.h>
#include "avl.h"
#include "heap.h"
#include "hash.h"

int main()
{
    FILE *file = fopen("./input/input-1.txt", "r");

    char line_file[100], line_name[20];
    int n1, n2;

    if (file == NULL)
    {
        perror("Error opening file.\n");
        return 0;
    }

    // Reading the input file
    while (fgets(line_file, sizeof(line_file), file) != NULL)
    {
        sscanf(line_file, "%s", line_name);

        if (strcmp(line_name, "CRIAR_SALA") == 0){

        } else if (strcmp(line_file, "RESERVAR_SALA") == 0){

        } else if (strcmp(line_file, "BLOQUEAR_SALA") == 0){

        } else if (strcmp(line_file, "DESBLOQUEAR_SALA") == 0){

        } else if (strcmp(line_file, "CANCELAR_RESERVA") == 0){

        } else if (strcmp(line_file, "LISTAR_SALAS") == 0){

        } else if (strcmp(line_file, "CONSULTAR_SALA") == 0){

        } else {

        }
    }
    // Closing the file
    fclose(file);

    return 0;
}