/*Ejercicio 3. Escriba un programa que pregunte el año de nacimiento del usuario e imprima por pantalla la edad aproximada.
*/

/*
  Enfoque:
  - Leer dos enteros: año de nacimiento y año actual.
  - Calcular edad aproximada como anioActual - anioNacimiento (sin considerar mes/día).
  - Imprimir la edad.

  Entradas:
  - anioNacimiento (int)
  - anioActual (int)

  Salida:
  - "Tu edad aproximada es: <edad> anios"

  Supuestos:
  - Se ignora el mes y el día, por eso se habla de “aproximada”.

*/

#include <stdio.h>

int main(void) {
    int anioNacimiento, anioActual;

    printf("¿Cuál es tu anio de nacimiento?\n");
    
    /* NOTA sobre el '&' en scanf:
       Usamos '&anioNacimiento' para indicar el lugar donde se debe guardar el número leído.
       Por ahora pensalo como un requisito de scanf para poder almacenar el dato dentro de la variable.
       esto no aplica a los arreglos, ya sea de caracteres o no, especial atencion a las "cadenas de caracteres" */
    if (scanf("%d", &anioNacimiento) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("¿Cuál es el anio actual?\n");
    if (scanf("%d", &anioActual) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (anioNacimiento > anioActual) {
        printf("Los datos no son coherentes (naciste despues del anio actual).\n");
        return 1;
    }

    /* Declaración e inicialización en la misma línea:
       acá se crea la variable 'edad' y al mismo tiempo se le asigna el valor calculado. */
    int edad = anioActual - anioNacimiento;

    printf("Tu edad aproximada es: %d anios\n", edad);
    return 0;
}

