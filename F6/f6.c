/** DADOS DO ALUNO
NOME: Luís Augusto Simas do Nascimento
RA: 790828
**/

#include <stdio.h>
#include <stdlib.h>


typedef int Chave;


typedef struct no{
    Chave chave;
    int tam;
    struct no *esq, *dir, *pai;

} No;

typedef struct arvore{
     No * raiz;
}Arvore;


/**
* Aloca um novo no com chave ch e conteudo inf e retorna-o
**/

No * criaNo(Chave ch){
    No * novono;
    novono = malloc(sizeof(No));
    novono->chave = ch;
    novono->pai = NULL;
    novono->dir = NULL;
    novono->esq = NULL;
    novono->tam = 1;
    return novono;
}

/**
* encontra o maior no de uma arvore com raiz
**/
No * maior(No *raiz){
  if (raiz->dir != NULL)
    return maior(raiz->dir);

  return raiz;
}

/**
* encontra o menor no de uma arvore com raiz
**/
No * menor(No *raiz){
  if (raiz->esq != NULL)
    return menor(raiz->esq);

  return raiz;
}

/**
* Insere recursivamente (ou iterativamente) um novo nó criado na árvore enraizada por raiz retornando um ponteiro para ele.
**/
No * insererec(No * raiz, No * novo){
  // Caso base
  if (raiz == NULL) {
    // Atribuindo o conteúdo ao novo nó
    novo->pai = NULL;
    return novo;
  } else {
    // Determinando em qual lado da árvore o elemento deve ser inserido
    if (novo->chave <= raiz->chave) {
      raiz->esq = insererec(raiz->esq, novo);
      raiz->esq->pai = raiz;
    } else{
      raiz->dir = insererec(raiz->dir, novo);
      raiz->dir->pai = raiz;
    }
  }

  raiz->tam++;
  return raiz;
}

/**
* altura da arvore
**/

int altura(No * raiz){
  // Caso base
  if (raiz == NULL)
    return -1;

  // Obtendo recursivamente as alturas das sub-árvores
  // a partir dos nós da raíz
  int hleft = altura(raiz->esq);
  int hright = altura(raiz->dir);

  // Retorna sempre a maior altura
  return (hleft > hright) ? hleft + 1 : hright + 1;
}



/**
* apaga todos os nos apontados por raiz
**/
No * destroi(No * raiz){
     if(raiz == NULL)
        return NULL;
     if(raiz->dir == NULL && raiz->esq ==NULL){
        free(raiz);
        return NULL;
     }
     if(raiz->esq != NULL)
        raiz->esq = destroi(raiz->esq);
     if(raiz->dir != NULL)
        raiz->dir = destroi(raiz->esq);
     return destroi(raiz);
}







int main(){
    Arvore * arv = malloc(sizeof(Arvore));
    //entrada 1 numero de elementos da arvore
    //entrada 2 lista de elementos a ser inserido em sequencia na árvore
    int i, n;
    scanf("%d",&n);
    int * v = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",&v[i]);

    No * novono;
    arv->raiz = criaNo(v[0]);
    for (i = 1; i < n; i++){
        novono = criaNo(v[i]);
        insererec(arv->raiz,novono);
    }

    printf("Altura da arvore = %d",altura(arv->raiz));
    int g = maior(arv->raiz)->chave;
    int s = menor(arv->raiz)->chave;
    printf("\n\nMaior elemento da arvore = %d",g );
    printf("\n\nMenor elemento da arvore = %d",s );


    destroi(arv->raiz);
    arv->raiz = NULL;
    free(arv);
    return 0;
}

