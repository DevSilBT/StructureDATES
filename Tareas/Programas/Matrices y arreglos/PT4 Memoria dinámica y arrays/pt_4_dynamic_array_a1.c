

/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Características del programa: 
Genere una lista de los primeros 10 números pares, deberá imprimirlos en orden inverso.
posteriormente deberá modificar el valor almacenado en el índice correspondiente al último dígito de su número cuenta por -1.*/

#include <stdio.h>
int main() {
    int numPares[10];
    int i, ultimoNumero;

    
    for (i = 0; i < 10; i++) {
        numPares[i] = 2 * i;
    }

    
    printf("Ultimo digito de su número de cuenta: ");
    scanf("%d", &ultimoNumero);

    
    numPares[ultimoNumero] = -1;


    printf("Números pares en orden inverso son:\n");
    for (i = 9; i >= 0; i--) {
        printf("%d\n", numPares[i]);
    }

    return 0;
}
