/*Ejercicio 6. Modifica el ejercicio 5 para que utilice un ciclo do while en lugar de un ciclo while.
  ¿Cuál es la diferencia?
*/

/*
  Enfoque:
  - Leer un entero positivo (limite).
  - Usar un bucle do ... while para imprimir 1, 2, ..., limite.

  Entradas:
  - limite (int) >= 1

  Salidas:
  - Secuencia 1, 2, ..., limite (cada numero en su propia linea)

  Supuestos:
  - "Numero natural" se interpreta como entero positivo.

  Notas didacticas:
  - En do ... while el cuerpo se ejecuta al menos una vez (condicion al final).
*/

#include <stdio.h>

int main(void) {
    int limite, contador = 1;

    printf("Ingrese un numero natural: ");
    if (scanf("%d", &limite) != 1 || limite < 1) {
        printf("Entrada invalida (se requiere entero positivo).\n");
        return 1;
    }

    /* do ... while: ejecuta primero, verifica despues */
    do {
        printf("%d\n", contador);
        contador++;
    } while (contador <= limite);

    return 0;
}
