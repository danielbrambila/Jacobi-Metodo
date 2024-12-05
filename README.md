# Jacobi-Metodo
# Solucionador de Sistemas por Jacobi

Este programa resuelve sistemas de ecuaciones lineales utilizando el método de Jacobi.

## Requisitos

- GCC (GNU Compiler Collection)
- Terminal de comandos

## Instrucciones para Compilar y Ejecutar

1. **Guardar el código**: Asegúrate de que el código esté guardado en un archivo llamado `jacobi.c`.

2. **Abrir una terminal**: En Visual Studio Code, puedes abrir una terminal integrada presionando ``Ctrl + ` `` (Ctrl + tecla de tilde).

3. **Compilar el código**: Usa el compilador `gcc` para compilar el archivo. Ejecuta el siguiente comando en la terminal:
   ```sh
   gcc -o jacobi jacobi.c -lm

   Ejecutar
   ./jacobi

   --------------------------------------------------
Bienvenido al solucionador de sistemas por Jacobi
--------------------------------------------------
Instrucciones:
1. Seleccione la opcion 1 para ingresar y resolver un sistema de ecuaciones.
2. Ingrese los coeficientes y terminos independientes de las ecuaciones.
3. El programa ajustara las ecuaciones si es necesario y resolvera el sistema.
4. Seleccione la opcion 2 para salir del programa.
--------------------------------------------------

Menu:
1. Ingresar y resolver un sistema de ecuaciones
2. Salir
--------------------------------------------------
Seleccione una opcion: 1
--------------------------------------------------
Ingrese los coeficientes de las ecuaciones (o 'r' para reiniciar):
Ingrese el coeficiente de x en la ecuacion 1: 10
Ingrese el coeficiente de y en la ecuacion 1: -1
Ingrese el coeficiente de z en la ecuacion 1: 2
Ingrese el termino independiente de la ecuacion 1: 6
Ingrese el coeficiente de x en la ecuacion 2: -1
Ingrese el coeficiente de y en la ecuacion 2: 11
Ingrese el coeficiente de z en la ecuacion 2: -1
Ingrese el termino independiente de la ecuacion 2: 25
Ingrese el coeficiente de x en la ecuacion 3: 2
Ingrese el coeficiente de y en la ecuacion 3: -1
Ingrese el coeficiente de z en la ecuacion 3: 10
Ingrese el termino independiente de la ecuacion 3: -11

Ecuaciones ajustadas (si fue necesario):
x = (1/10.00) * (6.00 + 1.00*y - 2.00*z )
y = (1/11.00) * (25.00 + 1.00*x + 1.00*z )
z = (1/10.00) * (-11.00 - 2.00*x + 1.00*y )
--------------------------------------------------
Iteracion         x         y         z
         1    0.600000    2.363636   -1.100000
         2    1.672727    2.209091   -1.092727
         3    1.650545    2.123140   -1.070909
         4    1.624114    2.123140   -1.070909
         5    1.624114    2.123140   -1.070909
Convergencia alcanzada en 5 iteraciones.
--------------------------------------------------
Solucion: 1.624114 2.123140 -1.070909 
--------------------------------------------------