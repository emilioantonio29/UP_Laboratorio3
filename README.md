# UNIVERSIDAD DE PALERMO | Laboratorio III

## C TrafficLight Program

## Compile instructions - Makefile
```bash
make
```

## Test2 | PANEL CCI

El programa debe iniciar pasando dos argumentos; el primero es un comando que puede ser 'cci' o 'panel'; si el comando ingresado es 'panel', debe agregarse un segundo argumento que debe ser un numero entre 1 y 3, que representa el numero de panel.

1) modo cci

- Al arrancar el programa se crea un archivo panel.txt. con un texto en 3 filas diferentes. Cada fila representa un panel.
- El programa le solicita un numero, si el numero no es 1 o 2, informa que el numero debe ser 1 o 2.
- Ingresando el numero 0 termina el programa.
- El numero 1 accede al modo lectura; despues de presionarlo, se le pide al usuario un numero de panel que debe ser entre 1 y 3. Hasta que no ingresa un numero entre 1 y 3 no avanza al siguiente paso. El numero ingresado corresponde a un numero de panel, posteriormente, el programa imprime por consola el texto correspondiente al panel ingresado, que se encuentra en el panel.txt.
- EL numero 2 accede al modo escritura; se le solicita al usuario un numero de panel que debe estar entre 1 y 3; posterior a esto, se le pide un texto que sera guardado en el numero de panel ingresado.


2) modo panel

- De acuerdo al numero ingresado, el programa lee el panel correspondiente en el archivo panel.txt. Cada 100 milisegundos revisa el archivo y actualiza la informacion en caso de detectar cambios.

