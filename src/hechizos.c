/* ===========================================================================
 * hechizos.c  -  TU TRABAJO del Lab 06: traduce el Lab 01 a C.
 * ---------------------------------------------------------------------------
 * Abre tu notebook del Lab 01 al lado y traduce linea por linea.
 * Cuando termines, `make test` (o probar.bat) te dice si quedo bien.
 * ========================================================================= */

#include "hechizos.h"

/* ---------------------------------------------------------------------------
 * PYTHON (Lab 01):
 *
 *     def mcd(a, b):
 *         while b:
 *             a, b = b, a % b
 *         return a
 *
 * CUIDADO: en C NO existe  a, b = b, a % b.
 * Si escribes  b = a % b;  y despues  a = b;  el segundo ya usa el b NUEVO.
 * Necesitas una variable temporal.
 * ------------------------------------------------------------------------- */
long mcd(long a, long b)
{
    /* TODO (Lab 06) */
    (void) a;          /* estas dos lineas evitan el aviso "parametro sin  */
    (void) b;          /* usar". Borralas cuando escribas la funcion.       */
    return 0;
}

/* ---------------------------------------------------------------------------
 * PYTHON:
 *
 *     def fibonacci(n):
 *         a, b = 0, 1
 *         for _ in range(n):
 *             a, b = b, a + b
 *         return a
 *
 * El for de C tiene tres partes:  for (int i = 0; i < n; i++)
 * Usa long long para a y b.
 * ------------------------------------------------------------------------- */
long long fibonacci(int n)
{
    /* TODO (Lab 06) */
    (void) n;
    return 0;
}

/* PYTHON:   count = 0;  for i in range(n): count += 1;  return count */
long simple_loop(long n)
{
    /* TODO (Lab 06) */
    (void) n;
    return 0;
}

/* PYTHON:   dos for anidados de range(n), count += 1 en el de adentro */
long double_loop(long n)
{
    /* TODO (Lab 06) */
    (void) n;
    return 0;
}
