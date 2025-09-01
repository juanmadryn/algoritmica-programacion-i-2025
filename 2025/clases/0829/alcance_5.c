#include <stdio.h>

int main() {
    int x = 5;

    if (x > 0) {
        int y = 10; // Variable local al bloque del if
        printf("x: %d, y: %d\n", x, y);
    }

    // printf("%d", y); // ERROR: y no es visible fuera del bloque
    return 0;
}
