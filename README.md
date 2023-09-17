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

## Test1 | PANEL CCI

1) ingresar a la ruta /control y ejecutar ./main para arrancar el programa. Se cumplen con las consignas solicitadas.

- Al arrancar el programa se crea un archivo panel.txt. con un texto en 3 filas diferentes. Cada fila representa un panel.
- El programa le solicita un numero, si el numero no es 1 o 2, informa que el numero debe ser 1 o 2.
- Ingresando el numero 0 termina el programa.
- El numero 1 accede al modo lectura; despues de presionarlo, se le pide al usuario un numero de panel que debe ser entre 1 y 3. Hasta que no ingresa un numero entre 1 y 3 no avanza al siguiente paso. El numero ingresado corresponde a un numero de panel, posteriormente, el programa imprime por consola el texto correspondiente al panel ingresado, que se encuentra en el panel.txt.
- EL numero 2 accede al modo escritura; se le solicita al usuario un numero de panel que debe estar entre 1 y 3; posterior a esto, se le pide un texto que sera guardado en el numero de panel ingresado.


2) ingresar a la ruta /panel y ejecutar ./main y un numero que debe estar entre 1 y 3.

- Si no se pasa el argumento el programa informa que debe arrancarse con un numero que debe estar entre 1 y 3.
- De acuerdo al numero ingresado, el programa lee el panel correspondiente en el archivo panel.txt. Cada 100 milisegundos revisa el archivo y actualiza la informacion en caso de detectar cambios.

