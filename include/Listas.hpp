#ifndef __LISTAS_H__
#define __LISTAS_H__

#include <functional>
#include <iostream>

using namespace std;

class exampleData {
private:
  int value;

public:
  inline void setValue(int value) { this->value = value; }
  inline int getValue() { return value; }
};

struct Node {
  // continene la información del nodo/eslabon
  exampleData data;
  // constructor del nodo...
  inline Node(exampleData data) : data(data) {}
  // Puntero que apunta al siguiente...
  struct Node *next;
};

/*
• Añadir o insertar elementos.
• Buscar o localizar elementos.
• Borrar elementos.
• Moverse a través de una lista, anterior, siguiente, primero.
*/

// CAP 1. Lista simples...

// Diseñe un algoritmo para insertar un elemento en una lista vacia...
/*
  1. nodo->siguiente apunte a NULL.
  2. Lista apunte a nodo.
*/
void insertarVacia(Node *&lista, exampleData data);

// Diseñe un algoritmo para insertar un elemento al principio de una lista...
/*
    1. Hacemos que nodo->siguiente apunte a Lista.
    2. Hacemos que Lista apunte a nodo.
 */
void insertarInicio(Node *&lista, exampleData data);

// diseñe un algoritmo para recorrer una lista simple..
/*
  1. Asignamos al puntero índice el valor de Lista.
  2. Abriremos un bucle que al menos debe tener una condición, que el índice
  no sea NULL.
  3. Dentro del bucle asignaremos al índice el valor del nodo siguiente al
  índice actual.
*/
void recorrido(Node *lista);

// diseñe un algoritmo que muestre los elementos de una lista de acuerdo a una
// función filtro..
void filtrarLista(Node *lista, std::function<bool(exampleData)> filter);

// Diseñe un algoritmo para insertar un elemento al final de una lista...
/*
  1. Necesitamos un puntero que señale al último elemento de la lista. La
  manera de conseguirlo es empezar por el primero y avanzar hasta que el
  nodo que tenga como siguiente el valor NULL.
  2. Hacer que nodo->siguiente sea NULL.
  3. Hacer que ultimo->siguiente sea nodo.
*/
void insertarFinal(Node *&lista, exampleData data);

// Diseñe un algoritmo para insertar un elemento en un nudo cualquiera de una
// lista...

// NOTE: index es el elemento anterior a donde quiero insertar...
/*
  1. Hacer que nodo->siguiente señale a anterior->siguiente.
  2. Hacer que anterior->siguiente señale a nodo.
*/
int insertarCualquier(Node *&lista, exampleData data, int index);

// Diseñe un algoritmo para eliminar el primer nodo de una lista abierta...
/*
  1. Hacemos que nodo apunte al primer elemento de la lista, es decir a Lista.
  2. Asignamos a Lista la dirección del segundo nodo de la lista: Lista-
  >siguiente.
  3. Liberamos la memoria asignada al primer nodo, el que queremos eliminar.
*/
void eliminaPrimero(Node *&lista);
// Diseñe un algoritmo para eliminar un elemento cualquiera de la lista
// abierta.. index es el elemento siguiente...
/*
  1. Hacemos que nodo apunte al nodo que queremos borrar.
  2. Ahora, asignamos como nodo siguiente del nodo anterior, el siguiente al
  que queremos eliminar: anterior->siguiente = nodo->siguiente.
  3. Eliminamos la memoria asociada al nodo que queremos eliminar.
*/
int eliminaCualquier(Node *&lista, int index);

// Diseñe un algoritmo para ELIMINAR una lista por completo...
/*
  El algoritmo genérico para borrar una lista completa consiste simplemente en
  borrar el primer elemento sucesivamente mientras la lista no esté vacía.
*/
void vaciarLista(Node *&lista, int index);

