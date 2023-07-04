#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define NUM_CARRERAS 7
#define NUM_ANIOS 5

typedef struct {
    char nombre[50];
    int ingresos[NUM_ANIOS][2]; // Dos semestres por año
} Carrera;

// Prototipos de funciones
void generarDatosAleatorios(Carrera carreras[]);
int calcularAnioMaxIngresos(const Carrera carreras[]);
int calcularCarreraMaxIngresosUltimoAnio(const Carrera carreras[]);
int calcularAnioMaxIngresosIngenieriaSoftware(const Carrera carreras[]);

int main() {
    setlocale(LC_ALL, "Spanish");
    srand(time(NULL));

    Carrera carreras[NUM_CARRERAS] = {
        {"Ingeniería de Software"},
        {"Administración"},
        {"Economía"},
        {"Relaciones Internacionales"},
        {"Matemáticas"},
        {"Contabilidad"},
        {"Ingeniería Industrial"}
    };

    int opcion;
    printf("Bienvenido al programa de registro de ingresos universitarios.\n");
    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Generar datos aleatorios de ingresos.\n");
        printf("2. Mostrar ingresos por carrera y año.\n");
        printf("3. Mostrar el año con mayor cantidad de ingresos.\n");
        printf("4. Mostrar la carrera con mayor cantidad de ingresos en el último año.\n");
        printf("5. Mostrar el año con mayor cantidad de ingresos en Ingeniería de Software.\n");
        printf("0. Salir.\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                generarDatosAleatorios(carreras);
                printf("Datos aleatorios generados exitosamente.\n");
                break;
            case 2:
                printf("Ingresos por carrera y año:\n");
                for (int i = 0; i < NUM_CARRERAS; i++) {
                    printf("%s\n", carreras[i].nombre);
                    for (int j = 0; j < NUM_ANIOS; j++) {
                        printf("Año #%d. Semestre 1: %d, Semestre 2: %d\n", j + 1, carreras[i].ingresos[j][0], carreras[i].ingresos[j][1]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("El año en que ingresó la mayor cantidad de alumnos a la universidad fue el #%d.\n", calcularAnioMaxIngresos(carreras) + 1);
                break;
            case 4:
                printf("La Carrera que recibió la mayor cantidad de alumnos en el último año fue: %s.\n", carreras[calcularCarreraMaxIngresosUltimoAnio(carreras)].nombre);
                break;
            case 5:
                printf("El año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos fue el #%d.\n", calcularAnioMaxIngresosIngenieriaSoftware(carreras) + 1);
                break;
            case 0:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}

void generarDatosAleatorios(Carrera carreras[]) {
    for (int i = 0; i < NUM_CARRERAS; i++) {
        for (int j = 0; j < NUM_ANIOS; j++) {
            carreras[i].ingresos[j][0] = rand() % 300; // Semestre 1
            carreras[i].ingresos[j][1] = rand() % 300; // Semestre 2
        }
    }
}

int calcularAnioMaxIngresos(const Carrera carreras[]) {
    int maxIngresos = 0;
    int anioMaxIngresos = 0;
    for (int i = 0; i < NUM_ANIOS; i++) {
        int suma = 0;
        for (int j = 0; j < NUM_CARRERAS; j++) {
            suma += carreras[j].ingresos[i][0] + carreras[j].ingresos[i][1];
        }
        if (suma > maxIngresos) {
            maxIngresos = suma;
            anioMaxIngresos = i;
        }
    }
    return anioMaxIngresos;
}

int calcularCarreraMaxIngresosUltimoAnio(const Carrera carreras[]) {
    int maxIngresosUltimoAnio = 0;
    int carreraMaxIngresosUltimoAnio = 0;
    for (int i = 0; i < NUM_CARRERAS; i++) {
        int sumaUltimoAnio = carreras[i].ingresos[NUM_ANIOS - 1][0] + carreras[i].ingresos[NUM_ANIOS - 1][1];
        if (sumaUltimoAnio > maxIngresosUltimoAnio) {
            maxIngresosUltimoAnio = sumaUltimoAnio;
            carreraMaxIngresosUltimoAnio = i;
        }
    }
    return carreraMaxIngresosUltimoAnio;
}

int calcularAnioMaxIngresosIngenieriaSoftware(const Carrera carreras[]) {
    int maxIngresosIngSoftware = 0;
    int anioMaxIngresosIngSoftware = 0;
    for (int i = 0; i < NUM_ANIOS; i++) {
        int ingresosIngSoftware = carreras[0].ingresos[i][0] + carreras[0].ingresos[i][1]; // Ingeniería de Software es la primera carrera (índice 0)
        if (ingresosIngSoftware > maxIngresosIngSoftware) {
            maxIngresosIngSoftware = ingresosIngSoftware;
            anioMaxIngresosIngSoftware = i;
        }
    }
    return anioMaxIngresosIngSoftware;
}
