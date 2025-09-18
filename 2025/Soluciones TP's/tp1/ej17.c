/*
  Ejercicio 17. Escriba un programa que permita ingresar un número natural N e imprima
  los N primeros términos de la serie de Fibonacci.  (PE N=10) (ver nota 4 en anexo).

  Enfoque:
  - Leer N (entero natural).
  - Manejar casos base: N=1 y N=2.
  - Para N>=3, iterar acumulando cada término como suma de los dos anteriores.

  Entradas:
  - N (int, N >= 1)

  Salidas:
  - Los N términos de la serie (iniciando en 1, 1), separados por espacios y con salto de línea final.

  Supuestos:
  - Se usa la convención Fibonacci que inicia en 1, 1 (no 0, 1).

  Validación:
  - Si N < 1, informar que se requiere un natural positivo y finalizar.

  Notas didácticas:
  - No se usan arreglos; se guardan solo los dos términos previos (memoria O(1)).
  - Para N grandes, el resultado desborda int; opcionalmente usar 'long long' y '%lld'.

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: N=1 → 1
  - PS: N=2 → 1 1
  - PE: N=10 → 1 1 2 3 5 8 13 21 34 55
*/

#include <stdio.h>

int main(void) {
    int N;
    int f, fmenos1 = 1, fmenos2 = 1;

    /* Entrada */
    printf("Ingrese el numero de terminos: ");
    if (scanf("%d", &N) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }
    if (N < 1) {
        printf("Se requiere un numero natural (N >= 1).\n");
        return 0;
    }

    /* Salidas según casos base */
    if (N == 1) {
        printf("1\n");
        return 0;
    }

    /* N >= 2: imprimir los dos primeros y continuar */
    printf("1 1");
    for (int i = 3; i <= N; i++) {
        f = fmenos1 + fmenos2;  /* término actual = suma de los dos anteriores */
        fmenos2 = fmenos1;      /* avanzar ventana: el anterior-2 pasa a anterior-1 */
        fmenos1 = f;            /* el actual pasa a ser el nuevo anterior-1 */
        printf(" %d", f);
    }
    printf("\n");

    return 0;
}
