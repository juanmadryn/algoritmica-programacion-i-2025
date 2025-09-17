/*Ejercicio 5. Escribe un programa que pida al usuario que ingrese un número y luego
  cuente desde 1 hasta ese número, mostrando cada número en pantalla. Utiliza una
  estructura while para lograr esto.*/

/*
  Enfoque:
  - Leer un entero positivo (N).
  - Usar un bucle while para imprimir 1, 2, ..., N.

  Entradas:
  - Limite (int) ≥ 1

  Salida:
  - Secuencia numérica en líneas consecutivas: 1, 2, ..., Limite

  Supuestos:
  - Se considera “número natural” como entero positivo.

*/

#include <stdio.h>

int main(void) {
    int limite, contador = 1;

    printf("Ingrese un numero natural: ");
    
    if (scanf("%d", &limite) != 1) {
        printf("Entrada invalida (se requiere entero positivo).\n");
        return 1;
    }

    if (limite < 1) {
        printf("Entrada invalida (se requiere entero positivo).\n");
        return 1;
    }

    /* Las lineas anteriores podrian unificarse en:
        if (scanf("%d", &limite) != 1 || limite < 1) {
        printf("Entrada invalida (se requiere entero positivo).\n");
        return 1;
    }
    */

    while (contador <= limite) {
        printf("%d\n", contador);
        contador++;   /* equivalente a: contador = contador + 1 */
    }

    return 0;
}
