/*Ejercicio 8. Escriba un programa que pregunte la fecha de nacimiento del usuario
  e imprima por pantalla la edad “exacta”. (PS) (PE 03/02/1990)
*/

/*
  Enfoque:
  - Leer cada fecha con un único scanf (dd/mm/aaaa).
  - Convertir cada fecha a "días absolutos" con el modelo didáctico: anio*365 + mes*30 + dia.
  - Restar: diferencia = totalActual - totalNacimiento.
  - Reconvertir a anios/meses/dias con divisiones y restos (365 y 30).

  Entradas:  fecha de nacimiento (dd/mm/aaaa), fecha actual (dd/mm/aaaa)
  Salida:    "Su edad es: <anios> anios, <meses> meses y <dias> dias"
  Supuestos: simplificación didáctica (1 anio = 365 dias, 1 mes = 30 dias).
*/

#include <stdio.h>

int main(void) {
    int diaNacimiento, mesNacimiento, anioNacimiento;   /* fecha de nacimiento */
    int diaActual, mesActual, anioActual;               /* fecha actual */
    int edadAnios, edadMeses, edadDias;                 /* resultado */

    printf("Ingrese su fecha de nacimiento (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &diaNacimiento, &mesNacimiento, &anioNacimiento);

    printf("Ingrese la fecha actual (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &diaActual, &mesActual, &anioActual);

    /* Paso 1: convertir cada fecha a dias (modelo 365/30).
       - Usamos 'long' en los calculos para reforzar el tipo y evitar cualquier riesgo
         de desbordamiento cuando se multiplican anios/meses por constantes.
       - (long)anioNacimiento es un cast: "convierte" la variable a 'long' ANTES de multiplicar.
       - 365L y 30L son literales de tipo 'long' (la 'L' lo indica). Esto fuerza que la
         multiplicacion se realice en 'long'. 
       - Se agregan parentesis explicitos para mejorar la lectura, aun cuando la precedencia
         de operadores (*) sobre (+) ya lo garantice.
    */
    long totalNacimiento = ( ((long)anioNacimiento * 365L)
                           + ((long)mesNacimiento  * 30L)
                           + ((long)diaNacimiento) );

    long totalActual     = ( ((long)anioActual     * 365L)
                           + ((long)mesActual      * 30L)
                           + ((long)diaActual) );

    if (totalActual < totalNacimiento) {
        printf("Fechas incoherentes (la fecha actual es anterior a la de nacimiento).\n");
        return 1;
    }

    /* Paso 2: diferencia total en dias */
    long diferencia = (totalActual - totalNacimiento);

    /* Paso 3: reconversion a anios/meses/dias (modelo 365/30) */
    edadAnios = (int)((diferencia / 365L));
    diferencia = (diferencia % 365L); /*El resto de los anios son los dis que no entran en el anio*/

    edadMeses = (int)((diferencia / 30L));
    edadDias  = (int)((diferencia % 30L));/*Ahora el resto son los dias que no entran en el mes*/

    printf("Su edad es: %d anios, %d meses y %d dias\n",
           edadAnios, edadMeses, edadDias);

    return 0;
}
