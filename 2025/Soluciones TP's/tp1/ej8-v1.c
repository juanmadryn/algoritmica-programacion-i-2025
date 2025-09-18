/*Ejercicio 8. Escriba un programa que pregunte la fecha de nacimiento del usuario
  e imprima por pantalla la edad “exacta”. (PS) (PE 03/02/1990)
*/

/*
  Enfoque:
  - Leer la fecha de nacimiento (día, mes, anio) y la fecha actual.
  - Calcular la edad en anios: anioActual - anioNacimiento
    y ajustar -1 si aún no pasó el cumpleaños (comparando mes y día).

  Entradas:
  - diaNacimiento, mesNacimiento, anioNacimiento (int)
  - diaActual, mesActual, anioActual (int)

  Salida:
  - "Tu edad es: <edad> anios"

  Supuestos:
  - Fechas válidas y coherentes (no se valida calendario).
  - “Exacta” en el sentido habitual: considera si ya cumplió años este anio.

  Notas didácticas:
  - En scanf se usa &variable para indicar “la casilla” donde guardar el valor leído.
    (Más adelante verán el porqué; por ahora, es un requisito de scanf).
*/

#include <stdio.h>

int main(void) {
    int diaNacimiento, mesNacimiento, anioNacimiento;
    int diaActual, mesActual, anioActual;
    int edad;

    /* Fecha de nacimiento */
    printf("¿Cual es tu fecha de nacimiento?\n");
    printf("Anio: ");
    scanf("%d", &anioNacimiento);
    printf("Mes (1-12): ");
    scanf("%d", &mesNacimiento);
    printf("Dia: ");
    scanf("%d", &diaNacimiento);

    /* Fecha actual */
    printf("¿Cual es la fecha actual?\n");
    printf("Anio: ");
    scanf("%d", &anioActual);
    printf("Mes (1-12): ");
    scanf("%d", &mesActual);
    printf("Dia: ");
    scanf("%d", &diaActual);

    /* Cálculo base */
    edad = anioActual - anioNacimiento;

    /* Ajuste: si aún no pasó el cumpleaños este anio, restar 1 */
    if (mesNacimiento > mesActual) {
        /* El mes de nacimiento aún no llegó */
        edad = edad - 1;
    } else if (mesNacimiento == mesActual && diaNacimiento > diaActual) {
        /* Es el mismo mes, pero el día de nacimiento aún no llegó */
        edad = edad - 1;
    }

    printf("Tu edad es: %d anios\n", edad);
    return 0;
}
