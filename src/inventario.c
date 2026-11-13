/* ===========================================================================
 * inventario.c  -  TU TRABAJO del Lab 07 (primera parte).
 * ---------------------------------------------------------------------------
 * Orden recomendado: inventario_agregar -> inventario_peso ->
 * inventario_imprimir -> inventario_liberar. Despues de cada una:
 * make test  (o probar.bat).
 * ========================================================================= */

#include "inventario.h"

#include <stdio.h>
#include <stdlib.h>    /* malloc, realloc, free */
#include <string.h>    /* strlen, strcpy */

/* DADA. Devuelve una COPIA nueva del texto, pedida con malloc (o NULL si no
 * hubo memoria). Es lo que hace strdup, pero strdup NO es de C99: con
 * -std=c99 el gcc de Windows no lo conoce y el programa puede caerse.
 * Lo que devuelve se libera con free, como todo lo que viene de malloc. */
static char *copiar_texto(const char *texto)
{
    char *copia = malloc(strlen(texto) + 1);      /* +1 para el '\0' final */
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

int inventario_agregar(Item **inv, int *cantidad, int *capacidad,
                       const char *nombre, char tipo, float peso)
{
    /* TODO (Lab 07):
     *
     * 1. Si la mochila no existe todavia (*capacidad == 0):
     *        pide espacio para 2 items con malloc
     *        *inv = malloc(2 * sizeof(Item));
     *    Si malloc devuelve NULL, return 0.
     *
     * 2. Si esta llena (*cantidad == *capacidad):
     *        duplica la capacidad con realloc.
     *    CUIDADO: guarda el resultado en un puntero AUXILIAR, no en *inv:
     *        Item *nueva = realloc(*inv, ...);
     *        if (nueva == NULL) return 0;    <- *inv sigue siendo valido
     *        *inv = nueva;
     *    Si escribes  *inv = realloc(*inv, ...)  y falla, pierdes la
     *    mochila vieja para siempre (fuga de memoria).
     *
     * 3. Llena el item en la posicion *cantidad:
     *        (*inv)[*cantidad].nombre = copiar_texto(nombre);   <- una COPIA
     *        ...tipo y peso...
     *    Los parentesis de (*inv) son obligatorios: sin ellos C lee
     *    *(inv[*cantidad]), que es otra cosa.
     *
     * 4. Incrementa *cantidad y return 1.
     */
    (void) inv;
    (void) cantidad;
    (void) capacidad;
    (void) nombre;
    (void) tipo;
    (void) peso;
    (void) copiar_texto;         /* borra esta linea cuando la uses */
    return 0;
}

float inventario_peso(const Item *inv, int cantidad)
{
    /* TODO (Lab 07): recorre y suma inv[i].peso */
    (void) inv;
    (void) cantidad;
    return 0.0f;
}

void inventario_imprimir(const Item *inv, int cantidad)
{
    /* TODO (Lab 07): una linea por item, con un switch sobre inv[i].tipo
     * para mostrar "Arma", "Armadura", "Pocion" o "Varios". Al final,
     * el peso total. Si cantidad == 0, imprime "La mochila esta vacia." */
    (void) inv;
    (void) cantidad;
    printf("  (la mochila todavia no esta implementada)\n");
}

void inventario_liberar(Item *inv, int cantidad)
{
    /* TODO (Lab 07):
     *   1. free de cada inv[i].nombre   (fueron pedidos con copiar_texto)
     *   2. free(inv)                     (fue pedido con malloc/realloc)
     * El orden importa: si liberas inv primero, ya no puedes leer
     * inv[i].nombre para liberarlo. */
    (void) inv;
    (void) cantidad;
}
