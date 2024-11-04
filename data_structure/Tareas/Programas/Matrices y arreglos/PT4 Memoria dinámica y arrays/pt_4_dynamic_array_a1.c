

/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           N�meros de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Caracter�sticas del programa: 
Genere una lista de los primeros 10 n�meros pares, deber� imprimirlos en orden inverso.
posteriormente deber� modificar el valor almacenado en el �ndice correspondiente al �ltimo d�gito de su n�mero cuenta por -1.*/

#include <stdio.h>
int main() {
    int numPares[10];
    int i, ultimoNumero;

    
    for (i = 0; i < 10; i++) {
        numPares[i] = 2 * i;
    }

    
    printf("Ultimo digito de su n�mero de cuenta: ");
    scanf("%d", &ultimoNumero);

    
    numPares[ultimoNumero] = -1;


    printf("N�meros pares en orden inverso son:\n");
    for (i = 9; i >= 0; i--) {
        printf("%d\n", numPares[i]);
    }

    return 0;
}
