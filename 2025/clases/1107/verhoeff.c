#include <stdio.h>
#include <string.h>

int d[10][10] = {
    {0,1,2,3,4,5,6,7,8,9},
    {1,2,3,4,0,6,7,8,9,5},
    {2,3,4,0,1,7,8,9,5,6},
    {3,4,0,1,2,8,9,5,6,7},
    {4,0,1,2,3,9,5,6,7,8},
    {5,9,8,7,6,0,4,3,2,1},
    {6,5,9,8,7,1,0,4,3,2},
    {7,6,5,9,8,2,1,0,4,3},
    {8,7,6,5,9,3,2,1,0,4},
    {9,8,7,6,5,4,3,2,1,0}
};

int p[8][10] = {
    {0,1,2,3,4,5,6,7,8,9},
    {1,5,7,6,2,8,3,0,9,4},
    {5,8,0,3,7,9,6,1,4,2},
    {8,9,1,6,0,4,3,5,2,7},
    {9,4,5,3,1,2,6,8,7,0},
    {4,2,8,6,5,7,3,9,0,1},
    {2,7,9,3,8,0,6,4,1,5},
    {7,0,4,6,9,1,3,2,5,8}
};

int inv[10] = {0,4,3,2,1,5,6,7,8,9};

// Calcula el dígito verificador Verhoeff para un número (como string)
int verhoeff_calcular(const char *numero) {
    int c = 0;
    int len = strlen(numero);
    for (int i = 0; i < len; i++) {
        int digit = numero[len - i - 1] - '0';
        c = d[c][p[i % 8][digit]];
    }
    return inv[c];
}

// Verifica si un número con dígito Verhoeff es válido
int verhoeff_verificar(const char *numero) {
    int c = 0;
    int len = strlen(numero);
    for (int i = 0; i < len; i++) {
        int digit = numero[len - i - 1] - '0';
        c = d[c][p[i % 8][digit]];
    }
    return (c == 0);
}

// Ejemplo de uso
int main() {
    char base[100];
    printf("Ingrese un número (sin dígito verificador): ");
    scanf("%s", base);

    int dv = verhoeff_calcular(base);
    printf("Dígito verificador: %d\n", dv);

    char completo[101];
    snprintf(completo, sizeof(completo), "%s%d", base, dv);

    printf("Número completo: %s\n", completo);

    // Verificación
    if (verhoeff_verificar(completo)) {
        printf("Verificación exitosa.\n");
    } else {
        printf("Número inválido.\n");
    }

    return 0;
}
