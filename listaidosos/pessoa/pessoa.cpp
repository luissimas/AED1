/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Implementar os métodos da classe Pessoa

*/

// Arquivo de cabeçalho
#include "pessoa.h"

using namespace std;

Pessoa::Pessoa() : nome(" "), idade(0) {}

Pessoa::Pessoa(string _nome, int _idade) : nome(_nome), idade(_idade) {}

string Pessoa::getNome() const { return nome; }
int Pessoa::getIdade() const { return idade; }

void Pessoa::setNome(string _nome) { nome = _nome; }
void Pessoa::setIdade(int _idade) { idade = _idade; }

bool Pessoa::operator>(const Pessoa &operando) {
  return (this->idade > operando.getIdade());
}

bool Pessoa::operator<(const Pessoa &operando) {
  return (this->idade < operando.getIdade());
}

bool Pessoa::operator==(const Pessoa &operando) {
  return ((this->idade == operando.getIdade()) && (this->nome == operando.getNome()));
}

ostream &operator<<(ostream &out, const Pessoa &operando) {
  out << operando.getNome() << endl;
  out << operando.getIdade();
  return out;
}
