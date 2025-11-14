// libros.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "util.h"

Libro* tablaHash[HASH_SIZE] = {NULL};

int hash(const char* clave) {
    int h = 0;
    while (*clave) h = (h * 31 + tolower(*clave++)) % HASH_SIZE;
    return h;
}

void insertarLibro(Libro* libro) {
    int idx = hash(libro->isbn);
    libro->next = tablaHash[idx];
    tablaHash[idx] = libro;
}

Libro* buscarLibro(const char* clave) {
    int idx = hash(clave);
    Libro* aux = tablaHash[idx];
    while (aux) {
        if (strcmp(aux->isbn, clave) == 0 || strcasecmp(aux->titulo, clave) == 0) return aux;
        aux = aux->next;
    }
    return NULL;
}

void eliminarLibro(const char* clave) {
    int idx = hash(clave);
    Libro* actual = tablaHash[idx];
    Libro* anterior = NULL;
    while (actual) {
        if (strcmp(actual->isbn, clave) == 0 || strcasecmp(actual->titulo, clave) == 0) {
            if (anterior) anterior->next = actual->next;
            else tablaHash[idx] = actual->next;
            free(actual);
            printf("Libro eliminado.\n");
            return;
        }
        anterior = actual;
        actual = actual->next;
    }
    printf("Libro no encontrado.\n");
}

void importarCSV(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) { perror("No se pudo abrir el archivo"); return; }
    char linea[1024];
    fgets(linea, 1024, f); // encabezado

    while (fgets(linea, 1024, f)) {
        Libro* libro = malloc(sizeof(Libro));
        memset(libro, 0, sizeof(Libro));

        sscanf(linea, "%d;%d;%d;%127[^;];%31[^;];%255[^;];%d;%d",
               &libro->producto_id, &libro->tipo_parte_libro_id,
               &libro->pais_edicion_id, libro->editorial,
               libro->isbn, libro->titulo,
               &libro->pagina_inicial, &libro->pagina_final);

        insertarLibro(libro);
    }
    fclose(f);
    printf("Importación finalizada.\n");
}

void exportarCSV(const char* path) {
    FILE* f = fopen(path, "w");
    if (!f) return;
    fprintf(f, "producto_id;tipo_parte_libro_id;pais_edicion_id;editorial;isbn;titulo_libro;pagina_inicial;pagina_final\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        Libro* l = tablaHash[i];
        while (l) {
            fprintf(f, "%d;%d;%d;%s;%s;%s;%d;%d\n",
                    l->producto_id, l->tipo_parte_libro_id, l->pais_edicion_id,
                    l->editorial, l->isbn, l->titulo,
                    l->pagina_inicial, l->pagina_final);
            l = l->next;
        }
    }
    fclose(f);
    printf("Exportación finalizada.\n");
}

void guardarLibrosBinario(const char* path) {
    FILE* f = fopen(path, "wb");
    if (!f) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        Libro* l = tablaHash[i];
        while (l) {
            fwrite(l, sizeof(Libro), 1, f);
            l = l->next;
        }
    }
    fclose(f);
    printf("Base de datos binaria guardada.\n");
}

void cargarLibrosBinario(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return;
    while (!feof(f)) {
        Libro* libro = malloc(sizeof(Libro));
        if (fread(libro, sizeof(Libro), 1, f) == 1) {
            libro->next = NULL;
            insertarLibro(libro);
        } else {
            free(libro);
        }
    }
    fclose(f);
    printf("Base de datos binaria cargada.\n");
}

void agregarLibroInteractivo() {
    Libro* libro = malloc(sizeof(Libro));
    memset(libro, 0, sizeof(Libro));

    printf("Producto ID: "); scanf("%d", &libro->producto_id); getchar();
    printf("Tipo parte libro ID: "); scanf("%d", &libro->tipo_parte_libro_id); getchar();
    printf("Pais edición ID: "); scanf("%d", &libro->pais_edicion_id); getchar();
    printf("Editorial: "); fgets(libro->editorial, 128, stdin); limpiarCadena(libro->editorial);
    printf("ISBN: "); fgets(libro->isbn, 32, stdin); limpiarCadena(libro->isbn);
    printf("Título: "); fgets(libro->titulo, 256, stdin); limpiarCadena(libro->titulo);
    printf("Página inicial: "); scanf("%d", &libro->pagina_inicial); getchar();
    printf("Página final: "); scanf("%d", &libro->pagina_final); getchar();

    insertarLibro(libro);
    printf("Libro agregado.\n");
}

void menu() {
    int opcion;
    char entrada[256];
    do {
        printf("\n1. Importar CSV\n2. Buscar libro\n3. Agregar libro\n4. Borrar libro\n5. Exportar CSV\n6. Cargar binario\n7. Guardar binario\n0. Salir\n> ");
        scanf("%d", &opcion); getchar();

        switch(opcion) {
            case 1:
                printf("Ruta CSV: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                importarCSV(entrada);
                break;
            case 2:
                printf("Título o ISBN: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                Libro* l = buscarLibro(entrada);
                if (l) printf("%s (%s) - %s\n", l->titulo, l->isbn, l->editorial);
                else printf("No encontrado.\n");
                break;
            case 3:
                agregarLibroInteractivo();
                break;
            case 4:
                printf("Título o ISBN a borrar: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                eliminarLibro(entrada);
                break;
            case 5:
                printf("Ruta destino CSV: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                exportarCSV(entrada);
                break;
            case 6:
                printf("Ruta binario: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                cargarLibrosBinario(entrada);
                break;
            case 7:
                printf("Ruta binario: "); fgets(entrada, 255, stdin); limpiarCadena(entrada);
                guardarLibrosBinario(entrada);
                break;
        }
    } while (opcion != 0);
}