#include "../include/Recursividad.hpp"

// Problemas con recursividad...

// Dado un numero N calcular la secuencia de 1 a N mediante un algoritmo
// recursivo...

int getN(int x) {
  if (x == 1)
    return x;
  std::cout << getN(x - 1) << std::endl;
  return x;
}

// otra posible solución...
void getN(double x) {
  if (x == 0)
    return;
  getN(x - 1);
  std::cout << x << std::endl;
}

// Dado dos numeros X e Y, escriba un programa que los lea e imprima desde el
// mayor hasta el menor.

void highToLow(int high, int low) {
  if (high < low)
    return;
  std::cout << high << std::endl;
  highToLow(high - 1, low);
}

// Dado un numero, calcule su factorial con ayuda de la explicación de la
// persona docente...

int factorial(int x) {
  // x -> 0
  if (!x) {
    return 1;
  }
  return factorial(x - 1) * x;
}

// Luego de un analisis de la secuencia de fibonacci, programar un algoritmo
// que dado una posición, obtenga el valor de la secuencia en esa posición.
// seq: 1 1 2 3 5 8 13

int fibo(int x) {
  if (x == 2 or x == 1) {
    return 1;
  }
  return fibo(x - 1) + fibo(x - 2);
}

// Dado un numero n, definir un algoritmo para invertirlo...
// con ayuda de las notas de su docente...
// sepa que: n % 10; Le devolver el ultimo digito de la secuencia.
// separa tambien que: n/ 10; Acortara el numero quitando el ultimo de la
// secuencia...
// finalmente, sepa que n * 10 + x, agrega a x al final de la secuencia..
// esto por que lo transforma en una unidad/decena/centena inicial...

int reverseNumber(int x, int reverse) {
  // x -> 0
  if (!x) {
    // Ya no quedan numeros en x
    return reverse;
  }
  // Le quitamos el ultimo digito a x, y se lo agregamos a reverse...
  return reverseNumber(x / 10, (reverse * 10) + (x % 10));
}

// dada una cadena, obtenga el inverso de la misma por medio de un algoritmo
// recursivo...Use la explicación del docente...
std::string reverseString(int idx, std::string ori, std::string dest) {
  if (ori.size() == idx) {
    return dest;
  }
  return reverseString(idx + 1, ori, ori[idx] + dest);
}

// Con ayuda de la explicación del docente, trate de implementar un algoritmo
// que dado un array considerado un set, muestre los subconjuntos.

// void subconjuntos(int i);