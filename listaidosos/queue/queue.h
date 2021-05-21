/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Arquivo de cabeçalho da classe Queue

A classe queue representa uma fila de espera implementada através
de uma lista cadastral.

*/

#ifndef QUEUE_H
#define QUEUE_H

// Bibliotecas
#include <iostream>
#include <string>

#include "../baselist/baselist.h"
#include "../baselist/baselist.cpp"

using namespace std;

template <class elementType>
class Queue: public BaseList<elementType>{
public:
  bool push(elementType *element);
  bool pop(elementType *element);

  void printQueue();
};

#endif
