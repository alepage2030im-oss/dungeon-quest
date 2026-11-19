/* ===========================================================================
 * combate.c  -  TU TRABAJO del Lab 08: el combate.
 * ========================================================================= */

#include "combate.h"

int combate_pelear(Luchador *heroe, NodoEnemigo *enemigo)
{
    /* TODO (Lab 08):
     *
     * 1. Si heroe->ataque <= 0 y enemigo->ataque <= 0, nadie puede ganar:
     *    return 0. (Sin esto, el while de abajo no termina nunca.)
     *
     * 2. while (1) {
     *        el heroe golpea:   enemigo->vida -= heroe->ataque;
     *        si enemigo->vida <= 0: return 1;
     *        el enemigo golpea: heroe->vida -= enemigo->ataque;
     *        si heroe->vida <= 0: return 0;
     *    }
     *
     * Usa -> porque los dos son PUNTEROS: asi las vidas cambian de verdad
     * en quien llamo a la funcion.
     */
    if (heroe->ataque <= 0 && enemigo->ataque <= 0) {
        return 0;
    }

    while (1) {
        enemigo->vida -= heroe->ataque;
        if (enemigo->vida <= 0) {
            return 1;
        }
        heroe->vida -= enemigo->ataque;
        if (heroe->vida <= 0) {
            return 0;
        }
    }
}
