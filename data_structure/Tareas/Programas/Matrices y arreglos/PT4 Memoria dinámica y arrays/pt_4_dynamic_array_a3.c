
/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Características del programa: 
Genere un arreglo dinámico variable bidimensional de acuerdo a su numero de cuenta y sera rellenado con los 
dígitos correspondientes a su cuenta. 
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int num_cuenta, i, j;


    printf("Ingrese su numero de cuenta (9 digitos): ");
    scanf("%d", &num_cuenta);

  
    if (num_cuenta < 100000000 || num_cuenta > 999999999) {
        printf("El numero de cuenta debe tener exactamente 9 dígitos.\n");
        return 1;
    }

    int **arreglo = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++) {
        arreglo[i] = (int *)malloc(3 * sizeof(int));
    }

    
    int digito;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            digito = num_cuenta % 10;
            arreglo[i][j] = digito;
            num_cuenta /= 10;
        }
    }


    printf("El arreglo bidimensional es:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < 3; i++) {
        free(arreglo[i]);
    }
    free(arreglo);

    return 1;
}
