/*
  Ejercicio 13. Escriba un programa que permita ingresar un número natural N y otro número
  natural M, e imprima el resultado de N elevado a la M calculándolo como sumas sucesivas.

  Enfoque:
  - Leer N y M (enteros naturales).
  - Calcular N^M SIN usar el operador '*':
      * Reutiliza la idea del Ejercicio 12: multiplicación por sumas sucesivas.
      * Para la potencia, repetir M veces la operación "resultado = resultado * N",
        donde esa multiplicación se implementa como N sumas de 'resultado'.

  Entradas:
  - N (int, N >= 0)
  - M (int, M >= 0)

  Salidas:
  - "Resultado: <valor>"

  Supuestos:
  - Convención: 0^0 se toma como 1.
  - No se maneja overflow; se usa long long para ampliar un poco el rango.

  Validación:
  - Si N < 0 o M < 0, informar que deben ser naturales (no negativos) y finalizar.

  Notas didácticas:
  - NO se usa el operador '*'. La multiplicación se emula con sumas sucesivas.
  - Bucle externo (M veces) para la potencia; bucle interno (N sumas) para la multiplicación.

  Complejidad:
  - Tiempo: O(M * N)
  - Memoria: O(1)

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: N=0, M=5 -> 0
  - PS: N=5, M=0 -> 1
  - PS: N=2, M=3 -> 8
  - PE: N=3, M=4 -> 81
*/

#include <stdio.h>

int main(void) {
    int N, M;

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

    if (N < 0 || M < 0) {
        printf("N y M deben ser numeros naturales (no negativos).\n");
        return 1;
    }

    /* Potencia por sumas sucesivas */
    /* Caso base: cualquier numero a la 0 vale 1; 0^0 se toma 1 por convencion. */
    long long resultado = 1;

    for (int exp = 0; exp < M; exp = exp + 1) {
        /* Reutiliza la idea del Ejercicio 12: multiplicacion por sumas sucesivas.
           Queremos: resultado = resultado * N, sin '*'.
           Lo logramos sumando 'resultado' exactamente N veces. */
        long long acumulado = 0;
        for (int contador = 0; contador < N; contador++) {
            acumulado = acumulado + resultado;
        }
        resultado = acumulado;
    }

    printf("Resultado: %lld\n", resultado);
    /*%11d es un especificador de formato de printf:
    %d → imprime un entero con signo en base 10.
    11 → ancho mínimo de campo: ocupa al menos 11 caracteres.
    Si el número tiene menos dígitos, se rellena con espacios a la izquierda (queda alineado a la derecha).
    Si el número tiene más de 11 dígitos, no se trunca: se imprime completo.*/

    return 0;
}
