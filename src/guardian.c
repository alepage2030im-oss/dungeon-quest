/* ===========================================================================
 * guardian.c  -  TU TRABAJO del Lab 06.
 * ========================================================================= */

#include "guardian.h"
#include "entrada.h"

#include <stdio.h>
#include <stdlib.h>    /* rand */

int guardian_comparar(int secreto, int intento)
{
    /* TODO (Lab 06): un if / else if / else que devuelva 1, -1 o 0. */
    (void) secreto;
    (void) intento;
    return 0;
}

int guardian_jugar(int intentos)
{
    /* TODO (Lab 06):
     *
     *   int secreto = rand() % 100 + 1;
     *
     *   for (int i = 1; i <= intentos; i++) {
     *       - pide un numero con get_int
     *       - usa guardian_comparar para decidir que responder
     *       - si acerto: felicita y return 1
     *   }
     *   - si llegas aqui se acabaron los intentos: revela el secreto, return 0
     *
     * No llames a srand() aqui: main() ya lo hace una vez al empezar.
     * Si lo llamas en cada partida, dos partidas seguidas pueden tener la
     * misma clave.
     */
    (void) intentos;
    printf("  (el guardian todavia no ha llegado a la puerta)\n");
    return 0;
}
