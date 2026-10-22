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
    printf("  (el cronometro todavia no esta implementado)\n");
}
