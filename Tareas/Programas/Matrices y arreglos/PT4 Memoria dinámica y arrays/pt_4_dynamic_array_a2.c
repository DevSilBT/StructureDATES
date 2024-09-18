/*
 Facultad de Estudios Superiores Acatlan
 Estructura de datos
  Alumno:                           Números de cuenta:
  Rodriguez Bautista Ollin.           31522542-2
  Siles Bazaldua Humberto Tomas       42414119-0
  Grupo: 1301

  Características del programa: 
Programa que acepte una lista de n alumnos, el arreglo deberá ser de nx3, la primera columna deberá tener un espacio de 25 caracteres, la segunda y tercera deberá aceptar números enteros.

El programa después de capturar los datos, deberá devolver el promedio de edad y de calificación grupal.
El programa deberá imprimir los nombres de los alumnos en sentido inverso al que fueron ingresados o se encuentran almacenados.
Puede ser del tipo char todo el arreglo, solo recuerde hacer el "casteo" para los elementos numéricos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNombre 25

typedef struct {
    char nombre[MaxNombre + 1];
    float calificacion;
    int edad;
} Estudiante;

int main() {
    int n, i;
    float sumaCal = 0, sumaEdades = 0;
    Estudiante *estudiantes;
    char respuesta;

    
    printf("Numero de estudiantes: ");
    scanf("%d", &n);

   
    estudiantes = (Estudiante *)malloc(n * sizeof(Estudiante));
    if (estudiantes == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    
    for (i = 0; i < n; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("  Nombre: ");
        scanf("%s", estudiantes[i].nombre);
        printf("  Edad: ");
        scanf("%d", &estudiantes[i].edad);
        printf("  Calificación: ");
        scanf("%f", &estudiantes[i].calificacion);

        sumaCal += estudiantes[i].calificacion;
        sumaEdades += estudiantes[i].edad;
    }

    
    float promedioCal = sumaCal / n;
    float promedioEdades = sumaEdades / n;

    
    printf("\nPromedios iniciales:\n");
    printf("Promedio de calificaciones: %.2f\n", promedioCal);
    printf("Promedio de edades: %.2f\n", promedioEdades);

    
    printf("\n¿Desea modificar alguna calificación? (s/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S') {
        
        for (i = 0; i < n; i++) {
            printf("¿Desea modificar la calificación de %s? (s/n): ", estudiantes[i].nombre);
            scanf(" %c", &respuesta);
            if (respuesta == 's' || respuesta == 'S') {
                printf("  Nueva calificación: ");
                scanf("%f", &estudiantes[i].calificacion);
                sumaCal += estudiantes[i].calificacion - estudiantes[i].calificacion;
            }
        }

        promedioCal = sumaCal / n;
        printf("\nPromedio de calificaciones (actualizado): %.2f\n", promedioCal);
    }

   
    printf("\nNombres en orden inverso:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%s\n", estudiantes[i].nombre);
    }

    
    free(estudiantes);

    return 0;
}
