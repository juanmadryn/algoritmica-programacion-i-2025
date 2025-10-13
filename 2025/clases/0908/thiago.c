#include <stdio.h>

#include <ctype.h>

#include <string.h>

#include <stdbool.h>

#define MAXLEN 1000
#define MAXCHAR 30

int menu();
int crearOracion();
int verDiccionario();
int salir();
char *_verificarExistenciasDePalabras(char *, char[][MAXCHAR]);
int _ejecutar_opcion(int);

int inicio_cadena = 0;

// cadena de oraciones
char cadena[MAXLEN][MAXCHAR] = {
    {"default"},
};

// type PunteroAFuncion es un puntero a funciones que devuelven un entero y no tienen parametros
typedef int (*PunteroAFuncion)(void);
// diccionario de opciones del tipo PunteroAFuncion que contiene las funciones principales
PunteroAFuncion dict_opciones_globales[] = {
    crearOracion,
    verDiccionario,
    salir,
};
// Todas las claves (opciones) que referencian a funciones o metodos.
int keys[] = {1, 2, 3};

// sirve de contador para saber cuantas oraciones tiene el array de oraciones
int count = 1;

int main()
{
    menu();
    return 0;
}

// le pide al usuario que ingrese una oracion y puede guardarla o no en la cadena de oraciones segun lo que quiera el usuario, retorna 1
int crearOracion()
{
    char oracion[MAXCHAR];
    printf("Ingrese la oracion a continuacion:\n");
    fgets(oracion, MAXCHAR, stdin);
    size_t len = strlen(oracion);
    if (len > 0 && oracion[len - 1] == '\n')
    {
        oracion[len - 1] = '\0';
    }

    printf("oracion: %s", oracion);                                                    // prueba
    char *ptr_palabras_encontradas = _verificarExistenciasDePalabras(oracion, cadena); // por aca hay problemas
    if (&ptr_palabras_encontradas == NULL)
    {
        printf("\n\n");
        return 1;
    }
    char palabras_encontradas[MAXLEN];
    strcpy(palabras_encontradas, ptr_palabras_encontradas);
    int dim = sizeof(*palabras_encontradas) / (sizeof(palabras_encontradas[0]));
    for (int i = 0; i < dim; i++)
    {
        printf("Se ha encontrado la palabra: %s\nDesea agregarla al diccionario? S/N", palabras_encontradas[i]);
        char option;
        option = tolower(fgetc(stdin));
        while (getchar() != '\n')
            ; // supuestamente limpia el buffer
        if (option != 's' && option != 'n' || option == 'n')
        {
            printf("\nLa palabra se ha borrado exitosamente.\n");
            continue;
        }
        strcpy(cadena[count], oracion);
        cadena[count][MAXCHAR - 1] = '\0';
        printf("\nLa palabra fue agregada con exito.");
        count++;
    }
    return true;
}
// muestra el diccionario completo por pantalla, retorna 1
int verDiccionario()

{
    printf("\nTu diccionario:\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d) ", (i + 1));
        for (int j = 0; j < MAXCHAR; j++)
        {
            printf("%c", cadena[i][j]);
        }
        printf("\n\n");
    }
    printf("Apreta Enter para volver.");
    while (getchar() != '\n')
        ; // limpia buffer
    return true;
}
// pregunta si quiere terminar el programa, si si, retorna 0, si no retorna 1
int salir()
{
    char option;
    printf("Esta seguro que quiere salir del programa? S/N: ");
    option = fgetc(stdin);
    while (getchar() != '\n')
        ; // limpia buffer
    option = tolower(option);
    if (option == 's')
    {
        printf("\nfin");
        return false;
    }
    if (option == 'n')
    {
        return 1;
    }
    printf("\nIngresaste un carácter inválido, volviendo al menu.\n");
    return true;
}
// Menu principal, administra las distintas operaciones permitidas del programa
int menu()
{
    int seguir = true;
    int option = 0;
    while (seguir)
    {
        printf("\n---Selecciona una opcion---\n");
        printf("1.Crear Oracion\n2.Ver todas las oraciones\n3.Salir\n--> ");

        int option = fgetc(stdin);
        option = option - '0'; // convierte de (ejemplo) '1' a 1.
        while (getchar() != '\n')
            ; // limpia buffer
        if (option < 1 || option > 3)
        {
            printf("\nIngresaste un valor invalido.\n");
            continue;
        }
        seguir = _ejecutar_opcion(option);
    }
}
// pide un puntero a oracion, y una cadena de oraciones. Verifica si existe una o mas palabras de la oracion en las palabras almacenadas dentro del diccionario.
// retorna NULL si no encontro palabras nuevas. Si las encontró, las devuelve en un array. Es la idea
char *_verificarExistenciasDePalabras(char *oracion, char cadena[][MAXCHAR]) // aca hay fallas
{
    char *result[][MAXCHAR] = {""};
    // Buffer temporal
    char temp_oracion[MAXCHAR];
    // Para cada oración en la cadena
    for (int i = 0; i < count; i++)
    {
        // Reset de la oración a verificar para cada palabra de la cadena
        strcpy(temp_oracion, oracion);
        temp_oracion[MAXCHAR - 1] = '\0'; //'\n' -> '\0'
        char *palabra_de_oracion = strtok(temp_oracion, " ");

        while (palabra_de_oracion != NULL)
        {
            if (strcmp(cadena[i], palabra_de_oracion) == 0) // ignora las repetidas
            {
                i--;
                continue;
            }
            strcpy(result[i][inicio_cadena], palabra_de_oracion);
            result[i][MAXCHAR] = '\0';
            palabra_de_oracion = strtok(NULL, " ");
        }
    }
    if (result[inicio_cadena][inicio_cadena] == "") // Todas las palabras de la oracion existen en la cadena
    {
        return NULL; // null si todas las palabras existen en el diccionario
    }
    return *result; // aca tambien hay errores
}

// Pide un entero y ejecuta distintas funciones segun que entero le llega (como un diccionario de funciones pero mas rudimentario). Retornara lo que retornen las funciones que llama
int _ejecutar_opcion(const int opcion)
{
    int cant_llaves = (sizeof(keys) / sizeof(keys[0]));
    for (int i = 0; i < cant_llaves; i++)
    {
        if (keys[i] == opcion)
        {
            return dict_opciones_globales[i]();
        }
    }
}
