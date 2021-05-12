/*

Autor(es): Luís Augusto Simas do Nascimento
RA: 790828
Data de Criação: 08/05/2021
Data de Atualização: 12/05/2021

Objetivos: Implementar os métodos da classe fila

*/

// Arquivo de cabeçalho
#include "fila.h"

using namespace std;

Fila::Fila() : primeiro(0), ultimo(0), ultimaOperacao(remocao){};

bool Fila::vazia() const {
  return ((primeiro == ultimo) && (ultimaOperacao == remocao));
}

bool Fila::cheia() const {
  return ((primeiro == ultimo) && (ultimaOperacao == insercao));
}

bool Fila::inserir(elementoFila *elemento) {
  if (cheia()) {
    return false;
  }

  int lengthElementos = (sizeof(elementos) / sizeof(elementoFila));

  elementos[ultimo] = *elemento;

  if (ultimo == (lengthElementos - 1)) {
    ultimo = 0;
  } else {
    ultimo++;
  }

  ultimaOperacao = insercao;

  return true;
}

bool Fila::retirar(elementoFila *elemento) {
  if (vazia()) {
    return false;
  }

  int lengthElementos = (sizeof(elementos) / sizeof(elementoFila));

  *elemento = elementos[primeiro];

  if (primeiro == (lengthElementos - 1)) {
    primeiro = 0;
  } else {
    primeiro++;
  }

  ultimaOperacao = remocao;

  return true;
}
