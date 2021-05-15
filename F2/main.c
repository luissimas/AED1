/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/05/2021
Data de Atualização: 14/05/2021

Objetivos: Testar a implementação do TAD Pilha com alocação encadeada e
dinâmica de memória.

*/

// Bibliotecas
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "pilha/pilha.h"
#include "utils/utils.h"

// Função principal
int main(int argc, char *argv[])
{
  Stack stack;
  int op = 0;

  create(&stack);

  while (op != 4) {
    /* printf("Opções: \n"); */
    printf("[1] Inserir elemento.\n");
    printf("[2] Remover elemento.\n");
    printf("[3] Imprimir pilha.\n");
    printf("[4] Sair.\n");
    printf("Opção: ");
    scanf("%d", &op);

    switch (op) {
    case 1: {
      stackElement *newElement = (stackElement *)calloc(sizeof(stackElement), 1);

      printf("Digite o valor do novo elemento: ");
      scanf(" %c", newElement);

      if (push(&stack, newElement)) {
        printf("Elemento inserido com sucesso!\n");
      } else {
        printf("Erro ao inserir elemento\n");
      }

      newElement = NULL;
      free(newElement);
      break;
    }
    case 2: {
      stackElement *removedElement = (stackElement *)calloc(sizeof(stackElement), 1);

      if (pop(&stack, removedElement)) {
        printf("Elemento retirado com sucesso!\n");
      } else {
        printf("Erro ao retirar elemento\n");
      }

      removedElement = NULL;
      free(removedElement);
      break;
    }
    case 3: {
      printf("Elementos da pilha: \n");
      printStack(&stack);
      printf("Digite ENTER para continuar...");
      getchar();
      getchar();
      break;
    }
    case 4: {
      printf("Saindo...\n");
      break;
    }
    default:
      printf("Opção inválida\n");
      ;
    }

    printf("\n");
  }

  return 0;
}
