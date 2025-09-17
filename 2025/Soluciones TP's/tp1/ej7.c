/*Ejercicio 7. Modifica el ejercicio 6 para que utilice un ciclo for. ¿Cuál es la diferencia?*/

/*
  Enfoque:
  - Leer un entero positivo (limite).
  - Usar un bucle for para imprimir 1, 2, ..., limite.

  Entradas:
  - limite (int) >= 1

  Salidas:
  - Secuencia 1, 2, ..., limite (cada numero en su propia linea)

  Supuestos:
  - "Numero natural" se interpreta como entero positivo.

  Notas didacticas:
  - for(inicio; condicion; actualizacion) concentra en la cabecera lo que,
    con while, suele escribirse en 3 lugares (antes, dentro y al final del bucle).
  - Igual que while, si la condicion es falsa al comienzo, el cuerpo NO se ejecuta.
  - A diferencia de do...while, for/while pueden no ejecutar ninguna vez.
*/

#include <stdio.h>

int main(void) {
    int limite, contador;

    printf("Ingrese un numero natural: ");
    if (scanf("%d", &limite) != 1 || limite < 1) {
        printf("Entrada invalida (se requiere entero positivo).\n");
        return 1;
    }

    for (contador = 1; contador <= limite; contador++) {
        printf("%d\n", contador);
    }

    return 0;
}
