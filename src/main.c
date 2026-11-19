/* ===========================================================================
 * main.c  -  La Posada: el menu principal de Dungeon Quest.
 * ---------------------------------------------------------------------------
 * ESTE ARCHIVO CRECE CADA SEMANA.
 *
 * Cada laboratorio agrega un modulo nuevo (un .h en include/ y un .c en
 * src/) y una opcion a este menu. Al final del semestre, desde aqui se
 * juega todo el proyecto.
 *
 * Reglas de main.c:
 *   - aqui NO va la logica: solo el menu y las llamadas a los modulos
 *   - cada opcion termina con pausa() para que se alcance a leer
 *   - srand() se llama UNA vez, al principio
 * ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "entrada.h"
#include "hechizos.h"
#include "cronometro.h"
#include "guardian.h"
#include "inventario.h"
#include "bestiario.h"
#include "combate.h"

/* Prototipos: C lee de arriba a abajo. Si main() llama a una funcion que
 * esta escrita mas abajo, hay que anunciarla aqui o el compilador dice
 * "implicit declaration of function". 'static' = solo se ve en este archivo. */
static void mostrar_menu(void);
static void ver_hechizos(void);
static void ver_mochila(void);
static void explorar_dungeon(void);

int main(void)
{
    srand((unsigned) time(NULL));

    int opcion;
    do {
        mostrar_menu();
        opcion = get_int("  Tu opcion: ");

        switch (opcion) {
            case 1:
                ver_hechizos();
                pausa();
                break;
            case 2:
                cronometro_tabla();
                pausa();
                break;
            case 3:
                guardian_jugar(7);
                pausa();
                break;
            case 4:
                ver_mochila();
                pausa();
                break;
            case 5:
                explorar_dungeon();
                pausa();
                break;
            case 0:
                printf("\n  Hasta la proxima, aventurero.\n\n");
                break;

            default:
                printf("  Opcion invalida.\n");
                break;
        }
    } while (opcion != 0);

    return EXIT_SUCCESS;
}

static void mostrar_menu(void)
{
    printf("\n  ==========================================\n");
    printf("     DUNGEON QUEST  -  La Posada\n");
    printf("  ==========================================\n");
    printf("   1) Los hechizos del Lab 01, en C\n");
    printf("   2) El cronometro: C contra Python\n");
    printf("   3) La puerta del guardian\n");
    printf("   4) Mochila\n");
    printf("   5) Explorar el dungeon\n");
    printf("   0) Salir\n\n");
}

static void ver_hechizos(void)
{
    printf("\n  --- Los cuatro hechizos ---\n\n");
    printf("  mcd(1071, 462)  = %ld\n",  mcd(1071, 462));
    printf("  fibonacci(10)   = %lld\n", fibonacci(10));
    printf("  simple_loop(7)  = %ld\n",  simple_loop(7));
    printf("  double_loop(4)  = %ld\n",  double_loop(4));

    printf("\n  --- Lo que Python te ocultaba ---\n\n");
    printf("  fibonacci(92)   = %lld\n", fibonacci(92));
    printf("  fibonacci(93)   = %lld\n", fibonacci(93));
    printf("\n  Si fibonacci(93) te sale negativo: explicalo en docs/informe_lab06.md\n");
}

static void ver_mochila(void)
{
    Item *mochila = NULL;
    int n = 0, cap = 0;

    inventario_agregar(&mochila, &n, &cap, "Espada larga", 'W', 3.5f);
    inventario_agregar(&mochila, &n, &cap, "Botas de cuero", 'A', 1.2f);
    inventario_agregar(&mochila, &n, &cap, "Pocion de vida", 'P', 0.3f);
    inventario_agregar(&mochila, &n, &cap, "Moneda de oro",  'X', 0.01f);
    inventario_agregar(&mochila, &n, &cap, "Arco corto",     'W', 2.1f);
   
    inventario_imprimir( mochila , n );
    inventario_liberar( mochila , n);
}
static void explorar_dungeon(void)
{
    NodoEnemigo *bestiario = NULL;
    Luchador heroe = {"Heroe", 100, 12};

    bestiario_agregar(&bestiario, "Goblin", 20, 4);
    bestiario_agregar(&bestiario, "Orco",   35, 7);
    bestiario_agregar(&bestiario, "Troll",  50, 9);
    bestiario_agregar(&bestiario, "Dragon", 80, 15);

    printf("\n  --- Los enemigos del dungeon ---\n");
    bestiario_imprimir(bestiario);

    for (NodoEnemigo *e = bestiario; e != NULL && heroe.vida > 0; e = e->siguiente) {
        printf("\n  El heroe pelea contra %s...\n", e->nombre);
        if (combate_pelear(&heroe, e)) {
            printf("  Gana el heroe. Le quedan %d de vida.\n", heroe.vida);
        } else {
            printf("  El heroe cae derrotado.\n");
        }
    }

    bestiario_purgar(&bestiario);

    printf("\n  --- Los enemigos que quedan ---\n");
    bestiario_imprimir(bestiario);

    bestiario_liberar(bestiario);
}