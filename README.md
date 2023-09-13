# UNIVERSIDAD DE PALERMO | Laboratorio III

## C TrafficLight Program

## Compile instructions

```bash
gcc -o NAMEYOURFILE ./src/main.c ./src/greeting.c
```

## Compile instructions - Makefile
```bash
make
```

## Ejercicio 

Un BANCO posee 3 cajeros y un tesorero. Cada cajero y el tesorero están representados por un proceso independiente: 
- CAJERO1
- CAJERO2
- CAJERO3
- TESORERO.

- a) CAJEROS
Cada cajero genera un lote propio con los depósitos recibidos con los siguientes datos: 

cajero1.dat 
IMPORTE (importe del depósito ALEATORIO de $100 a $500.-)
CHEQUE (si es cheque (0) o efectivo (1) ALEATORIO).

Cada lote puede tener N depósitos (ALEATORIO de 10 a 20). 

###Ejemplo:
cajero1.dat     cajero2.dat     cajero3.dat
100 0           100 0           103 1
403 0           402 0           120 0
202 1           432 1
302 2

Si el archivo no existe, se deberá crear (cajero1.dat, cajero2.data, cajero3.dat en cada proceso). Si existe, agregar los depósitos en el mismo archivo al final.

- b) TESORERO
El tesorero tiene que ir procesando los lotes de depósitos de uno. Al finalizar cada lote, deberá actualizar el total de depósitos (cantidad e importes) y un resumen por cajero.

###Ejemplo:
TOTAL
TC-EFEC     T$-EFEC     TC-CHEQ     T$-CHEQ
10          $100        5           $1025

CAJERO1
TC-EFEC     T$-EFEC     TC-CHEQ     T$-CHEQ
2           $50         1           $1000

CAJERO2
TC-EFEC     T$-EFEC     TC-CHEQ     T$-CHEQ
3           $20         2           $20

CAJERO3
TC-EFEC     T$-EFEC     TC-CHEQ     T$-CHEQ
5           $30         2           $5

Cada lote procesado deberá ser renombrado como cajero1.999.dat (donde 999 indica el número secuencial de lote por cada cajero).

###Importante:

- La solución debe estar desarrollada en 4 procesos comunicados por medio de 3 archivos de lotes (cajero1.dat, cajero2.dat, cajero3.dat) y utilizando semáforos.
- Los procesos de CAJEROS deben funcionar en forma automática simulando a cada cajero en forma ALEATORIA (1, 2, 3), con una espera ALEATORIA entre 1000ms y  2500ms.
- TESORERO posee un bucle que controla si hay nuevos lotes cada 500ms.

###Notas:

- El programa debe estar INDENTADO CORRECTAMENTE. 
- Utilizar DEFINE para constantes.
