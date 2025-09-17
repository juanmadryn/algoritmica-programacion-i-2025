/*Ejercicio 8. Escriba un programa que pregunte la fecha de nacimiento del usuario
  e imprima por pantalla la edad “exacta”. (PS) (PE 03/02/1990)
*/

/*
  Enfoque:
  - Leer la fecha de nacimiento y la fecha actual con un único scanf por fecha (formato dd/mm/aaaa).
  - Calcular diferencias base por componente (anios, meses, dias).
  - Ajustar con “prestamos”: si dias < 0, sumar 30 y restar 1 mes; si meses < 0, sumar 12 y restar 1 anio.

  Entradas:
  - Fecha de nacimiento: dd/mm/aaaa
  - Fecha actual:        dd/mm/aaaa

  Salida:
  - "Su edad es: <anios> anios, <meses> meses y <dias> dias"

  Supuestos / Limitaciones:
  - Simplificacion didactica: se asume "30 dias por mes" para el ajuste.
  - No se validan fechas reales (28/29/30/31 ni anios bisiestos).
  - Se asume que las fechas ingresadas son validas y coherentes.
*/

#include <stdio.h>

int main(void) {
    int diaNacimiento, mesNacimiento, anioNacimiento;   /* fecha de nacimiento */
    int diaActual, mesActual, anioActual;               /* fecha actual */
    int edadAnios, edadMeses, edadDias;                 /* resultado */

    /* Leer fechas con un unico scanf por fecha (tres variables) */
    printf("Ingrese su fecha de nacimiento (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &diaNacimiento, &mesNacimiento, &anioNacimiento);

    printf("Ingrese la fecha actual (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &diaActual, &mesActual, &anioActual); /*- En el formato " %d/%d/%d" el espacio inicial descarta restos de salto de linea previos.*/

    /* Diferencias base por componente */
    edadAnios  = anioActual - anioNacimiento;
    edadMeses  = mesActual  - mesNacimiento;
    edadDias   = diaActual  - diaNacimiento;

    /* Ajuste de dias: si quedo negativo, “pido prestado” 1 mes (=30 dias en esta simplificacion) */
    if (edadDias < 0) {
        edadDias  += 30;   /* asumimos 30 dias/mes */
        edadMeses -= 1;
    }

    /* Ajuste de meses: si quedo negativo, “pido prestado” 1 anio (=12 meses) */
    if (edadMeses < 0) {
        edadMeses += 12;
        edadAnios -= 1;
    }

    printf("Su edad es: %d anios, %d meses y %d dias\n",
           edadAnios, edadMeses, edadDias);

    return 0;
}
