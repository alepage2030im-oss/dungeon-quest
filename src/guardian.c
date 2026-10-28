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
    if (secreto == intento) {
        return 0;
    } else if (secreto < intento) {
        return -1;
    } else {
        return 1;
    }
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
    int secreto = rand() % 100 + 1;

    for (int i = 1; i <= intentos; i++) {
        printf("Intento %d de %d.\n", i, intentos);
        int intento = get_int ("Adivina el numero secreto (1-100): ");
        int resultado = guardian_comparar(secreto, intento);
        if (resultado == 0) {
            printf(" Felicidades! Adivinaste el numero secreto.\n");
            return 1;
        } else if (resultado < 0) {
            printf("El numero secreto es menor que %d. Intenta de nuevo.\n", intento);
        } else {
            printf("El numero secreto es mayor que %d. Intenta de nuevo.\n", intento);
        }
    }
    printf("Se acabaron los intentos. El numero secreto era %d.\n", secreto);
    return 0;
}
