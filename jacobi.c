#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void jacobi(double A[3][3], double b[3], double x[3], double tol, int max_iter) {
    double x_new[3];
    printf("%10s %10s %10s %10s\n", "Iteracion", "x", "y", "z");
    for (int k = 0; k < max_iter; ++k) {
        for (int i = 0; i < 3; ++i) {
            double s = 0.0;
            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    s += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - s) / A[i][i];
        }
        printf("%10d %10.6f %10.6f %10.6f\n", k + 1, x_new[0], x_new[1], x_new[2]);

        double norm = 0.0;
        for (int i = 0; i < 3; ++i) {
            norm = fmax(norm, fabs(x_new[i] - x[i]));
        }
        if (norm < tol) {
            for (int i = 0; i < 3; ++i) {
                x[i] = x_new[i];
            }
            printf("Convergencia alcanzada en %d iteraciones.\n", k + 1);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            x[i] = x_new[i];
        }
    }
    printf("No se alcanzo la convergencia en %d iteraciones.\n", max_iter);
}

void hacer_diagonalmente_dominante(double A[3][3], double b[3]) {
    for (int i = 0; i < 3; ++i) {
        double suma = 0.0;
        for (int j = 0; j < 3; ++j) {
            if (i != j) {
                suma += fabs(A[i][j]);
            }
        }
        if (fabs(A[i][i]) <= suma) {
            for (int k = i + 1; k < 3; ++k) {
                if (fabs(A[k][i]) > suma) {
                    for (int j = 0; j < 3; ++j) {
                        double temp = A[i][j];
                        A[i][j] = A[k][j];
                        A[k][j] = temp;
                    }
                    double temp_b = b[i];
                    b[i] = b[k];
                    b[k] = temp_b;
                    break;
                }
            }
        }
    }
}

void capturar_ecuaciones() {
    double A[3][3];
    double b[3];
    double x[3] = {0.0, 0.0, 0.0};
    char opcion;

    while (1) {
        printf("--------------------------------------------------\n");
        printf("Ingrese los coeficientes de las ecuaciones (o 'r' para reiniciar):\n");
        char variables[3] = {'x', 'y', 'z'};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("Ingrese el coeficiente de %c en la ecuacion %d: ", variables[j], i + 1);
                if (scanf(" %lf", &A[i][j]) != 1) {
                    while (getchar() != '\n');
                    printf("Entrada invalida. Reiniciando la captura de datos...\n");
                    i = -1;
                    break;
                }
            }
            if (i == -1) continue;
            printf("Ingrese el termino independiente de la ecuacion %d: ", i + 1);
            if (scanf(" %lf", &b[i]) != 1) {
                while (getchar() != '\n');
                printf("Entrada invalida. Reiniciando la captura de datos...\n");
                i = -1;
                continue;
            }
        }

        hacer_diagonalmente_dominante(A, b);

        printf("\nEcuaciones ajustadas (si fue necesario):\n");
        for (int i = 0; i < 3; ++i) {
            printf("%c = (1/%.2f) * (%.2f", variables[i], A[i][i], b[i]);
            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    printf(" %c %.2f*%c", (A[i][j] < 0 ? '+' : '-'), fabs(A[i][j]), variables[j]);
                }
            }
            printf(" )\n");
        }

        printf("¿Desea volver a ingresar las ecuaciones? (r para repetir, cualquier otra tecla para continuar): ");
        scanf(" %c", &opcion);
        if (opcion != 'r') break;
    }

    double tol = 1e-5;
    int max_iter = 100;

    jacobi(A, b, x, tol, max_iter);

    printf("--------------------------------------------------\n");
    printf("Solucion: \a\a");
    for (int i = 0; i < 3; ++i) {
        printf("%.6f ", x[i]);
    }
    printf("\n");
    printf("--------------------------------------------------\n");
}

void menu() {
    int opcion;
    do {
        printf("\n--------------------------------------------------\n");
        printf("Menu:\n");
        printf("1. Ingresar y resolver un sistema de ecuaciones\n");
        printf("2. Salir\n");
        printf("--------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (opcion) {
            case 1:
                capturar_ecuaciones();
                break;
            case 2:
                printf("Saliendo del programa.\n\a");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n\a");
        }
    } while (opcion != 2);
}

int main() {
    setlocale(LC_CTYPE, "Spanish");
    printf("--------------------------------------------------\n");
    printf("Bienvenido al solucionador de sistemas por Jacobi\nLuis Daniel Brambila Ramos 2310116\n");
    printf("--------------------------------------------------\n");
    printf("Instrucciones:\n");
    printf("1. Seleccione la opcion 1 para ingresar y resolver un sistema de ecuaciones.\n");
    printf("2. Ingrese los coeficientes y terminos independientes de las ecuaciones.\n");
    printf("3. El programa ajustara las ecuaciones si es necesario y resolvera el sistema.\n");
    printf("4. Seleccione la opcion 2 para salir del programa.\n");
    printf("--------------------------------------------------\n");
    menu();
    return 0;
}