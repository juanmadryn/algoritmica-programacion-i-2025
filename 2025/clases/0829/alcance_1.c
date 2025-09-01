#include <stdio.h>

void saludar() {
    int edad = 20; // Variable local a esta función
    printf("Hola, tenés %d años\n", edad);
}

int main() {
    saludar();
    // printf("%d", edad); // ERROR: edad no es visible aquí
    return 0;
}
