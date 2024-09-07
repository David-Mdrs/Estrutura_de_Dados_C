#include <stdio.h>

typedef struct FILA{
  int MAX;
  int *fila;
  int posicao;
} FILA;

void criar(FILA *fila, int MAX);  // Inicializa e aloca memória com campos da Fila
void imprimir(FILA *fila);        // Imprime os elementos da Fila
int tamanho(FILA *fila);          // Retorna o tamanho da Fila
void apagar(FILA *fila);          // Desaloca memória e apaga Fila
void enqueue(FILA *fila, int elemento); // Insere elementos no fim da Fila
void dequeue(FILA *fila);         // Remove primeiro elemento da Fila
int getFront(FILA *fila);         // Retorna primero elemento da Fila sem removê-lo

int main(void) {
  FILA fila;
  criar(&fila, 4);
  enqueue(&fila, 1);
  enqueue(&fila, 2);
  enqueue(&fila, 3);
  enqueue(&fila, 4);
  enqueue(&fila, 5);

  imprimir(&fila);
  dequeue(&fila);
  imprimir(&fila);
  printf("Primeiro elemento da Fila: %d\n", getFront(&fila));
  apagar(&fila);
  imprimir(&fila);
  return 0;
}

void criar(FILA *fila, int MAX){
  fila->MAX = MAX;
  fila->posicao = 0;
  fila->fila = malloc(MAX * sizeof(int));
}
void imprimir(FILA *fila){
  printf("[ ");
  for(int i = 0; i < fila->posicao; i++){
    printf("%d ", fila->fila[i]);
  }
  printf("]\n");
}
int tamanho(FILA *fila){
  return fila->posicao;
}
void apagar(FILA *fila){
  fila->posicao = 0;
}
void enqueue(FILA *fila, int elemento){
  if(fila->posicao < fila->MAX){
    fila->fila[fila->posicao] = elemento;
    fila->posicao++;
  } else {
    printf("Fila cheia!\n");
  }
}
void dequeue(FILA *fila){
  if(fila->posicao){  // Fila vazia
    for(int i = 0; i < fila->posicao-1; i++){
      fila->fila[i] = fila->fila[i+1];
    }
    fila->posicao--;
  }
}
int getFront(FILA *fila){
  if(fila->posicao == 0){
    printf("Fila vazia!\n");
    exit(1);
  }
  return fila->fila[0];
}