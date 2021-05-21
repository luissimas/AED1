/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Implementar uma fila com atendimento prioritário

*/

// Bibliotecas
#include <iostream>
#include <string>

#include "pessoa/pessoa.h"
#include "queue/queue.h"
#include "queue/queue.cpp"

using namespace std;

// Função principal
int main(int argc, char *argv[])
{
  int op;
  Queue<Pessoa> queue;

  while (op != 4) {
    /* cout << "Opções: " << endl; */
    cout << "[1] Inserir pessoa." << endl;
    cout << "[2] Remover pessoa." << endl;
    cout << "[3] Imprimir fila." << endl;
    cout << "[4] Sair." << endl;
    cout << "Opção: ";
    cin >> op;

    switch (op) {
    case 1: {
      string nome;
      int idade;

      cout << "Inserindo uma nova pessoa: " << endl;
      cout << "Nome: ";
      cin >> nome;
      cout << "Idade: ";
      cin >> idade;

      Pessoa *newElement = new Pessoa(nome, idade);

      if (queue.push(newElement)) {
        cout << "Pessoa inserida com sucesso!" << endl;
      } else {
        cout << "Erro ao inserir pessoa" << endl;
      }

      delete newElement;

      break;
    }
    case 2: {
      Pessoa *removedElement = new Pessoa;

      if (queue.pop(removedElement)) {
        cout << removedElement->getNome() << " retirado com sucesso!" << endl;
      } else {
        cout << "Erro ao retirar pessoa" << endl;
      }

      delete removedElement;

      break;
    }
    case 3: {
      cout << "Pessoas na fila: " << endl;
      queue.printQueue();
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
