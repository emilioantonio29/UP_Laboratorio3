#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include "../headers/globals.h"
#include "../headers/key.h"
#include "../headers/semaforo.h"
#include "../headers/randomNumbers.h"

/*
int main()
{

    int numero = generarDeposito();
    printf("Número aleatorio entre 100 y 500: %d\n", numero);

    int numero2 = generarTipoDeposito();
    printf("Número aleatorio entre 0 y 1: %d\n", numero2);

    int numero3 = generarIteracion();
    printf("Número aleatorio entre 10 y 20: %d\n", numero3);
  
   //int i;
   int id_semaforo;
   id_semaforo = creo_semaforo();


   inicia_semaforo(id_semaforo, VERDE);

   while(1)
   {
       espera_semaforo(id_semaforo);
       printf("Seccion critica\n");
       sleep (1);
       levanta_semaforo(id_semaforo);
       sleep (10);
   }


   return 0;
}

*/

int main()
{
    int deposito;
    int tipoDeposito;
    int cantidadDepositos = generarIteracion();

	char cadena[CADENA_LARGO]; /* Un array lo suficientemente grande como para guardar la linea mas larga del fichero */
	int nro_producto=0, nro_partida=0;
	FILE *productor; 

	int id_semaforo;
	
	id_semaforo =  creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
	
    espera_semaforo(id_semaforo);
        
        productor = fopen("cajero1.dat", "a");
        if (productor!=NULL)
        {
            deposito = generarDeposito();
            tipoDeposito = generarTipoDeposito();
            fprintf(productor, "cajero1.dat\n");
            for (nro_producto=0; nro_producto<cantidadDepositos; nro_producto++)
            {
                deposito = generarDeposito();
                tipoDeposito = generarTipoDeposito();
                printf("REGISTRO: %d %d\n", deposito, tipoDeposito);
                fprintf(productor, "%d %d\n", deposito, tipoDeposito);
                usleep(1000*1000);
            }
            fclose(productor);
            nro_partida++;
            printf("\nTERMINO LA PRODUCCION DE CAJERO 1\n");
        }
        else
        {
            perror ("Error al abrir cajero1.dat");
        }
        
    levanta_semaforo(id_semaforo);
    usleep(100*1000);

	return 0;
}
