#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    printf("La palabra tiene %lu letras.\n", strlen(palabra));
    return 0;
}
