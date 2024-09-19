
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

    // Pedimos al usuario el numero de cuenta
    printf("Ingrese su numero de cuenta (9 digitos): ");
    scanf("%d", &num_cuenta);

    // Verificamos que el numero de cuenta tenga 9 dígitos
    if (num_cuenta < 100000000 || num_cuenta > 999999999) {
        printf("El numero de cuenta debe tener exactamente 9 dígitos.\n");
        return 1;
    }

    // Creamos un arreglo bidimensional dinámico de tamaño 3x3
    int **arreglo = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++) {
        arreglo[i] = (int *)malloc(3 * sizeof(int));
    }

    // Rellenamos el arreglo con los dígitos del numero de cuenta
    int digito;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            digito = num_cuenta % 10;
            arreglo[i][j] = digito;
            num_cuenta /= 10;
        }
    }

    // Imprimimos el arreglo
    printf("El arreglo bidimensional es:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }

    // Liberamos la memoria asignada
    for (i = 0; i < 3; i++) {
        free(arreglo[i]);
    }
    free(arreglo);

    return 1;
}
