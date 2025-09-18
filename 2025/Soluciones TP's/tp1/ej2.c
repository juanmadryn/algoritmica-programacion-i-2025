/*
  Ejercicio 2
  Consigna: Imprimir "¿Cuál es tu nombre?", leer el nombre por teclado y luego
            imprimir "Hola <nombre>".
*/

#include <stdio.h>

int main(void) {
    char nombre[100];  /* buffer para el nombre (hasta 99 chars + '\0') */

    printf("¿Cuál es tu nombre?\n");

    /* Lee hasta 99 caracteres o hasta el salto de línea, lo que ocurra primero.
       - El espacio inicial en el formato consume espacios/blancos previos.
       - Excluye '\n' residual, el [^\n] es un "scanset": acepta cualquier carácter salvo '\n'. */
    if (scanf(" %99[^\n]", nombre) != 1) {
        /* Si falla la lectura, dejamos nombre vacío para no imprimir basura. */
        nombre[0] = '\0';
    }

    printf("Hola %s\n", nombre);
    return 0;
}

