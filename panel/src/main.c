#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/globals.h"
#include "../headers/key.h"
#include "../headers/semaforo.h"
#include "../headers/control.h"

int main(int argc, char *argv[]) {
    int numero;
    int i; 
    int id_semaforo;
    char cadena1[101];    
    char cadena2[101];
    char *array[3];
    int firstRound = 1;    

    // Verificar si se proporciona un argumento (número)
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    // Convertir el argumento en un número entero
    numero = atoi(argv[1]);

    // Verificar si el número está en el rango de 1 a 3
    if (numero < 1 || numero > 3) {
        printf("Al iniciar el programa, ingresa un numero de panel que se encuentre entre 1 y 3.\n");
        return 1;
    }

    id_semaforo =  creo_semaforo();
    inicia_semaforo(id_semaforo, VERDE);

    // Bucle while con espera de 100 milisegundos
    while (1) {

        espera_semaforo(id_semaforo);

        for (i = 0; i < 3; i++) {
            array[i] = (char *)malloc(MAX_LINE_LENGTH);
        }

        leerArchivo(array);

        if(firstRound == 1){

            strcpy(cadena1, array[numero-1]);
            strcpy(cadena2, array[numero-1]);

            
            printf("PANEL %d", numero);
            printf("********************\n");
            printf("%s\n", cadena1);
            printf("********************+++++++\n");


        }else{

            strcpy(cadena2, array[numero-1]);

            if(strcmp(cadena1, cadena2) == 0){

                // NO IMPRIME

            }else{

                strcpy(cadena1, array[numero-1]);
                printf("CAMBIO EL PANEL\n");

                printf("PANEL %d", numero);
                printf("********************\n");
                printf("%s\n", cadena1);
                printf("********************+++++++\n");

            }
            

        }

        levanta_semaforo(id_semaforo);

        firstRound = 0;

        usleep(100000); // Espera de 100 milisegundos (100000 microsegundos)

    }

    levanta_semaforo(id_semaforo);

    return 0;
}
