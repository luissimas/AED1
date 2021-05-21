/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Implementar os métodos da classe Queue

*/

// Arquivo de cabeçalho
#include "queue.h"

using namespace std;

template <class elementType>
bool Queue<elementType>::push(elementType *element) {
  // Verifica se o elemento já está na lista
  if (BaseList<elementType>::isInList(element, NULL)) {
    return false;
  }

  // Elemento auxiliar para armazenar os valores retornados pela lista
  elementType elementAux;

  // Variável de controle
  bool found = false;

  // Determinando em qual posição o elemento será adicionado
  BaseList<elementType>::getFirst(&elementAux);

  // Atribuindo ao header da lista um elemento padrão
  BaseList<elementType>::getHeader()->setData(new elementType);

  do {
    // A lista respeita a ordem decrescente dos elementos
    // 70
    // 75 54 47 34
    // Caso o elemento tenha sido encontrado ou tenhamos chego ao final da lista
    if (*element > BaseList<elementType>::getCurrent()->getData()) {
      found = true;
    }
  } while (!found && BaseList<elementType>::getNext(&elementAux));

  // Inserindo o elemento antes do elemento apontado pelo current atual da lista
  return BaseList<elementType>::insertNode(
      BaseList<elementType>::getCurrent()->getPrev(), element);
}

template <class elementType>
bool Queue<elementType>::pop(elementType *element) {
  // Obtendo o valor do primeiro elemento da lista
  BaseList<elementType>::getData(BaseList<elementType>::getHeader()->getNext(),
                                 element);

  // Removendo o primeiro elemento da lista
  return BaseList<elementType>::removeNode(
      BaseList<elementType>::getHeader()->getNext());
}

template <class elementType> void Queue<elementType>::printQueue() {
  if (BaseList<elementType>::empty()) {
    cout << "A fila está vazia!" << endl;
    return;
  }

  // Elemento auxiliar
  elementType *elementAux = new elementType;

  BaseList<elementType>::getFirst(elementAux);

  // Exibindo todos os elementos
  do {
    cout << *elementAux << endl;
  } while (BaseList<elementType>::getNext(elementAux) &&
           (BaseList<elementType>::getCurrent() !=
            BaseList<elementType>::getHeader()));

  cout << endl;
}
