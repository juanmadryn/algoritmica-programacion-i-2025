#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    int len = strlen(palabra);

    printf("Invertida: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", palabra[i]);
    }
    printf("\n");
    return 0;
}
