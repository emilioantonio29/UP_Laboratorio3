#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include "../headers/globals.h"
#include "../headers/key.h"
#include "../headers/semaforo.h"
#include "../headers/randomNumbers.h"

int main() {
    while (1) { // Bucle while infinito
        int numero;
        int numeroPanel;
        char cadena[100]; // Aquí se almacenará la cadena, se asume un máximo de 100 caracteres
        int id_semaforo;
        FILE *productor; 


        // Solicitar un número al usuario
        printf("Ingresa un número (o 0 para salir): ");
        scanf("%d", &numero);

        if (numero == 0) {
            // Salir del bucle si el usuario ingresa 0
            printf("Saliendo del programa...\n");
            break;
        }

        if (numero == 1) {


            	id_semaforo =  creo_semaforo();
	            inicia_semaforo(id_semaforo, VERDE);
                espera_semaforo(id_semaforo);
                espera_semaforo(id_semaforo);
                    
                    // productor = fopen("panel.dat", "a");
                    // if (productor!=NULL)
                    // {
                    //     fprintf(productor, "panel1.dat\n");
                    //     for (nro_producto=0; nro_producto<cantidadDepositos; nro_producto++)
                    //     {
                    //         deposito = generarDeposito();
                    //         tipoDeposito = generarTipoDeposito();
                    //         printf("REGISTRO: %d %d\n", deposito, tipoDeposito);
                    //         fprintf(productor, "%d %d\n", deposito, tipoDeposito);
                    //         usleep(1000*1000);
                    //     }
                    //     fclose(productor);
                    //     nro_partida++;
                    //     printf("\nTERMINO LA PRODUCCION DE CAJERO 1\n");
                    // }
                    // else
                    // {
                    //     perror ("Error al abrir panel1.dat");
                    // }
                    
                levanta_semaforo(id_semaforo);



        } else if(numero == 2) {

            printf("Ingresa un numero de panel: ");
            scanf("%d", &numeroPanel);
            // while (numeroPanel < 1 && numeroPanel > 3)
            // {
                
            //     printf("Ingresa un numero de panel: ");
            //     scanf("%d", &numeroPanel);

            //     if(numeroPanel < 1 && numeroPanel > 3){
            //         printf("Por favor ingresa un numero de panel valido, 1, 2 o 3");
            //     }

            // }
            
            // Si el número es igual a dos, solicitar una cadena al usuario
            printf("Ingresa una cadena de caracteres: ");
            scanf(" %[^\n]", cadena); // Usamos %[^\n] para leer toda la línea como una cadena
            printf("La cadena ingresada es: %s\n", cadena);

        } else {
            printf("Opcion invalida. Presiona 1 para leer el panel, 2 para escribir en el panel o 0 para salir.\n");
        }
    }

    return 0;
}

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

/*
int main()
{
    int deposito;
    int tipoDeposito;
    int cantidadDepositos = generarIteracion();

	char cadena[CADENA_LARGO];
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
*/
