#include <stdio.h>

void contarLlamadas() {
    static int llamadas = 0; // Se mantiene entre llamadas
    llamadas++;
    printf("Llamada número %d\n", llamadas);
}

int main() {
    contarLlamadas(); // 1
    contarLlamadas(); // 2
    contarLlamadas(); // 3
    return 0;
}
