#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "../headers/control.h"
#include "../headers/globals.h"

void escribirPaneles() {
    FILE *archivo;

    // Abrir el archivo en modo escritura ("w")
    archivo = fopen(NOMBRE_TEXTO, "w");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Escribir en el archivo las líneas deseadas
    fprintf(archivo, "panel1\n");
    fprintf(archivo, "panel2\n");
    fprintf(archivo, "panel3");

    // Cerrar el archivo
    fclose(archivo);

    printf("El archivo 'panel.txt' ha sido creado y escrito exitosamente.\n");
}

void leerArchivo(char *array[]) {
    int i; 
    FILE *archivo;
    archivo = fopen(NOMBRE_TEXTO, "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    for (i = 0; i < 3; i++) {
        if (fgets(array[i], MAX_LINE_LENGTH, archivo) == NULL) {
            break; // Salir si no hay más líneas en el archivo
        }
        // Eliminar el salto de línea al final de cada línea
        array[i][strcspn(array[i], "\n")] = '\0';
    }

    fclose(archivo);
}

void reemplazarTexto(char *array[], int posicion, const char *texto) {
    if (posicion >= 0 && posicion < 3) {
        strcpy(array[posicion], texto);
    } else {
        printf("Posición no válida. Debe ser 0, 1 o 2.\n");
    }
}

void escribirArchivo(char *array[]) {
    int i; 

    FILE *archivo;
    archivo = fopen(NOMBRE_TEXTO, "w");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    for (i = 0; i < 3; i++) {
        fprintf(archivo, "%s\n", array[i]);
    }

    fclose(archivo);

    printf("El archivo 'panel.txt' ha sido actualizado con éxito.\n");
}
