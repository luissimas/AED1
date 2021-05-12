/*

Autor(es): Luís Augusto Simas do Nascimento
RA: 790828
Data de Criação: 08/05/2021
Data de Atualização: 12/05/2021

Objetivos: Testar a implementação do TAD Fila.

*/

// Bibliotecas
#include <iostream>
#include <string>

#include "fila.h"

using namespace std;

// Cabeçalho da função para imprimir os elementos da fila
void imprimirFila(const Fila *fila);

// Função principal
int main(int argc, char *argv[]) {
  Fila fila;
  int opcao = 0;

  while (opcao != 4) {
    /* cout << "Opções: " << endl; */
    cout << "[1] Inserir elemento." << endl;
    cout << "[2] Remover elemento." << endl;
    cout << "[3] Imprimir fila." << endl;
    cout << "[4] Sair." << endl;
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
    case 1: {
      int *novoElemento = new int;

      cout << "Digite o valor do novo elemento: ";
      cin >> *novoElemento;

      if (fila.inserir(novoElemento)) {
        cout << "Elemento inserido com sucesso!" << endl;
      } else {
        cout << "Erro ao inserir elemento" << endl;
      }

      novoElemento = 0;
      delete novoElemento;
      break;
    }
    case 2: {
      elementoFila *elementoRetirado = new elementoFila;

      if (fila.retirar(elementoRetirado)) {
        cout << "Elemento retirado com sucesso!" << endl;
      } else {
        cout << "Erro ao retirar elemento" << endl;
      }

      elementoRetirado = 0;
      delete elementoRetirado;
      break;
    }
    case 3: {
      cout << "Elementos da fila: " << endl;
      imprimirFila(&fila);
      cout << "Digite ENTER para continuar...";
      getchar();
      getchar();
      break;
    }
    case 4: {
      cout << "Saindo..." << endl;
      break;
    }
    default:
      cout << "Opção inválida" << endl;
      ;
    }

    cout << endl;
  }

  return 0;
}

/*
  Os elementos da fila são impressos copiando a fila passada
  como parâmetro para uma fila auxiliar, cujos elementos serão
  retirados e exibidos. Dessa forma é possível exibir os elementos
  sem alterar a fila e utilizando apenas os métodos definidos no TAD.
*/
void imprimirFila(const Fila *fila) {
  if (fila->vazia()) {
    cout << "A fila está vazia!" << endl;
    return;
  }

  if (fila->cheia()) {
    cout << "A fila está cheia!" << endl;
  }

  Fila filaAux = *fila;
  elementoFila *elemento = new elementoFila;

  while (!filaAux.vazia()) {
    if (filaAux.retirar(elemento)) {
      cout << *elemento << "   ";
    }
  }

  cout << endl;
}
