#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Constantes
#define MAX_PALABRAS 1000
#define MAX_LONGITUD_PALABRA 30
#define MAX_LONGITUD_ORACION 256

int main() {
    char diccionario[MAX_PALABRAS][MAX_LONGITUD_PALABRA];
    int cantidad_palabras_diccionario = 0;

    char oracion[MAX_LONGITUD_ORACION];
    char *palabra_actual;

    int indice_diccionario;
    int palabra_encontrada;
    char respuesta_usuario;

    printf("=== Verificador de palabras con diccionario ===\n");

    while (1) {
        printf("\nIngrese una oración (o 'fin' para terminar): ");
        fgets(oracion, sizeof(oracion), stdin);

        int longitud_oracion = strlen(oracion);
        if (longitud_oracion > 0 && oracion[longitud_oracion - 1] == '\n') {
            oracion[longitud_oracion - 1] = '\0';
        }

        if (strcmp(oracion, "fin") == 0) {
            break;
        }

        palabra_actual = strtok(oracion, " ,");
        while (palabra_actual != NULL) {
            palabra_encontrada = false;

            for (indice_diccionario = 0; 
                !palabra_encontrada 
                    && indice_diccionario < cantidad_palabras_diccionario; 
                indice_diccionario++) {
                if (strcmp(diccionario[indice_diccionario], palabra_actual) == 0) {
                    palabra_encontrada = true;
                }
            }

            if (!palabra_encontrada) {
                printf("Palabra desconocida: '%s'\n", palabra_actual);
                printf("¿Desea agregarla al diccionario? (s/n): ");
                scanf(" %c", &respuesta_usuario);
                getchar();

                if (respuesta_usuario == 's' || respuesta_usuario == 'S') {
                    if (cantidad_palabras_diccionario < MAX_PALABRAS) {
                        strncpy(diccionario[cantidad_palabras_diccionario], palabra_actual, MAX_LONGITUD_PALABRA - 1);
                        diccionario[cantidad_palabras_diccionario][MAX_LONGITUD_PALABRA - 1] = '\0';
                        cantidad_palabras_diccionario++;
                        printf("Palabra '%s' agregada al diccionario.\n", palabra_actual);
                    } else {
                        printf("No se puede agregar más palabras. Diccionario lleno.\n");
                    }
                }
            }

            palabra_actual = strtok(NULL, " ,");
        }
    }

    printf("\n=== Diccionario final (%d palabras) ===\n", cantidad_palabras_diccionario);
    for (indice_diccionario = 0; indice_diccionario < cantidad_palabras_diccionario; indice_diccionario++) {
        printf("%s\n", diccionario[indice_diccionario]);
    }

    return 0;
}