// Ejemplo de una lista abierta, y ordenada...
/*
  1. El primer paso es crear un nodo para el dato que vamos a insertar.

  2. Si Lista es NULL, o el valor del primer elemento de la lista es mayor que
  el del nuevo, insertaremos el nuevo nodo en la primera posición de la lista.

  3. En caso contrario, buscaremos el lugar adecuado para la inserción,
  tenemos un puntero "anterior". Lo inicializamos con el valor de Lista, y
  avanzaremos mientras anterior->siguiente no sea NULL y el dato que
  contiene anterior->siguiente sea menor o igual que el dato que queremos
  insertar.

  4. Ahora ya tenemos anterior señalando al nodo adecuado, así que insertamos
  el nuevo nodo a continuación de él.
*/
void insertarOrdenado(Node *&lista, exampleData data);
/*
   1. Lo primero será localizar el nodo a eliminar, si es que existe. Pero sin
   perder el puntero al nodo anterior. Partiremos del nodo primero, y del valor
   NULL para anterior. Y avanzaremos mientras nodo no sea NULL o
   mientras que el valor almacenado en nodo sea menor que el que buscamos.

   2. Ahora pueden darse tres casos:

   3. Que el nodo sea NULL, esto indica que todos los valores almacenados en la
   lista son menores que el que buscamos y el nodo que buscamos no existe.
   Retornaremos sin borrar nada.

   4. Que el valor almacenado en nodo sea mayor que el que buscamos, en ese
   caso también retornaremos sin borrar nada, ya que esto indica que el nodo
   que buscamos no existe.

   5. Que el valor almacenado en el nodo sea igual al que buscamos.

   6. De nuevo existen dos casos:
   7. Que anterior sea NULL. Esto indicaría que el nodo que queremos borrar es
   el primero, así que modificamos el valor de Lista para que apunte al nodo
   siguiente al que queremos borrar.

   8. Que anterior no sea NULL, el nodo no es el primero, así que asignamos a
   anterior->siguiente la dirección de nodo->siguiente.

   9. Después de 7 u 8, liberamos la memoria de nodo.
 */
void eliminarOrdenado(Node *&lista, exampleData data);

// usando clases...

// * Tarea: IDENTIFICAR que metodos faltan en la clase, e implementarlos.
// * Tarea: IMPLEMENTAR la sobrecarga del operador ==, y RECORRIENDO toda la
// * lista Hacer la sobrecarga apropiada.

class nodo {
public:
  nodo(int v, nodo *sig = NULL) {
    valor = v;
    siguiente = sig;
  }

private:
  int valor;
  nodo *siguiente;
  friend class lista;
};

typedef nodo *pnodo;
class lista {
public:
  lista() { primero = actual = NULL; }
  ~lista();
  void Insertar(int v);
  void Borrar(int v);
  bool ListaVacia() { return primero == NULL; }
  void Mostrar();
  void Siguiente() {
    if (actual)
      actual = actual->siguiente;
  }
  void Primero() { actual = primero; }
  void Ultimo() {
    Primero();
    if (!ListaVacia())
      while (actual->siguiente)
        Siguiente();
  }
  bool Actual() { return actual != NULL; }
  int ValorActual() { return actual->valor; }

private:
  pnodo primero;
  pnodo actual;
};

lista::~lista() {
  pnodo aux;
  while (primero) {
    aux = primero;
    primero = primero->siguiente;
    delete aux;
  }
  actual = NULL;
}
void lista::Insertar(int v) {
  pnodo anterior;
  // Si la lista está vacía
  if (ListaVacia() || primero->valor > v) {
    // Asignamos a lista un nuevo nodo de valor v y
    // cuyo siguiente elemento es la lista actual
    primero = new nodo(v, primero);
  } else {
    // Buscar el nodo de valor menor a v
    anterior = primero;
    // Avanzamos hasta el último elemento o hasta que el
    // siguiente tenga un valor mayor que v
    while (anterior->siguiente && anterior->siguiente->valor <= v)
      anterior = anterior->siguiente;
    // Creamos un nuevo nodo después del nodo anterior, y cuyo
    // siguiente
    // es el siguiente del anterior

    anterior->siguiente = new nodo(v, anterior->siguiente);
  }
}
void lista::Borrar(int v) {
  pnodo anterior, nodo;
  nodo = primero;
  anterior = NULL;
  while (nodo && nodo->valor < v) {
    anterior = nodo;
    nodo = nodo->siguiente;
  }
  if (!nodo || nodo->valor != v)
    return;
  else {           // Borrar el nodo
    if (!anterior) // Primer elemento
      primero = nodo->siguiente;
    else // un elemento cualquiera
      anterior->siguiente = nodo->siguiente;
    delete nodo;
  }
}
void lista::Mostrar() {
  nodo *aux;
  aux = primero;
  while (aux) {
    cout << aux->valor << "-> ";
    aux = aux->siguiente;
  }
  cout << endl;
}

#endif // __LISTAS_H__