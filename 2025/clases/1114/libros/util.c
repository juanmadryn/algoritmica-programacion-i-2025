// util.c
#include <ctype.h>
#include <string.h>
#include "util.h"

void limpiarCadena(char* str) {
    str[strcspn(str, "\n")] = '\0';
}