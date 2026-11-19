/* ===========================================================================
 * bestiario.c  -  TU TRABAJO del Lab 08: la lista enlazada.
 * ---------------------------------------------------------------------------
 * Orden recomendado: agregar -> liberar -> insertar -> purgar.
 * Despues de cada una: probar.bat  (o make test).
 * ========================================================================= */

#include "bestiario.h"

#include <stdio.h>
#include <stdlib.h>    /* malloc, free */
#include <string.h>    /* strlen, strcpy */

/* DADA. Una COPIA nueva del texto, pedida con malloc (o NULL si no hubo
 * memoria). Es la misma de la mochila. Se libera con free. */
static char *copiar_texto(const char *texto)
{
    char *copia = malloc(strlen(texto) + 1);      /* +1 para el '\0' final */
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

/* DADA. Pide un nodo con su nombre copiado y siguiente en NULL.
 * Devuelve NULL si no hubo memoria (y no deja nada a medias). */
static NodoEnemigo *nuevo_enemigo(const char *nombre, int vida, int ataque)
{
    NodoEnemigo *e = malloc(sizeof(NodoEnemigo));
    if (e == NULL) {
        return NULL;
    }
    e->nombre = copiar_texto(nombre);
    if (e->nombre == NULL) {
        free(e);
        return NULL;
    }
    e->vida = vida;
    e->ataque = ataque;
    e->siguiente = NULL;
    return e;
}

int bestiario_agregar(NodoEnemigo **cabeza, const char *nombre, int vida, int ataque)
{
    /* TODO (Lab 08):
     *
     * 1. NodoEnemigo *nuevo = nuevo_enemigo(nombre, vida, ataque);
     *    Si es NULL, return 0.
     *
     * 2. Si la lista esta vacia (*cabeza == NULL): el nuevo ES la cabeza.
     *        *cabeza = nuevo;
     *
     * 3. Si no: camina hasta el ULTIMO (el que tiene siguiente == NULL)
     *        NodoEnemigo *p = *cabeza;
     *        while (p->siguiente != NULL) p = p->siguiente;
     *    y engancha:   p->siguiente = nuevo;
     *
     * 4. return 1.
     */
    (void) cabeza;
    (void) nombre;
    (void) vida;
    (void) ataque;
    (void) nuevo_enemigo;            /* borra esta linea cuando la uses */
    return 0;
}

int bestiario_insertar(NodoEnemigo **cabeza, int pos, const char *nombre, int vida, int ataque)
{
    /* TODO (Lab 08):
     *
     * 1. Pide el nodo con nuevo_enemigo; si es NULL, return 0.
     *
     * 2. Si pos <= 0 o la lista esta vacia: va al PRINCIPIO.
     *        nuevo->siguiente = *cabeza;
     *        *cabeza = nuevo;
     *
     * 3. Si no: camina hasta el nodo ANTERIOR a la posicion (pos - 1 pasos,
     *    o hasta el ultimo si la lista es mas corta) y engancha EN ESTE ORDEN:
     *        nuevo->siguiente = anterior->siguiente;   <- primero
     *        anterior->siguiente = nuevo;              <- despues
     *    Si lo haces al reves, el nuevo termina apuntandose a si mismo.
     *
     * 4. return 1.
     */
    (void) cabeza;
    (void) pos;
    (void) nombre;
    (void) vida;
    (void) ataque;
    return 0;
}

void bestiario_purgar(NodoEnemigo **cabeza)
{
    /* TODO (Lab 08): es la parte dificil. Dibujala antes.
     *
     * 1. Mientras la CABEZA este derrotada (vida <= 0): guardala, avanza
     *    *cabeza a su siguiente y libera la vieja (nombre y nodo).
     *
     * 2. Despues, recorre con un puntero p desde *cabeza y mira SIEMPRE al
     *    siguiente:
     *        si p->siguiente esta derrotado: guardalo, salta
     *            (p->siguiente = muerto->siguiente) y liberalo.
     *            NO avances p: el nuevo siguiente tambien puede estar muerto.
     *        si no: avanza p.
     */
    (void) cabeza;
}

void bestiario_imprimir(const NodoEnemigo *cabeza)
{
    if (cabeza == NULL) {
        printf("  (el bestiario esta vacio)\n");
        return;
    }
    for (const NodoEnemigo *e = cabeza; e != NULL; e = e->siguiente) {
        printf("  %-14s vida %4d   ataque %3d\n", e->nombre, e->vida, e->ataque);
    }
}

void bestiario_liberar(NodoEnemigo *cabeza)
{
    /* TODO (Lab 08): recorre liberando, igual que la mochila pero
     * en una lista. Por cada nodo: guarda el siguiente ANTES del free, y
     * libera primero el nombre y despues el nodo.
     *
     *     while (cabeza != NULL) {
     *         NodoEnemigo *sig = cabeza->siguiente;
     *         free(cabeza->nombre);
     *         free(cabeza);
     *         cabeza = sig;
     *     }
     */
    (void) cabeza;
}
