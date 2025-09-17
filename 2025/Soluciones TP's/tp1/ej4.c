/*Ejercicio 4. Escriba un programa que pida al usuario que ingrese su edad y, si la edad
  es 18 o más, muestre el mensaje "Eres mayor de edad", de lo contrario, muestre
  "No eres mayor de edad". Utiliza una estructura if-then-else para lograr esto.
*/

/*
  Enfoque:
  - Leer la edad como entero.
  - Usar if ... else para decidir el mensaje:
      edad >= 18  → "Eres mayor de edad"
      si no       → "No eres mayor de edad"

  Entradas:
  - edad (int)

  Salidas:
  - "Eres mayor de edad"   (si edad >= 18)
  - "No eres mayor de edad" (si edad < 18)

  Supuestos:
  - La edad se ingresa como número entero no negativo.

*/

#include <stdio.h>

int main(void) {
    int edad;

    printf("Ingrese su edad:\n");

    /* NOTA sobre el '&' en scanf:
       Usamos '&anioNacimiento' para indicar el lugar donde se debe guardar el número leído.
       Por ahora pensalo como un requisito de scanf para poder almacenar el dato dentro de la variable.
       esto no aplica a los arreglos, ya sea de caracteres o no, especial atencion a las "cadenas de caracteres" */
    if (scanf("%d", &edad) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (edad >= 18) {
        printf("Eres mayor de edad\n");
    } else {
        printf("No eres mayor de edad\n");
    }

    return 0;
}
