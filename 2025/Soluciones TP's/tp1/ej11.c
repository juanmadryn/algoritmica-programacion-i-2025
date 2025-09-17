/*
  Ejercicio 11. Escriba un programa que permita ingresar un número natural N e imprima
  los números primos menores o iguales a N. (PS) (PE N=10). (ver nota 2 en anexo).

  Enfoque:
  - Leer N (entero natural).
  - Para cada número desde N hasta 2, probar si tiene divisor entero entre 2 y (n-1).
  - Si no tiene divisores, imprimirlo (es primo).

  Entradas:
  - N (int, N >= 0)

  Salidas:
  - Secuencia de primos ≤ N (separados por tabulación).

  Supuestos:
  - Se acepta impresión en orden descendente (de N hacia 2), equivalente a ascendente para el propósito del TP.

  Validación:
  - Si N < 2, informar que no hay primos ≤ N.

  Notas didácticas:
  - Se usa una bandera booleana (esPrimo) para cortar la búsqueda al hallar un divisor.
  - Versión intencionalmente simple: prueba de divisores hasta n-1.
    (Optimizable probando hasta √n, pero se mantiene simple por fines pedagógicos.)

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: N=1 → (sin salida); N=2 → 2; N=10 → 10,9,8,7,6,5,4,3,2 → imprime 7,5,3,2
  - PE: N=10 → 7	5	3	2
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int limite, numero, divisor, resto;
    bool esPrimo;

    /* Entrada */
    printf("Ingrese un numero natural: ");
    if (scanf("%d", &limite) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (limite < 2) {
        printf("No hay numeros primos menores o iguales a %d.\n", limite);
        return 0;
    }

    /* Recorre desde N hacia 2 e imprime los primos (orden descendente) */
    for (numero = limite; numero > 1; numero--) {
        esPrimo = true;
        divisor = numero - 1;                 /* candidato a divisor */

        /* Mientras no se haya encontrado divisor y queden divisores por probar */
        while (esPrimo == true && divisor > 1) {
            resto = numero % divisor;
            if (resto == 0) {
                esPrimo = false;              /* tiene divisor: no es primo */
            }
            divisor = divisor - 1;            /* siguiente divisor */
        }

        if (esPrimo == true) {
            printf("%d\t", numero);
        }
    }

    printf("\n");
    return 0;
}
