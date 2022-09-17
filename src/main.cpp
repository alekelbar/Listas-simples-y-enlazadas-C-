#include "../include/Listas.hpp"

int main() {
  lista Lista;
  Lista.Insertar(20);
  Lista.Insertar(10);
  Lista.Insertar(40);
  Lista.Insertar(30);
  Lista.Mostrar();
  cout << "Lista de elementos:" << endl;
  Lista.Primero();
  while (Lista.Actual()) {
    cout << Lista.ValorActual() << endl;
    Lista.Siguiente();
  }
  Lista.Primero();
  cout << "Primero: " << Lista.ValorActual() << endl;
  Lista.Ultimo();
  cout << "Ultimo: " << Lista.ValorActual() << endl;
  Lista.Borrar(10);
  Lista.Borrar(15);
  Lista.Borrar(45);
  Lista.Borrar(30);
  Lista.Borrar(40);
  Lista.Mostrar();
  return 0;
}
