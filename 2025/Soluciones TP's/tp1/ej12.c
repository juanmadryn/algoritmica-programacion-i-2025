/*
  Ejercicio 12. Escriba un programa que permita ingresar un número natural N y otro número
  natural M, e imprima el resultado de N multiplicado por M calculándolo como sumas sucesivas.

  Enfoque:
  - Leer N y M (enteros naturales, N >= 0, M >= 0).
  - Calcular N * M sumando N repetidamente M veces (suma sucesiva).

  Entradas:
  - N (int, N >= 0)
  - M (int, M >= 0)

  Salidas:
  - "Resultado: <valor>"

  Supuestos:
  - Se usa tipo int; no se maneja overflow para valores grandes.

  Validación:
  - Si N < 0 o M < 0, informar que deben ser naturales (no negativos) y finalizar.

  Notas didácticas:
  - En scanf se usa &variable para indicar la “casilla” donde guardar el valor leído.
  - Variante posible (no implementada): para menos iteraciones, sumar el mayor repetidamente
    la menor cantidad de veces. Aquí se mantiene la versión simple y directa.

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: N=0, M=10 -> 0
  - PS: N=7, M=0  -> 0
  - PE: N=3, M=4  -> 12
*/

#include <stdio.h>

int main(void) {
    int N, M;
    int resultado = 0;


    /* Entrada de datos */
    printf("Ingrese N (numero natural): ");
    if (scanf("%d", &N) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }
    printf("Ingrese M (numero natural): ");
    if (scanf("%d", &M) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Validacion minima */
    if (N < 0 || M < 0) {
        printf("N y M deben ser numeros naturales (no negativos).\n");
        return 1;
    }

    /* Sumas sucesivas con for: sumar N exactamente M veces */
    for (int contador = 0; contador < M; contador++) {
        resultado = resultado + N;
    }

    printf("Resultado: %d\n", resultado);
    return 0;
}
