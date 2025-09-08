#include <stdio.h>
#include <string.h>

int main() {
    char clave[20];
    char secreto[20] = "secreto";

    printf("Ingrese la clave: ");
    scanf("%s", clave);

    if (strcmp(clave, secreto) == 0) {
        printf("¡Acceso concedido!\n");
    } else {
        printf("Clave incorrecta.\n");
    }
    return 0;
}
