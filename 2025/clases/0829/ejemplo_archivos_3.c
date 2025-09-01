#include <stdio.h>

struct Persona {
    char nombre[30];
    int edad;
};

int main() {
    struct Persona personas[2] = {
        {"Lucía", 28},
        {"Matías", 34}
    };

    FILE *archivo = fopen("personas.dat", "wb");
    if (archivo == NULL) return 1;

    fwrite(personas, sizeof(struct Persona), 2, archivo);
    fclose(archivo);

    // Leer de nuevo
    archivo = fopen("personas.dat", "rb");
    struct Persona p;
    while (fread(&p, sizeof(struct Persona), 1, archivo)) {
        printf("Nombre: %s, Edad: %d\n", p.nombre, p.edad);
    }

    fclose(archivo);
    return 0;
}
