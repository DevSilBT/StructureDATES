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

 Tendremos que crear una matriz de 6x4, que lea los elementos de la matriz en forma de "S" invertida.
*/

int main() {
    int matrizSinver[6][4];
    int i, j;
    char opcion;

    do {
        
        printf("---Matriz de 6x4---\n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 4; j++) {
                printf("Posicion [%d][%d]: ", i, j);
                scanf("%d", &matrizSinver[i][j]);
            }
        }

        
        printf("\nLa matriz S invertida es:\n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 4; j++) {
                printf("%d\t", matrizSinver[i][j]);
            }
            printf("\n");
        }

        
        printf("\n¿Desea ingresar otra matriz? (s/n): ");
        scanf(" %c", &opcion); 
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
