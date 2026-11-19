/* ===========================================================================
 * test_lab08.c  -  Pruebas del Lab 08: el bestiario y el combate. NO LO MODIFIQUES: es tu meta.
 * ========================================================================= */

#include <string.h>

#include "prueba.h"
#include "bestiario.h"
#include "combate.h"

/* Cuantos nodos tiene la lista (se detiene si encuentra un ciclo). */
static int contar(const NodoEnemigo *e)
{
    int n = 0;
    for (; e != NULL && n <= 1000; e = e->siguiente) {
        n++;
    }
    return n;
}

/* Los nombres de la lista, separados por comas. */
static void como_texto(const NodoEnemigo *e, char *out, int largo)
{
    out[0] = '\0';
    for (int n = 0; e != NULL && n < 50; e = e->siguiente, n++) {
        if (out[0] != '\0') {
            strncat(out, ",", largo - strlen(out) - 1);
        }
        strncat(out, e->nombre ? e->nombre : "?", largo - strlen(out) - 1);
    }
}

/* El nodo numero i (0 = la cabeza), o NULL. */
static NodoEnemigo *nodo(NodoEnemigo *e, int i)
{
    for (; e != NULL && i > 0; e = e->siguiente, i--) {
    }
    return e;
}

int main(void)
{
    char lista[256];

    printf("\n  Pruebas del Lab 08 - El Bestiario\n");
    printf("  --------------------------------\n");

    /* ===================== AGREGAR ===================== */
    NodoEnemigo *b = NULL;
    VERIFICAR(bestiario_agregar(&b, "Goblin", 20, 4) == 1, "agregar a una lista vacia devuelve 1");
    VERIFICAR(b != NULL && b->siguiente == NULL, "con un enemigo, la cabeza existe y su siguiente es NULL");
    bestiario_agregar(&b, "Orco", 35, 7);
    bestiario_agregar(&b, "Dragon", 80, 15);
    como_texto(b, lista, sizeof lista);
    VERIFICAR(strcmp(lista, "Goblin,Orco,Dragon") == 0, "agregar pone al final: Goblin,Orco,Dragon");
    VERIFICAR(contar(b) == 3, "la lista tiene 3 enemigos");
    VERIFICAR(nodo(b, 2) != NULL && nodo(b, 2)->vida == 80 && nodo(b, 2)->ataque == 15,
              "el Dragon guarda vida 80 y ataque 15");

    char buffer[32] = "Troll";
    bestiario_agregar(&b, buffer, 50, 9);
    strcpy(buffer, "zzzz");
    VERIFICAR(nodo(b, 3) != NULL && nodo(b, 3)->nombre != NULL && strcmp(nodo(b, 3)->nombre, "Troll") == 0,
              "el nombre es una copia: cambiar el original no lo afecta");

    /* ===================== INSERTAR ===================== */
    bestiario_insertar(&b, 0, "Rata", 5, 1);
    VERIFICAR(b != NULL && b->nombre && strcmp(b->nombre, "Rata") == 0, "insertar en 0 cambia la cabeza");
    bestiario_insertar(&b, 2, "Murcielago", 8, 2);
    como_texto(b, lista, sizeof lista);
    VERIFICAR(strcmp(lista, "Rata,Goblin,Murcielago,Orco,Dragon,Troll") == 0,
              "insertar en 2 lo deja en la tercera posicion");
    bestiario_insertar(&b, 99, "Esqueleto", 15, 3);
    VERIFICAR(contar(b) == 7 && nodo(b, 6) && nodo(b, 6)->nombre && strcmp(nodo(b, 6)->nombre, "Esqueleto") == 0,
              "insertar mas alla del largo lo pone al final");
    bestiario_insertar(&b, -3, "Slime", 3, 1);
    VERIFICAR(b != NULL && b->nombre && strcmp(b->nombre, "Slime") == 0 && contar(b) == 8,
              "insertar en una posicion negativa lo pone al principio");

    /* ===================== PURGAR ===================== */
    /* Slime,Rata,Goblin,Murcielago,Orco,Dragon,Troll,Esqueleto: caen los dos
     * primeros, dos seguidos en medio y el ultimo */
    int caen[] = {0, 1, 3, 4, 7};
    for (int i = 0; i < 5; i++) {
        if (nodo(b, caen[i])) {
            nodo(b, caen[i])->vida = 0;
        }
    }
    bestiario_purgar(&b);
    como_texto(b, lista, sizeof lista);
    VERIFICAR(strcmp(lista, "Goblin,Dragon,Troll") == 0,
              "purgar quita a los derrotados: al principio, en medio (seguidos) y al final");
    VERIFICAR(contar(b) == 3, "despues de purgar quedan 3");

    for (NodoEnemigo *e = b; e != NULL; e = e->siguiente) {
        e->vida = -5;
    }
    bestiario_purgar(&b);
    VERIFICAR(b == NULL, "si todos caen, la lista queda vacia (cabeza NULL)");
    bestiario_purgar(&b);
    VERIFICAR(b == NULL, "purgar una lista vacia no hace nada");

    bestiario_liberar(b);
    b = NULL;
    bestiario_agregar(&b, "Lobo", 12, 3);
    bestiario_agregar(&b, "Oso", 40, 8);
    bestiario_liberar(b);          /* si no libera bien, el detector de fugas lo ve */
    b = NULL;

    /* ===================== COMBATE ===================== */
    NodoEnemigo goblin = {"Goblin", 25, 5, NULL};
    Luchador heroe = {"Heroe", 100, 10};
    VERIFICAR(combate_pelear(&heroe, &goblin) == 1, "el heroe (100/10) le gana al goblin (25/5)");
    VERIFICAR(goblin.vida <= 0, "el goblin derrotado queda con vida <= 0");
    VERIFICAR(heroe.vida == 90, "el heroe recibe 2 golpes de 5: queda con 90 (golpea primero)");

    NodoEnemigo dragon = {"Dragon", 50, 20, NULL};
    Luchador novato = {"Novato", 10, 1};
    VERIFICAR(combate_pelear(&novato, &dragon) == 0, "el novato (10/1) pierde contra el dragon (50/20)");
    VERIFICAR(novato.vida <= 0 && dragon.vida == 49, "las vidas de los dos quedan modificadas");

    NodoEnemigo estatua = {"Estatua", 30, 0, NULL};
    Luchador pacifista = {"Pacifista", 30, 0};
    VERIFICAR(combate_pelear(&pacifista, &estatua) == 0 && estatua.vida == 30,
              "si nadie puede hacer dano, devuelve 0 sin pelear (y no se cuelga)");

    return RESUMEN("Lab 08 (bestiario y combate)");
}
