#pragma once
#include <iostream>

// Dado un numero N calcular la secuencia de 1 a N mediante un algoritmo
// recursivo...
int getN(int x);

// Dado dos numeros X e Y, escriba un programa que los lea e imprima desde el
// mayor hasta el menor.

void highToLow(int high, int low);

// Dado un numero, calcule su factorial con ayuda de la explicación de la
// persona docente...

int factorial(int x);

// Luego de un analisis de la secuencia de fibonacci, programar un algoritmo
// que dado una posición, obtenga el valor de la secuencia en esa posición.
// seq: 1 1 2 3 5 8 13

int fibo(int x);

// Dado un numero n, definir un algoritmo para invertirlo...
// con ayuda de las notas de su docente...
// sepa que: n % 10; Le devolver el ultimo digito de la secuencia.
// separa tambien que: n/ 10; Acortara el numero quitando el ultimo de la
// secuencia...
// finalmente, sepa que n * 10 + x, agrega a x al final de la secuencia..
// esto por que lo transforma en una unidad/decena/centena inicial...

int reverseNumber(int x, int reverse);

// dada una cadena, obtenga el inverso de la misma por medio de un algoritmo
// recursivo...Use la explicación del docente...
std::string reverseString(int idx, std::string ori, std::string dest);

// Con ayuda de la explicación del docente, trate de implementar un algoritmo
// que dado un array considerado un set, muestre los subconjuntos.

