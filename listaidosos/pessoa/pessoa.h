/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Arquivo de cabeçalho da classe Pessoa

*/

#ifndef PESSOA_H
#define PESSOA_H

// Bibliotecas
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
  string nome;
  int idade;

public:
  Pessoa();
  Pessoa(string _nome, int _idade);

  string getNome() const;
  int getIdade() const;

  void setNome(string _nome);
  void setIdade(int _idade);

  bool operator>(const Pessoa &operando);
  bool operator<(const Pessoa &operando);
  bool operator==(const Pessoa &operando);

  friend ostream &operator<<(ostream &out, const Pessoa &operando);
};

#endif
