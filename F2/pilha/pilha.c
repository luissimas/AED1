/*

Autor(es): Luís Augusto Simas do Nascimento
RA: 790828
Data de Criação: 14/05/2021
Data de Atualização: 14/05/2021

Objetivos: Implementar os métodos do TAD pilha

*/

// Arquivo de cabeçalho
#include "pilha.h"

// Cria uma pilha vazia
void create(Stack *stack) { stack->head = NULL; }

// Adiciona um novo elemento no topo da pilha.
// Retorna 1 em caso de sucesso, e 0 em caso de fracasso.
int push(Stack *stack, stackElement *element) {
  if (full(stack)) {
    return 0;
  }

  // Alocando um novo nó
  node *newNode = (node *)malloc(sizeof(node));

  // Atribuindo o valor do elemento a ser adicionado para o campo
  // data do novo nó
  newNode->data = *element;

  // Apontando como próximo elemento o antigo topo
  newNode->next = stack->head;

  // Agora o ponteiro do topo da pilha aponta para o novo elemento
  stack->head = newNode;

  return 1;
}

// Remove elemento no topo da pilha e o retorna por referência.
// Retorna 1 em caso de sucesso, e 0 em caso de fracasso.
int pop(Stack *stack, stackElement *element) {
  if (empty(stack)) {
    return 0;
  }

  // Copiando o valor do campo data do elemento ao topo da pilha
  // para ser retornado por referência
  *element = stack->head->data;

  // Armazenando o endereço do topo da pilha (que será removido)
  node *oldNode = stack->head;

  // Atribuindo o topo para o próximo elemento
  stack->head = stack->head->next;

  // Liberando a memória do elemento removido
  free(oldNode);

  return 1;
}

// Retorna 1 caso a pilha esteja cheia.
int full(Stack *stack) { return 0; }

// Retorna 1 caso a pilha esteja vazia.
int empty(Stack *stack) { return (stack->head == NULL); }
