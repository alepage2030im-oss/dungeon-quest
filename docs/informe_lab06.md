# Informe — Lab 06 · La Forja

**Nombre:**
**Repositorio:**

---

## 1. El cronómetro: C contra Python

Pega la tabla que imprime la opción 2 del menú y completa la última columna con tus tiempos de
Python del Lab 01 (los que tengas; si no mediste algún `n`, déjalo en blanco).

| función | n | segundos en C | segundos en Python |
|---|---|---|---|
| `simple_loop` | 1 000 000 |0.0060000 |0.0702 |
| `simple_loop` | 10 000 000 |0.031000 |0.5850|
| `simple_loop` | 100 000 000 | 0.236000|7.5251 |
| `double_loop` | 1 000 | 0.003000|0.0554|
| `double_loop` | 3 000 |0.021000 |0.5209  |
| `double_loop` | 10 000 |0.241000 |5.9045|

**¿Cuántas veces más rápido es C?**
    C es en promedio unas 25 a 30 veces más rápido que python
**¿Cambió la forma de la curva, o solo la constante? ¿Por qué?**
    la curva no cambia, en C y en Python el tiempo crece linealmente en simple_loop y cuadráticamente en double_loop, porque hace la misma cantidad de vueltas. Lo que cambió fue la constante, C es unas 25 a 30 veces más rápido porque cada vuelta cuesta mucho menos al estar compilado.”

---

## 2. El desbordamiento

¿Qué imprime `fibonacci(93)`? Explica con tus palabras por qué sale ese número.
fibonacci(92)= 7540112804746346429
fibonacci(93)= -6246583658587674878
el que de negativo el valor de fibonacci(93) es porque el valor real, 12 200 160 415 121 876 738, es mayor que el máximo que cabe en un long long (9 223 372 036 854 775 807). Un long long solo tiene 64 bits, así que cuando la suma a + b se pasa del máximo, el número “da la vuelta” y sigue desde el extremo negativo del rango. Python no tiene este problema porque sus enteros crecen sin límite. Lo peligroso de C es que no avisa: no hay error ni excepción, el programa solo sigue como si nada

---

## 3. Rompe el compilador

Provoca cada error a propósito, copia el mensaje **exacto** del compilador y explícalo.
Después déjalo arreglado: el repositorio tiene que compilar.

| Lo que hiciste | Mensaje del compilador | Qué significa |
|---|---|---|
| quitar un `;` | error: expected ',' or ';' before 'a'| no hubo un punto y coma luego de la liena de codigo y en C simpre despues de cada linea de codigo debe de haber un punto y coma |
| usar una variable sin declararla |error: 'b' undeclared (first use in this function) |no se declaro la variable b en el primer recorrido de la funcion |
| `int x = "hola";` |error: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion] |no se puede poner una variable de tipo char cuando se ha declarado que es tipo int |
| una función `int` sin `return` |warning: control reaches end of non-void function [-Wreturn-type]|no da un error como tal solo da una advertencia de que el algoritmo de la funcion nunca termine|
| llamar a `mcd` sin el `#include "hechizos.h"` |error: implicit declaration of function 'mcd' [-Wimplicit-function-declaration] |se llamo a mcd pero el compilador no sabe a que funcion esta llamando |

---

## 4. El repositorio

- Enlace a tu repositorio:
    https://github.com/alepage2030im-oss/dungeon-quest
- ¿Cuántos commits hiciste? Pega la salida de `git log --oneline`:
hice en total 6 comits
```
15daae2 final
0ee48ed mini cambio en main y informe
70d828e main y mini arreglos en guardian y cronometro
c9bc3bb guardian
4ec50da cronometro
19fa9df ,
d97b8c0 Initial commit
```
