#include <stdio.h>

/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

Características del programa: 
Se desea construir un programa que cuenta con las siguientes funciones de lectura de matrices estáticas:

Tendremos que crear una matriz de 6x6, que lea los elementos de la matriz en forma de "Z".
*/

int main() {
    int matriZ[6][6];
    int i, j;
    char opcion;

    do {
        printf("\ ---Matriz de 6x6---\n");

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                printf("Posicion [%d][%d]: ", i, j);
                scanf("%d", &matriZ[i][j]);
            }
        }

        printf("\nLa matriz Z es:\n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                printf("%d\t", matriZ[i][j]);
            }
            printf("\n");
        }

        printf("\n¿Desea generar otra matriz? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
