/*En una Institución educativa se almacenan datos sobre el número de alumnos que han ingresado a sus
diferentes carreras en los dos semestres anuales y en los últimos 5 años. Cada carrera tiene un 
numero asociado que la identifica: 1. Ingeniería de Software. 2. Administración. 3. Economía.
4. Relaciones Internacionales. 5. Matemáticas. 6. Contabilidad. 7. Ingeniería Industrial.
Escriba un programa que calcule:
a) El año en que ingresó la mayor cantidad de alumnos a la universidad.
b) La Carrera que recibió la mayor cantidad de alumnos en el último año.
c) ¿En qué año la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos?*/

/*Anthony Almeida-Jeison Quimi-Romina Villavicencio*/

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    //se ocupa una función para identificar el idioma y se imprima correctamente todo
    setlocale(LC_ALL, "Spanish");
    //se utiliza srand para cada vez que se corre salgan numeros diferentes
    srand(time(NULL));
    //se declara variables por literales para mayor entendimiento
    int suma, ingresos=0, anio=0;
    int alumnos=0, carrera=0;
    int sof=0, anios=0;
    int car[6][8];
    //se crea un ciclo anidado con el año y la carrera para determinar el ingreso de estudiantes
    for (int i = 1; i < 6; i++)
    {
        suma=0;
        for (int j = 1; j < 8; j++)
        {
    //en el rand se pone un rango maximo de ingreso de estudiantes de 300
            car[i][j]=rand()%300;
            suma+=car[i][j];
    //se crea un if para el literal b, determinando que carrera tiene mas alumnos en el ultimo año
        if (i==5 && car[i][j]> alumnos)
        {
            alumnos=car[i][j];
            carrera=j;
        }
    //se crea un if para el literal c, determinando en que año hubo mas ingresos a Ingieneria de Software
        if (j==1 && car[i][j] >sof)
        {
            sof=car[i][j];
            anios=i;
        }
        
        }
    //se crea un if para el literal a, determinando en que año hubo mas ingresos de estudiantes
        if (suma>ingresos)
        {
            ingresos=suma;
            anio=i;
        }
        
    }
    //con un ciclo anidado imprimo los ingresos por carrera y año
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            printf("Año #%d. Carrera #%d Ingresos=%d \n", i, j, car[i][j]);
        }

    }
    //se imprime los resultados de los literales
    printf("a) El año en que ingresó la mayor cantidad de alumnos a la universidad fue el #%d con %d estudiantes \n", anio, ingresos);
    printf("b) La Carrera que recibió la mayor cantidad de alumnos en el último año fue la carrera #%d con %d estudiantes \n", carrera, alumnos);
    printf("LEYENDA DE CARRERAS \n");
    printf(" 1. Ingeniería de Software \n 2. Administración \n 3. Economía\n 4. Relaciones Internacionales\n 5. Matemáticas\n 6. Contabilidad\n 7. Ingeniería Industrial\n");
    printf("c) El año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos fue el #%d con %d estudiantes \n", anios, sof);
    
    return 0;
}