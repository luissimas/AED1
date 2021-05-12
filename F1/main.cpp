/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 08/05/2021
Data de Atualização: 08/05/2021

Objetivos: Testar a implementação do TAD Fila.

*/

// Bibliotecas
#include <iostream>
#include <string>

#include "fila.h"

using namespace std;

void imprimirFila(const Fila *fila);

// Função principal
int main(int argc, char *argv[]) {
  Fila fila;

  for (int i = 0; i < 18; i = i + 2) {
    fila.inserir(i);
  }

  imprimirFila(&fila);

  return 0;
}

void imprimirFila(const Fila *fila) {
  if (fila->vazia()) {
    cout << "A fila está vazia!" << endl;
    return;
  }

  if (fila->cheia()) {
    cout << "A fila está cheia!" << endl;
  }

  Fila filaAux = *fila;
  elementoFila elemento;

  while (!filaAux.vazia()) {
    if (filaAux.retirar(elemento)) {
      cout << elemento << endl;
    }
  }
}
