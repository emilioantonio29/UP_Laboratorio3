#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>
#include "./headers/globals.h"
#include "./headers/key.h"
#include "./headers/semaforo.h"
#include "./headers/file.h"
#include "./headers/cci.h"

int cci() {

    int numero;
    int numeroPanel;
    int id_semaforo;
    int i; 
    char *array[3];
    int posicion;

    id_semaforo =  creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
    espera_semaforo(id_semaforo);

    escribirPaneles();

    levanta_semaforo(id_semaforo);

    while (1) { // Bucle while infinito

        // Solicitar un número al usuario
        printf("Ingresa un número (o 0 para salir): ");
        scanf("%d", &numero);

        if (numero == 0) {
            // Salir del bucle si el usuario ingresa 0
            printf("Saliendo del programa...\n");
            break;
        }

        if (numero == 1) {

            printf("Ingresa un numero de panel: ");
            scanf("%d", &numeroPanel);
            printf("El panel seleccionado es: %d\n", numeroPanel);

            while (numeroPanel < 1 || numeroPanel > 3)
            {
                printf("Numero de panel Invalido. Ingresa 1, 2 o 3\n");
                printf("Ingresa un numero de panel: ");
                scanf("%d", &numeroPanel);
                printf("El panel seleccionado es: %d\n", numeroPanel);
            }

            espera_semaforo(id_semaforo);

            for (i = 0; i < 3; i++) {
                array[i] = (char *)malloc(MAX_LINE_LENGTH);
            }

            leerArchivo(array);

            printf("CONTENIDO DEL PANEL %d\n", numeroPanel);

            printf("%s\n", array[numeroPanel-1]);

            // Liberar la memoria asignada
            for (i = 0; i < 3; i++) {
                free(array[i]);
            }

            levanta_semaforo(id_semaforo);

        } else if(numero == 2) {

            printf("Ingresa un numero de panel: ");
            scanf("%d", &numeroPanel);
            printf("El panel seleccionado es: %d\n", numeroPanel);

            while (numeroPanel < 1 || numeroPanel > 3)
            {
                printf("Numero de panel Invalido. Ingresa 1, 2 o 3\n");
                printf("Ingresa un numero de panel: ");
                scanf("%d", &numeroPanel);
                printf("El panel seleccionado es: %d\n", numeroPanel);
            }
            
            // printf("Ingresa una cadena de caracteres para el panel seleccionado: ");
            // scanf(" %[^\n]", cadena); // Usamos %[^\n] para leer toda la línea como una cadena

            // id_semaforo =  creo_semaforo();
            espera_semaforo(id_semaforo);

            for (i = 0; i < 3; i++) {
                array[i] = (char *)malloc(MAX_LINE_LENGTH);
            }

            leerArchivo(array);

            // Mostrar el contenido original
            printf("Contenido original:\n");
            for (i = 0; i < 3; i++) {
                printf("%d: %s\n", i, array[i]);
            }

            posicion = numeroPanel-1;

            printf("Ingresa el nuevo texto: ");
            getchar(); // Consumir el salto de línea pendiente
            fgets(array[posicion], MAX_LINE_LENGTH, stdin);
            // Eliminar el salto de línea al final del nuevo texto
            array[posicion][strcspn(array[posicion], "\n")] = '\0';

            // Mostrar el contenido actualizado
            printf("Contenido actualizado:\n");
            for (i = 0; i < 3; i++) {
                printf("%d: %s\n", i, array[i]);
            }

            escribirArchivo(array);

            // Liberar la memoria asignada
            for (i = 0; i < 3; i++) {
                free(array[i]);
            }

            levanta_semaforo(id_semaforo);

        } else {
            printf("Opcion invalida. Presiona 1 para leer el panel, 2 para escribir en el panel o 0 para salir.\n");
        }
    }

    return 0;
}
