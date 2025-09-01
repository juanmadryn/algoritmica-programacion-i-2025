#include <stdio.h>

int main() {
    int entero = 5;
    float decimal = 2.5;
    
    float resultado = entero + decimal;

    printf("entero = %d\n", entero);
    printf("decimal = %.2f\n", decimal);
    printf("resultado (entero + decimal) = %.2f\n", resultado);

    int resultado_int = entero + decimal;
    printf("resultado entero (entero + decimal) = %d\n", resultado_int);

    return 0;
}
