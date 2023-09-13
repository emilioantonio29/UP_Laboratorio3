#include <stdio.h>
#include <stdio.h>
#include "../headers/control.h"


void escribirPaneles() {
    FILE *archivo;

    // Abrir el archivo en modo escritura ("w")
    archivo = fopen("panel.txt", "w");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Escribir en el archivo las líneas deseadas
    fprintf(archivo, "panel1\n");
    fprintf(archivo, "panel2\n");
    fprintf(archivo, "panel3\n");

    // Cerrar el archivo
    fclose(archivo);

    printf("El archivo 'panel.txt' ha sido creado y escrito exitosamente.\n");
}

void sobreescribirLinea(FILE *archivo, int linea, const char *mensaje) {
    // Posicionar el puntero en la línea deseada
    fseek(archivo, 0, SEEK_SET);
    for (int i = 1; i < linea; i++) {
        while (fgetc(archivo) != '\n');
    }

    // Sobrescribir la línea con el nuevo mensaje
    fprintf(archivo, "%s\n", mensaje);
}



/*
#include <stdlib.h>
#include <time.h>
#include "../headers/globals.h"
#include "../headers/randomNumbers.h"

int generarDeposito() {
    //La función srand(time(NULL)) en C se utiliza para inicializar la semilla del generador de números aleatorios (rand()) con un valor que cambia con el tiempo
    srand(time(NULL));

    // Genera un número aleatorio entre 0 y 400, luego suma 100 para obtener un rango entre 100 y 500
    int numero = rand() % HASTA + SUMA_CIEN;

    return numero;
}

int generarTipoDeposito() {
    //La función srand(time(NULL)) en C se utiliza para inicializar la semilla del generador de números aleatorios (rand()) con un valor que cambia con el tiempo
    srand(time(NULL));

    // Genera un número aleatorio 0 o 1
    int numero = rand() % 2;

    return numero;
}

int generarIteracion() {
    // Inicializa la semilla para la generación de números aleatorios
    srand(time(NULL));

    // Genera un número aleatorio entre 0 y 10, luego suma 10 para obtener un rango entre 10 y 20
    int numero = rand() % HASTA_FOR + SUMA_FOR;

    return numero;
}
*/