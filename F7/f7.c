/**
Nome: Luís Augusto Simas do Nascimento
Ra: 790828
**/

#include <stdio.h>
#include <stdlib.h>

// Defines auxiliar nas operações de heap
#define LEFT_CHILD(i) (2 * i + 1)
#define RIGHT_CHILD(i) (2 * i + 2)
#define PARENT(i) ((i - 1) / 2)

// Função auxiliar para trocar dois elementos
void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

/*
  HeapSort:
    - Organizamos os elementos do vetor para construir um heap
    - Dividimos o vetor em uma parte ordenada e uma não-ordenada
    - A cada iteração:
        - Encontramos o maior elemento do heap O(log(n))
        - Colocamos na última posição do vetor não-ordenado
        - Decrementamos o tamanho do vetor não-ordenado
*/

// Operações do heap
/*
  Percorremos o heap trocando o elemento da posição passada
  com seu pai enquanto ele for maior do que o pai. Isso garante
  a propriedade fundamental do heap (o pai deve ser maior que
  ambos os filhos).
*/
void shiftUp(int *array, int pos) {
  int current = pos;

  while (current > 0 && array[PARENT(current)] < array[current]) {
    swap(&array[PARENT(current)], &array[current]);
    current = PARENT(current);
  }
}

/*
  Percorremos o heap trocando o elemento da posição passada
  com um de seus filhos enquanto ele for menor do que um dos filhos.
*/
void shiftDown(int *array, int size, int pos) {
  int current = pos;
  int child;

  // Enquanto estivermos no range do array e um dos dois filhos for maior que o
  // pai
  while (((LEFT_CHILD(current) < size) && (array[LEFT_CHILD(current)] > array[current])) ||
         ((RIGHT_CHILD(current) < size) && (array[RIGHT_CHILD(current)] > array[current]))) {

    child = LEFT_CHILD(current);

    if ((RIGHT_CHILD(current) < size) && (array[RIGHT_CHILD(current)] > array[child]))
      child = RIGHT_CHILD(current);

    swap(&array[current], &array[child]);
    current = child;
  }
}

/*
  Recebe um vetor com `size` elementos e o transforma em um maxheap
*/
void heapify(int *array, int size) {
  for (int i = size / 2; i >= 0; i--) {
    shiftDown(array, size, i);
  }
}

/**
 * Recebe o vetor v  de tamanho n e o ordena
 **/
void sort(int *v, int n) {
  // Transformando o vetor em um maxheap
  heapify(v, n);

  // Ordenando o vetor utilizando a propriedades do heap
  for (int i = n; i > 0; i--) {
    // Troca o primeiro elemento do heap (maior elemento) com o último
    // elemento do vetor
    swap(&v[0], &v[i - 1]);

    // Restaura a estrutura do heap fazendo o shiftDown do primeiro
    // elemento (que acabou de ser trocado)
    shiftDown(v, i - 1, 0);
  }
}

int main() {

  // entrada 1 numero de elementos do vetor a ser ordenado
  // entrada 2 lista de elementos a ser inserido em sequencia na árvore
  int i, n;
  scanf("%d", &n);
  int *v = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);

  sort(v, n);

  // imprime o vetor ordenado
  for (i = 0; i < n - 1; i++)
    printf("%d,", v[i]);
  printf("%d", v[i]);

  free(v);
  return 0;
}
