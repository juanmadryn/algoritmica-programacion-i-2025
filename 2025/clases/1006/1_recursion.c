#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool es_palindromo(char string[], int length) {
    if(length == 0 || length == 1) return true;
    if(tolower(string[0]) != tolower(string[length - 1])){
        return false;
    }
    return es_palindromo(&string[1], length - 2);
}

int main(int argc, char *argv[]) {
    char * string = "mennem";
    int string_len = strlen(string);
    if(es_palindromo(string, string_len)) {
        printf("Es palindromo\n");
    } else {
        printf("No es palindromo\n");
    }
    return 0;
}