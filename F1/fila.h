/*

Autor(es): Luís Augusto Simas do Nascimento
RA: 790828
Data de Criação: 08/05/2021
Data de Atualização: 12/05/2021

Objetivos: Arquivo de cabeçalho da classe Fila, que representa
uma fila utilizando o conceito de vetor circular

*/

#ifndef FILA_H
#define FILA_H

// Bibliotecas
#include <iostream>
#include <string>

using namespace std;

// Tamanho máximo definido pois estamos utilizando alocação estática
#define TAMANHOMAX 10
/*
  Typedef para definir o tipo de elemento da fila. Nesse caso específico
  não é necessário, porém facilita a manutenção do código caso em algum
  momento seja necessário utilizar um tipo diferente de dados para representar
  os elementos.
*/
typedef int elementoFila;

/*
  enum para armazenar de forma mais clara qual foi a última operação realizada
  na fila
*/
enum operacoes : unsigned short int { insercao, remocao };

class Fila {
private:
  int primeiro;
  int ultimo;
  operacoes ultimaOperacao;
  elementoFila elementos[TAMANHOMAX];

public:
  Fila();

  // Retorna true caso a fila não tenha nenhum elemento, e false caso contrário
  bool vazia() const;

  // Retorna true caso a fila esteja cheia, e false caso contrário
  bool cheia() const;

  // Insere um elemento na fila e retorna um bool indicando sucesso/fracasso
  bool inserir(elementoFila *elemento);

  // Remove um elemento da fila e o retorna por referência, também retorna um b
  // ol indicando sucesso/fracasso
  bool retirar(elementoFila *elemento);
};

#endif
