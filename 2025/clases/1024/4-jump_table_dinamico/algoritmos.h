// se agrega ifndef (si no está definido) para evitar inclusiones múltiples de la cabecera
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// Definición de estructura
typedef struct {
    const char* name;
    void (*sort_func)(int*, int);
} SortAlgorithm;

// Declaración del arreglo y su tamaño
extern SortAlgorithm sort_algorithms[];
extern const int num_algorithms;

#endif