#include "../include/Recursividad.hpp"

const int elementSize = 4;                // numeros de elementos...
int elements[elementSize] = {0, 1, 2, 3}; // los elementos...
bool boolean[2] = {false};
int a;

// tarea de subconjuntos, pueden usar:
// https://pythontutor.com/render.html#mode=edit
void subconjuntos(int i) {
  if (i == elementSize) {
    for (size_t j = 0; j < elementSize; j++) {
      if (boolean[j]) {
        std::cout << elements[j] << "";
        a = elements[j];
      }
    }
    std::cout << std::endl;
    return;
  }
  boolean[i] = true;   // tomar...
  subconjuntos(i + 1); // 3 | 2
  boolean[i] = false;  // no tomar...
  subconjuntos(i + 1); //
}

int main() {
  // code
  subconjuntos(0);
  return 0;
}
