/*

Autor(es): Luís Augusto Simas do Nascimento
RA: 790828
Data de Criação: 14/05/2021
Data de Atualização: 14/05/2021

Objetivos: Implementar os métodos de utilidade

*/

// Arquivo de cabeçalho
#include "utils.h"

void printStack(Stack *stack){
  Stack stackAux;
  stackElement element;

  create(&stackAux);

  if(empty(stack)){
    printf("A pilha está vazia!\n");
    return;
  }

  // Removendo os elementos da pilha e armazenando-os na pilha auxiliar
  while(!empty(stack)){
    pop(stack, &element);
    printf(" %c ", element);
    push(&stackAux, &element);
  }

  // Devolvendo os elementos para a pilha original
  while(!empty(&stackAux)){
    pop(&stackAux, &element);
    push(stack, &element);
  }

  printf("\n");
}

