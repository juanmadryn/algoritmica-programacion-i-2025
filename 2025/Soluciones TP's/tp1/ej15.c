/*
  Ejercicio 15. Escriba un programa que permita ingresar una letra L e imprima todas la letras del abecedario en orden alfabético desde la letra a ( o A) hasta L. Tenga en cuenta si el usuario ingresó una letra minúscula o mayúscula. (ver nota 3 en anexo).

  Enfoque:
  - Leer un carácter (letra).
  - Si es 'A'..'Z', imprimir desde 'A' hasta esa letra.
  - Si es 'a'..'z', imprimir desde 'a' hasta esa letra.
  - Si no es una letra del alfabeto inglés, informar error.

  Entradas:
  - letra (char)

  Salidas:
  - Secuencia de letras desde 'A' o 'a' hasta la letra ingresada (misma capitalización).

  Supuestos:
  - Se trabaja con el alfabeto básico ASCII ('A'..'Z' y 'a'..'z'); no se contempla 'Ñ/ñ'.

  Validación:
  - Si el carácter no es letra ASCII, se imprime mensaje de error.

  Notas didácticas:
  - Se usan literales de carácter ('A', 'Z', 'a', 'z') en lugar de códigos numéricos (65, 90, 97, 122),
    lo que mejora la legibilidad sin cambiar la lógica.
  - En scanf se antepone un espacio en " %c" para consumir posibles saltos de línea previos.

  Complejidad:
  - Tiempo: O(|L - 'A'|) u O(|L - 'a'|) según el caso.
  - Memoria: O(1)

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: entrada 'D' → A B C D
  - PS: entrada 'g' → a b c d e f g
  - PE: entrada 'A' → A
*/

#include <stdio.h>

int main(void) {
    char letra;

    printf("Ingrese una letra: ");
    /* El espacio antes de %c hace que se salte cualquier whitespace pendiente (incluye '\n'). */
    if (scanf(" %c", &letra) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Mayusculas: 'A'..'Z' */
    if (letra >= 'A' && letra <= 'Z') {
        for (char c = 'A'; c <= letra; c = c + 1) {
            printf("%c ", c);
        }
        printf("\n");
    }
    /* Minusculas: 'a'..'z' */
    else if (letra >= 'a' && letra <= 'z') {
        for (char c = 'a'; c <= letra; c = c + 1) {
            printf("%c ", c);
        }
        printf("\n");
    }
    /* No es una letra ASCII */
    else {
        printf("El caracter ingresado no es una letra valida del alfabeto ASCII.\n");
    }

    return 0;
}
