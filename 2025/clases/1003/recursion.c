#include <stdio.h>

void par(int);
void impar(int);


void impar(int n) {
    if (n > 0) return par(n - 1);
    printf("Impar");    
}
void par(int n) {
    if (n > 0) return impar(n - 1);
    printf("Par");    
}

int main(void) {
    par(6);
    return 0;
}
