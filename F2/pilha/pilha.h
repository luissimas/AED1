/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/05/2021
Data de Atualização: 14/05/2021

Objetivos: Arquivo de cabeçalho do TAD de uma Pilha implementada
com alocação encadeada e dinâmica.

*/

#ifndef PILHA_H
#define PILHA_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definindo o tipo de elementos da pilha
typedef char stackElement;

// Definindo a estrutura dos nós da que compõe a pilha
typedef struct node {
  stackElement data;
  struct node *next;
} node;

// Uma pilha é apenas um ponteiro para o nó do topo
typedef struct {
  node *head;
} Stack;

// Cria uma pilha vazia
void create(Stack *stack);

// Adiciona um novo elemento no topo da pilha.
// Retorna 1 em caso de sucesso, e 0 em caso de fracasso.
int push(Stack *stack, stackElement *element);

// Remove elemento no topo da pilha e o retorna por referência.
// Retorna 1 em caso de sucesso, e 0 em caso de fracasso.
int pop(Stack *stack, stackElement *element);

// Retorna 1 caso a pilha esteja cheia.
int full(Stack *stack);

// Retorna 1 caso a pilha esteja vazia.
int empty(Stack *stack);

#endif
