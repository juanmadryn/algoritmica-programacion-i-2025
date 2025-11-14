#include <stdio.h>

// Codifica un número de 4 bits como código Hamming(7,4)
int hamming74_encode(int data) {
    int d1 = (data >> 3) & 1;
    int d2 = (data >> 2) & 1;
    int d3 = (data >> 1) & 1;
    int d4 = (data >> 0) & 1;

    int p1 = d1 ^ d2 ^ d4;
    int p2 = d1 ^ d3 ^ d4;
    int p3 = d2 ^ d3 ^ d4;

    // Estructura: p1 p2 d1 p3 d2 d3 d4 (bits 6 a 0)
    int encoded = 0;
    encoded |= (p1 << 6);
    encoded |= (p2 << 5);
    encoded |= (d1 << 4);
    encoded |= (p3 << 3);
    encoded |= (d2 << 2);
    encoded |= (d3 << 1);
    encoded |= (d4 << 0);

    return encoded;
}

// Decodifica el código Hamming(7,4) y corrige un error de 1 bit si existe
int hamming74_decode(int code) {
    int p1 = (code >> 6) & 1;
    int p2 = (code >> 5) & 1;
    int d1 = (code >> 4) & 1;
    int p3 = (code >> 3) & 1;
    int d2 = (code >> 2) & 1;
    int d3 = (code >> 1) & 1;
    int d4 = (code >> 0) & 1;

    // Síndromes de paridad
    int s1 = p1 ^ d1 ^ d2 ^ d4;
    int s2 = p2 ^ d1 ^ d3 ^ d4;
    int s3 = p3 ^ d2 ^ d3 ^ d4;

    int error_pos = s1 * 1 + s2 * 2 + s3 * 4;

    if (error_pos) {
        printf("⚠️  Error en bit %d. Corrigiendo...\n", error_pos);
        code ^= 1 << (7 - error_pos);  // Corrige el bit invertido
    } else {
        printf("Sin errores detectados.\n");
    }

    // Extraer los bits de datos corregidos
    d1 = (code >> 4) & 1;
    d2 = (code >> 2) & 1;
    d3 = (code >> 1) & 1;
    d4 = (code >> 0) & 1;

    return (d1 << 3) | (d2 << 2) | (d3 << 1) | d4;
}

// Imprime los bits de un entero (solo los primeros n bits)
void print_bits(int val, int bits) {
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (val >> i) & 1);
}

int main() {
    int valor;
    printf("Ingrese un número entre 0 y 15: ");
    scanf("%d", &valor);

    if (valor < 0 || valor > 15) {
        printf("Entrada inválida. Debe estar entre 0 y 15.\n");
        return 1;
    }

    int codificado = hamming74_encode(valor);

    printf("\n Código Hamming(7,4): ");
    print_bits(codificado, 7);
    printf(" (hex: %02X)\n", codificado);

    // Simular error: invertir 1 bit
    int bit_error = 2; // posición 3 (1-based)
    codificado ^= 1 << (7 - bit_error); // cambiar bit en posición 3
    printf("🔧 Código con error simulado en bit %d: ", bit_error);
    print_bits(codificado, 7);
    printf("\n");

    int decodificado = hamming74_decode(codificado);

    printf("Valor decodificado: %d (bin: ", decodificado);
    print_bits(decodificado, 4);
    printf(")\n");

    return 0;
}
