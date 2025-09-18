/*
  Ejercicio 10. Escriba un programa que permita ingresar un número natural N e imprima
  el factorial de N, es decir N!. (PS) (PE N=5). (ver nota 1 en anexo).

  Enfoque:
  - Leer N (entero natural).
  - Calcular N! iterativamente con un bucle while acumulando el resultado.

  Entradas:
  - N (int, N >= 0)

  Salidas:
  - "El resultado es: <factorial>"

  Supuestos:
  - No se requiere manejar overflow; se mantiene int por simplicidad del TP.

  Validación:
  - Si N < 0, informar que el factorial no está definido para negativos.

  Notas didácticas:
  - En scanf se usa &N para indicar “la casilla” donde guardar el valor leído.

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: N=0 → 1; N=1 → 1; N=5 → 120
  - PE: N=5 → 120
*/

#include <stdio.h>

int main(void) {
    int N, factorial;

    /* Solicitar el dato al usuario */
    printf("Ingrese un numero natural: ");
    if (scanf("%d", &N) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Validación mínima: número natural (N >= 0) */
    if (N < 0) {
        printf("El factorial no esta definido para numeros negativos.\n");
        return 1;
    }

    /* Cálculo iterativo del factorial con while.
       Caso borde: si N == 0, factorial permanece en 1 (por definición 0! = 1). */
    factorial = 1;
    while (N > 0) {
        factorial = factorial * N;  /* multiplicación acumulativa */
        N = N - 1;                  /* preparar la siguiente iteración */
    }

    /* Salida */
    printf("El resultado es: %d\n", factorial);
    return 0;
}
