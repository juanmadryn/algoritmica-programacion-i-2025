#include <stdio.h>

int string_length(char string[]) {
    if(string[0] == '\0') return 0;
    return string_length(&string[1]) + 1;
}

int main() {
    char * string = "Hola mundo";
    int length = string_length(string);
    printf("El tamaño del string es: %d\n", length);
    return 0;
}