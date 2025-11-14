// libros.h
#ifndef LIBROS_H
#define LIBROS_H

#define MAX_LIBROS 1000
#define HASH_SIZE 100

typedef struct Libro {
    int producto_id;
    int tipo_parte_libro_id;
    int pais_edicion_id;
    char editorial[128];
    char isbn[32];
    char titulo[256];
    int pagina_inicial;
    int pagina_final;
    struct Libro* next;
} Libro;

extern Libro* tablaHash[HASH_SIZE];

void insertarLibro(Libro* libro);
Libro* buscarLibro(const char* clave);
void eliminarLibro(const char* clave);
void importarCSV(const char* path);
void exportarCSV(const char* path);
void menu();

#endif
