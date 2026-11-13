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
    if (*capacidad == 0)
    {
        *inv = malloc(2 * sizeof(Item));
        if (*inv == NULL)
        {
            return 0;
        }
        *capacidad = 2;
    }
    else if (*cantidad == *capacidad)
    {
        Item *nueva = realloc(*inv, 2 * (*capacidad) * sizeof(Item));
        if (nueva == NULL)
        {
            return 0;
        }
        *inv = nueva;
        *capacidad = 2 * (*capacidad);
    }
    (*inv)[*cantidad].nombre = copiar_texto(nombre);
    (*inv)[*cantidad].tipo   = tipo;
    (*inv)[*cantidad].peso   = peso;

    (*cantidad)++; 
    return 1;

}

float inventario_peso(const Item *inv, int cantidad)
{
    float total = 0.0f;
    for (int i = 0; i < cantidad; i++) {
        total = total + inv[i].peso;
    }
    return total;
}

void inventario_imprimir(const Item *inv, int cantidad)
{
    if (cantidad == 0) {
        printf("La mochila esta vacia.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        const char *tipo_texto;
        switch (inv[i].tipo) {
            case 'W': tipo_texto = "Arma";     break;
            case 'A': tipo_texto = "Armadura"; break;
            case 'P': tipo_texto = "Pocion";   break;
            default:  tipo_texto = "Varios";   break;
        }
        printf("  %s  (%s)  %.1f kg\n", inv[i].nombre, tipo_texto, inv[i].peso);
    }

    printf("  Peso total: %.1f kg\n", inventario_peso(inv, cantidad));
}

void inventario_liberar(Item *inv, int cantidad)
{
    for (int i = 0; i < cantidad; i++) {
        free(inv[i].nombre);
    }
    free( inv );
}
