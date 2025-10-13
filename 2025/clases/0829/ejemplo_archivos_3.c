#include <stdio.h>

struct Persona {
    char nombre[30];
    int edad;
	char dni[10];
	char estado;
};

int main() {
    struct Persona personas[2] = {
        {"Lucía", 28, "48102031", 'V'},
        {"Matías", 34, "48102032", 'I'}
    };

    FILE *archivo = fopen("personas.dat", "ab");
    if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	//printf("Se abrió correctamente el archivo para escribir.\n");

    fwrite(personas, sizeof(struct Persona), 2, archivo);
    
	fclose(archivo);
	//printf("Se cerró correctamente el archivo.\n");
    // Leer de nuevo
    archivo = fopen("personas.dat", "rb");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	//printf("Se abrió correctamente el archivo para leer.\n");
    struct Persona persona;
    while (fread(&persona, sizeof(struct Persona), 1, archivo)) {
		if(persona.estado=='V')
			printf("Nombre: %s, Edad: %d, DNI: %s\n", persona.nombre, persona.edad, persona.dni);
    }

    fclose(archivo);
	//printf("Se cerró correctamente el archivo.\n");
    return 0;
}
