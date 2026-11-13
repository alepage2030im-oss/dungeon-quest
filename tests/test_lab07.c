/* ===========================================================================
 * test_lab07.c  -  Pruebas del Lab 07, parte 1: el inventario.  NO LO MODIFIQUES.
 * ---------------------------------------------------------------------------
 * (El bestiario y el combate se agregan a este archivo en la parte 2.)
 * ========================================================================= */

#include <string.h>

#include "prueba.h"
#include "inventario.h"

/* Compara floats con tolerancia: 0.1 + 0.2 no es exactamente 0.3 */
static int casi_igual(float a, float b)
{
    float d = a - b;
    return d < 0.001f && d > -0.001f;
}

int main(void)
{
    printf("\n  Pruebas del Lab 07 - Dungeon Quest (parte 1: inventario)\n");
    printf("  -------------------------------------------------------\n");

    Item *mochila = NULL;
    int n = 0, cap = 0;

    /* --- el primer item: malloc --- */
    int ok = inventario_agregar(&mochila, &n, &cap, "Espada larga", 'W', 3.5f);
    VERIFICAR(ok == 1,                    "agregar a una mochila vacia devuelve 1");
    VERIFICAR(mochila != NULL,            "despues del primero, la mochila existe (malloc)");
    VERIFICAR(n == 1,                     "cantidad == 1");
    VERIFICAR(cap == 2,                   "capacidad inicial == 2");
    VERIFICAR(n >= 1 && mochila != NULL && mochila[0].nombre != NULL
              && strcmp(mochila[0].nombre, "Espada larga") == 0,
              "el item 0 se llama 'Espada larga'");
    VERIFICAR(n >= 1 && mochila != NULL && mochila[0].tipo == 'W',
              "el item 0 es de tipo 'W'");

    /* --- el nombre es una COPIA, no una referencia --- */
    char buffer[32] = "Arco corto";
    inventario_agregar(&mochila, &n, &cap, buffer, 'W', 2.1f);
    strcpy(buffer, "zzzzzz");               /* cambio el original...         */
    VERIFICAR(n >= 2 && mochila != NULL && mochila[1].nombre != NULL
              && strcmp(mochila[1].nombre, "Arco corto") == 0,
              "el nombre es una copia: cambiar el original no lo afecta");
    VERIFICAR(n >= 2 && mochila != NULL && mochila[1].nombre != buffer,
              "el item no apunta al texto de quien llama (usa copiar_texto)");

    /* --- la mochila crece: realloc --- */
    inventario_agregar(&mochila, &n, &cap, "Pocion de vida",  'P', 0.3f);
    VERIFICAR(n == 3 && cap == 4,         "al tercer item la capacidad se duplica a 4");

    inventario_agregar(&mochila, &n, &cap, "Botas de cuero",  'A', 1.2f);
    inventario_agregar(&mochila, &n, &cap, "Casco de hierro", 'A', 2.8f);
    VERIFICAR(n == 5 && cap == 8,         "al quinto item la capacidad se duplica a 8");

    VERIFICAR(n >= 5 && mochila != NULL && mochila[0].nombre != NULL
              && strcmp(mochila[0].nombre, "Espada larga") == 0,
              "al crecer, el primer item sigue en su lugar");
    VERIFICAR(n >= 5 && mochila != NULL && mochila[4].nombre != NULL
              && strcmp(mochila[4].nombre, "Casco de hierro") == 0,
              "el ultimo item agregado esta al final");

    /* --- el peso --- */
    VERIFICAR(casi_igual(inventario_peso(mochila, n), 9.9f),
              "peso total == 9.9 kg");
    VERIFICAR(casi_igual(inventario_peso(mochila, 0), 0.0f),
              "peso de una mochila vacia == 0");

    /* --- devolver la memoria (si esto revienta, hay un free de mas) --- */
    inventario_liberar(mochila, n);
    VERIFICAR(1, "inventario_liberar termino sin reventar");

    /* --- mochila grande --- */
    Item *grande = NULL;
    int gn = 0, gcap = 0;
    for (int i = 0; i < 1000; i++) {
        inventario_agregar(&grande, &gn, &gcap, "Moneda", 'X', 0.01f);
    }
    VERIFICAR(gn == 1000 && gcap == 1024, "1000 items: capacidad 1024 (2,4,8,...,1024)");
    inventario_liberar(grande, gn);

    return RESUMEN("Lab 07 (inventario)");
}
