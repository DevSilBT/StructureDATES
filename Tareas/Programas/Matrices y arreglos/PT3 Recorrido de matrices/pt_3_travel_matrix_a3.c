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

Tendremos que crear una matriz de 6x6, que lea los elementos de la matriz en forma de "Z" de abajo hacia arriba.
*/

int main() {
    int matriZInver[6][6];
    char opcion;
    int i, j;

    do {
        printf("Matriz de 6x6:\n");

    
        for (i = 5; i >= 0; i--) {
            printf("Posicion [%d][%d]: ", i, i);
            scanf("%d", &matriZInver[i][i]);
        }

    
        for (i = 5; i > 0; i--) {
            for (j = i + 1; j < 6; j++) {
                printf("Posicion [%d][%d]: ", i, j);
                scanf("%d", &matriZInver[i][j]);
            }
        }

    
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5 - i; j++) {
                printf("Posicion [%d][%d]: ", i, j);
                scanf("%d", &matriZInver[i][j]);
            }
        }

    
        printf("\nLa matriz Z inversa es:\n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                printf("%d\t", matriZInver[i][j]);
            }
            printf("\n");
        }

  
        printf("\n¿Desea ingresar nuevos valores? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
