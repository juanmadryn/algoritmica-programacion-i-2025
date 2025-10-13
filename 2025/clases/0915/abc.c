#include <stdio.h>
#define MAX 26

int main(){
    char arreglo[MAX-1];

    for(int i = 0; i < MAX; i++){
        arreglo[i] = 'a' + i;
    }

    printf("Arreglo: %s\n", arreglo);
}