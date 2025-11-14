#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10
#define MAX_LEN 64
#define TOTAL_PERSONAS 30

typedef struct Persona {
    int dni;
    char nombre[MAX_LEN];
    char apellido[MAX_LEN];
    struct Persona* siguiente;
} Persona;

Persona* tabla[HASH_SIZE] = {NULL};
int colisiones = 0;

int hash(int dni) {
    int h = dni % HASH_SIZE;
    return h;
}

void insertar(int dni, const char* nombre, const char* apellido) {
    int idx = hash(dni);

    Persona* actual = tabla[idx];
    while (actual) {
        if (actual->dni == dni) {
            strncpy(actual->nombre, nombre, MAX_LEN);
            strncpy(actual->apellido, apellido, MAX_LEN);
            return;
        }
        actual = actual->siguiente;
    }

    if (tabla[idx]) colisiones++;

    Persona* nueva = malloc(sizeof(Persona));
    nueva->dni = dni;
    strncpy(nueva->nombre, nombre, MAX_LEN);
    strncpy(nueva->apellido, apellido, MAX_LEN);
    nueva->siguiente = tabla[idx];
    tabla[idx] = nueva;
}

Persona* buscar(int dni) {
    int idx = hash(dni);
    Persona* actual = tabla[idx];
    while (actual) {
        if (actual->dni == dni) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}

void mostrarTabla() {
    printf("\n--- Tabla de Hash (Personas) ---\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("[%2d]: ", i);
        Persona* p = tabla[i];
        while (p) {
            printf("(%d → %s %s) ", p->dni, p->nombre, p->apellido);
            p = p->siguiente;
        }
        printf("\n");
    }
}

void cargarPersonas() {
    for (int i = 0; i < TOTAL_PERSONAS; i++) {
        int dni = 10000001 + i;
        char nombre[MAX_LEN], apellido[MAX_LEN];
        snprintf(nombre, MAX_LEN, "Nombre%d", i + 1);
        snprintf(apellido, MAX_LEN, "Apellido%d", i + 1);
        insertar(dni, nombre, apellido);
    }
}

int main() {
    cargarPersonas();
    mostrarTabla();

    printf("\n== Búsqueda ==\n");
    int dniBuscado;
    printf("Ingrese DNI a buscar: ");
    scanf("%d", &dniBuscado);

    Persona* p = buscar(dniBuscado);
    if (p)
        printf("[RESULTADO] Persona encontrada: %s %s (DNI %d)\n", p->nombre, p->apellido, p->dni);
    else
        printf("[RESULTADO] DNI %d no encontrado.\n", dniBuscado);

    printf("\n== Estadísticas ==\n");
    printf("Colisiones totales: %d\n", colisiones);

    return 0;
}
