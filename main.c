#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "./headers/globals.h"
#include "./headers/key.h"
#include "./headers/semaforo.h"
#include "./headers/file.h"
#include "./headers/panel.h"
#include "./headers/cci.h"

int main(int argc, char *argv[]) {

    int numero;

    if (argc < 2) {

        printf("Uso: %s <COMANDO> [NUMERO_PANEL]\n", argv[0]);

        printf("COMANDO: puede ser 'cci' o 'panel'\n");

        printf("NUMERO_PANEL: el numero de panel debe ser entre 1 y 3; solo es requerido si el comando ingresado es 'panel'\n");

        return 1;
    }

    if (strcmp(argv[1], "cci") == 0) {

        cci();

    } else if (strcmp(argv[1], "panel") == 0) {
        if (argc < 3) {
            printf("Falta el número en el comando 'panel'\n");
            return 1;
        }

        numero = atoi(argv[2]);

        panel(numero);

    } else {
        printf("Comando no reconocido: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
