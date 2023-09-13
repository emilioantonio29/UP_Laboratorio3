#include <stdio.h>
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
