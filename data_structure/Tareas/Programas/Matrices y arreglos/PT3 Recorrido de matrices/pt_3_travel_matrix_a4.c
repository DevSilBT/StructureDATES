#include <stdio.h>

/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin            31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301
 

Características del programa: 
Se desea construir un programa que cuenta con las siguientes funciones de lectura de matrices estáticas:

Tendremos que crear una matriz de  3x4,que leea la "invertida", es decir, de derecha a izquierda y de abajo hacia arriba.
*/
int main() {
    int matriz[3][4];
    int i, j;
    char opcion;

    do {
        
        printf("Matriz de 3x4:\n");
        for (i = 2; i >= 0; i--) { 
            for (j = 3; j >= 0; j--) { 
                printf("Posicion [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }


        printf("\nLa matriz inversa es:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }

     
        printf("\n¿Desea ingresar nuevos valores? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
