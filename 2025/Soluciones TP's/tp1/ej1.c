/*
  Ejercicio 1
  Consigna: Escriba un programa que imprima en la terminal la cadena de texto "Hola mundo".

  Enfoque:
  - Usar la función estándar printf (stdio.h) para enviar texto a la salida estándar (pantalla por defecto).
  - Finalizar la línea con '\n' por buena práctica.

  Salida esperada (exacta): Hola mundo
*/

#include <stdio.h>   /* Biblioteca estándar de E/S: printf, puts, etc. */

/* Punto de entrada del programa (función principal). 
   Retorna 0 si el programa finaliza correctamente. */
int main(void) {
    /* Imprime exactamente la cadena pedida seguida de un salto de línea. */
    printf("Hola mundo\n");

    return 0;
}
