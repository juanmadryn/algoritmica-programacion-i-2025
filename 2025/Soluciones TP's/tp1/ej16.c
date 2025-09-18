/*Ejercicio 16. Escriba un programa que permita ingresar una letra L e imprima todas la letras del abecedario en orden alfabético inverso desde z (o Z) hasta L. Tenga en cuenta si el usuario ingresó una letra minúscula o mayúscula. (ver nota 3 en anexo).
*/

/*
  Enfoque:
  - Leer un carácter (letra).
  - Si es 'A'..'Z', imprimir desde 'Z' hacia la letra (inclusive).
  - Si es 'a'..'z', imprimir desde 'z' hacia la letra (inclusive).
  - Si no es letra ASCII, informar error.

  Entradas:
  - letra (char)

  Salidas:
  - Secuencia de letras en orden inverso, respetando la capitalización de la entrada.

  Supuestos:
  - Se trabaja con el alfabeto básico ASCII ('A'..'Z' y 'a'..'z'); no se contempla 'Ñ/ñ'.

  Validación:
  - Si el carácter no pertenece a 'A'..'Z' ni 'a'..'z', se imprime un mensaje de error.

  Notas didácticas:
  - Se usan literales de carácter ('A','Z','a','z') en vez de códigos numéricos (65,90,97,122) para mejorar legibilidad.
  - En scanf se antepone un espacio en " %c" para consumir whitespace pendiente (incluye '\n' de entradas previas).

  Pruebas sugeridas (PS) / Prueba de ejemplo (PE):
  - PS: L='M'  → Z Y X W V U T S R Q P O N M
  - PS: L='x'  → z y x
  - PE: L='A'  → Z Y X ... B A
*/

#include <stdio.h>

int main(void) {
    char letra;

    printf("Ingrese una letra: ");
    /* El espacio antes de %c descarta saltos de línea u otros espacios previos */
    if (scanf(" %c", &letra) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Mayúsculas: 'A'..'Z' */
    if (letra >= 'A' && letra <= 'Z') {
        for (char c = 'Z'; c >= letra; c = c - 1) {
            printf("%c ", c);
        }
        printf("\n");
    }
    /* Minúsculas: 'a'..'z' */
    else if (letra >= 'a' && letra <= 'z') {
        for (char c = 'z'; c >= letra; c = c - 1) {
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
