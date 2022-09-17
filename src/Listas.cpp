
#include "./../include/Listas.hpp"

/*
• Añadir o insertar elementos.
• Buscar o localizar elementos.
• Borrar elementos.
• Moverse a través de una lista, anterior, siguiente, primero.
*/

// CAP 1. Lista simples...

void insertarVacia(Node *&lista, exampleData data) {
  if (!lista) {
    Node *newNode = new Node(data);
    newNode->next = NULL;
    lista = newNode;
  }
}

void insertarInicio(Node *&lista, exampleData data) {
  if (lista) {
    Node *newNode = new Node(data);
    newNode->next = lista;
    lista = newNode;
  }
}

void recorrido(Node *lista) {

  if (lista) {
    Node *node = lista;
    while (node) {
      std::cout << node->data.getValue() << std::endl;
      node = node->next;
    }
  }
}

void filtrarLista(Node *lista, std::function<bool(exampleData)> filter) {
  if (lista) {
    Node *node = lista;
    while (node) {
      if (filter(node->data)) {
        std::cout << node->data.getValue() + ", " << std::endl;
      }
      node = node->next;
    }
  }
}

void insertarFinal(Node *&lista, exampleData data) {

  if (lista) {
    Node *aux = lista;
    while (aux) {
      aux = aux->next;
    }

    Node *newNode = new Node(data);
    newNode->next = NULL;
    aux->next = newNode;
  }
}

int insertarCualquier(Node *&lista, exampleData data, int index) {
  if (lista) {
    int cont = 0;
    Node *aux = lista;
    while (aux && cont < index) {
      aux = aux->next;
      cont++;
    }
    if (cont < index)
      return -1;

    Node *newNode = new Node(data);
    newNode->next = aux->next;
    aux->next = newNode;
  }

  // 1 si fue un exito, o la lista esta vacia...
  return 1;
}

void eliminaPrimero(Node *&lista) {

  if (lista) {
    Node *aux = lista;
    lista = lista->next;
    delete aux;
  }
}

int eliminaCualquier(Node *&lista, int index) {
  if (lista) {
    int cont = 0;
    Node *aux = lista;
    while (aux && cont < index) {
      aux = aux->next;
      cont++;
    }
    if (cont < index)
      return -1;

    // si existe un siguiente, es el que queremos eliminar..
    if (!aux->next) {
      Node *node = aux->next;
      aux->next = node->next; // Si es el ultimo, será NULL
      delete node;
    }
  }
  return 1;
}

void vaciarLista(Node *&lista, int index) {

  if (lista) {
    Node *node = lista;
    Node *toDelete = NULL;
    while (node) {
      toDelete = node;
      node = node->next;
      delete toDelete;
    }
  }
}

void insertarOrdenado(Node *&lista, exampleData data) {

  Node *newNode = new Node(data);
  if (!lista || lista->data.getValue() > data.getValue()) {
    insertarInicio(lista, data);
  } else {
    // * NOTE: Se llama anterior por que se posicionara una posicioón antes del
    // * objetivo..
    Node *anterior = lista;
    while (anterior->next &&
           anterior->next->data.getValue() <= data.getValue()) {
      anterior = anterior->next;
    }

    Node *node = new Node(data);
    node->next = anterior->next;
    // * NOTE: En caso de ser el ultimo, me devuelve el puntero, no NULL...
    anterior->next = node;
  }
}

void eliminarOrdenado(Node *&lista, exampleData data) {

  Node *anterior = NULL;
  Node *node = lista;
  while (node || node->data.getValue() < data.getValue()) {
    /* code */
    anterior = node;
    node = node->next;
  }

  if (!node || node->data.getValue() != data.getValue())
    return;

  if (!anterior) {
    // Esto es en retrospectiva, dejar la lista vacia en NULL...
    lista = node->next;
  } else {
    // Este caso se da si node apunta al primero...
    anterior->next = node->next;
  }
  delete node;
}
