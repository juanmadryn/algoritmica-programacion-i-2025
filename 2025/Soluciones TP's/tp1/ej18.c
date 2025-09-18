/*
  Ejercicio 18. Escriba un programa que permita ingresar un número entero N e indique
  si el número es capicúa. (ver nota 5 en anexo).

  Enfoque:
  - Leer N (entero).
  - Construir el número invertido tomando dígitos de N de derecha a izquierda:
      resto = N % 10
      invertido = invertido * 10 + resto
      N = N / 10
  - Comparar el invertido con el original.

  Entradas:
  - N (int)

  Salidas:
  - "<N> es capicua" o "<N> NO es capicua"

  Supuestos:
  - Consideramos capicúa sólo para enteros no negativos. Para este EJ, los negativos se
    informan como “NO es capicúa”. (Alternativa didáctica: tomar |N| y comparar sobre el absoluto.)

  Validación:
  - Si la lectura falla, se informa "Entrada invalida".

  Notas didácticas:
  - El algoritmo de inversión es iterativo y usa sólo divisiones y módulos por 10.
  - Para valores muy grandes puede haber overflow al construir el número invertido en 'int'.

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: 0  → capicúa
  - PS: 7  → capicúa
  - PS: 10 → NO capicúa
  - PE: 1221 → capicúa
*/

#include <stdio.h>

int main(void) {
    int N;

    printf("Ingrese un numero entero: ");
    if (scanf("%d", &N) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Negativos: para este TP, se consideran NO capicua */
    if (N < 0) {
        printf("%d NO es capicua\n", N);
        return 0;
    }

    /* Preservamos el original y trabajamos sobre una copia */
    int original = N;
    int invertido = 0;

    /* Caso N=0: el while no ejecuta y queda invertido=0 → 0 es capicua */
    while (N > 0) {
        int resto = N % 10;                /* último dígito */
        invertido = invertido * 10 + resto;/* lo agregamos a la derecha */
        N = N / 10;                        /* quitamos el último dígito */
    }

    if (original == invertido) {
        printf("%d es capicua\n", original);
    } else {
        printf("%d NO es capicua\n", original);
    }

    return 0;
}
