#ifndef _SEMAFORO
#define _SEMAFORO
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int creo_semaforo();

void inicia_semaforo(int id_semaforo, int valor);

void levanta_semaforo(int id_semaforo);

void espera_semaforo(int id_semaforo);

#endif