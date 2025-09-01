#include <stdio.h>

int main() {
    int entero = 7;
    int divisor = 2;

    float resultado_implicito = entero / divisor;
    float resultado_explicito = (float)entero / divisor;

    printf("Resultado sin casting: %f\n", resultado_implicito);
    printf("Resultado con casting: %f\n", resultado_explicito);

    return 0;
}
