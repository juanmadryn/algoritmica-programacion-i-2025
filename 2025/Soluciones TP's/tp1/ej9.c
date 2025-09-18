/*Ejercicio 9. Escriba un programa que pregunte la fecha de nacimiento del usuario
  e imprima por pantalla la estación del año (en el hemisferio austral) en que cumple años.
*/

/*
  Enfoque:
  - Leer día, mes y año de nacimiento (el año no afecta el cálculo, pero se pide por consigna).
  - Determinar la estación del año en el hemisferio sur según la fecha del cumpleaños:
      Verano:    21/12  a 20/03
      Otonio:    21/03  a 20/06
      Invierno:  21/06  a 20/09
      Primavera: 21/09  a 20/12
  - Devolver la estación correspondiente.

  Entradas:
  - diaNacimiento (int), mesNacimiento (int), anioNacimiento (int)

  Salida:
  - "Naciste en <ESTACION>"

  Supuestos / notas:
  - No se ajusta por husos horarios ni astronomía fina; se usan fechas convencionales.
  - Para evitar problemas de codificación, se imprime "OTONIO" en lugar de "OTOÑO".
*/

#include <stdio.h>

int main(void) {
    int diaNacimiento, mesNacimiento, anioNacimiento;

    printf("Ingresa tu fecha de nacimiento (DD MM AAAA): ");
    if (scanf("%d %d %d", &diaNacimiento, &mesNacimiento, &anioNacimiento) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    /* Validacion minima */
    if (mesNacimiento < 1 || mesNacimiento > 12 || diaNacimiento < 1 || diaNacimiento > 31) {
        printf("ERROR: ingrese un dia/mes valido.\n");
        return 1;
    }

    if ( (mesNacimiento == 12 && diaNacimiento >= 21) ||
         (mesNacimiento == 1) || (mesNacimiento == 2) ||
         (mesNacimiento == 3 && diaNacimiento <= 20) ) {
        printf("Naciste en VERANO\n");
    } else if ( (mesNacimiento == 3 && diaNacimiento >= 21) ||
                (mesNacimiento == 4) || (mesNacimiento == 5) ||
                (mesNacimiento == 6 && diaNacimiento <= 20) ) {
        printf("Naciste en OTONIO\n");
    } else if ( (mesNacimiento == 6 && diaNacimiento >= 21) ||
                (mesNacimiento == 7) || (mesNacimiento == 8) ||
                (mesNacimiento == 9 && diaNacimiento <= 20) ) {
        printf("Naciste en INVIERNO\n");
    } else {
        /* Resto: 21/09..20/12 */
        printf("Naciste en PRIMAVERA\n");
    }

    return 0;
}
