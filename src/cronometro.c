/* ===========================================================================
 * cronometro.c  -  medir() viene dada; cronometro_tabla() es tuya.   [Lab 06]
 * ========================================================================= */

#include "cronometro.h"
#include "hechizos.h"

#include <stdio.h>
#include <time.h>      /* clock, CLOCKS_PER_SEC */

double medir(long (*f)(long), long n, long *resultado)
{
    clock_t inicio = clock();
    *resultado = f(n);
    clock_t fin = clock();
    return (double) (fin - inicio) / CLOCKS_PER_SEC;
}

void cronometro_tabla(void)
{
    /* TODO (Lab 06):
     *
     *   1. Mide simple_loop con  n = 1000000, 10000000, 100000000
     *   2. Mide double_loop con  n = 1000, 3000, 10000
     *   3. Imprime una tabla:
     *
     *        funcion          n        segundos
     *        simple_loop      1000000  0.002100
     *        ...
     *
     * Pista: guarda los n en un arreglo y recorrelo con un for.
     *     long ns[] = {1000000L, 10000000L, 100000000L};
     *     long r;
     *     double t = medir(simple_loop, ns[i], &r);
     *
     * Usa %ld para long y %f para double.
     */
    long ns_simple[] = {1000000L, 10000000L, 100000000L};
    long ns_double[] = {1000L, 3000L, 10000L};
    long r;

    for (int i = 0; i < 3; i++) {
        double t = medir(simple_loop, ns_simple[i], &r);
        printf("simple_loop %ld %.6f\n", ns_simple[i], t);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        double t = medir(double_loop, ns_double[i], &r);
        printf("double_loop %ld %.6f\n", ns_double[i], t);
    }
    
}
