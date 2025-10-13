#include <stdio.h>

int producto(int a, int b) {
    if(b == 0) return 0;
    return a + producto(a, b - 1);
}

int main() {
    int a = 5;
    int b = 3;
    int result = producto(a, b);
    printf("El producto de %d y %d es: %d\n", a, b, result);
    return 0;
}