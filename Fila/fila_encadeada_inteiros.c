#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int dado;
  struct NO *proximo;
} NO;
typedef struct FILA{
  struct NO *inicio;
  struct NO *fim;
} FILA;

void criar(FILA *fila);     // Inicializa e aloca memória com campos da Fila
void apagar(FILA *fila);          // Desaloca memória e apaga Fila
void imprimir(FILA *fila);        // Imprime os elementos da Fila
int tamanho(FILA *fila);          // Retorna o tamanho da Fila
void enqueue(FILA *fila, int dado); // Insere elementos no fim da Fila
int dequeue(FILA *fila);          // Remove primeiro elemento da Fila
int getFront(FILA *fila);         // Retorna primero elemento da Fila sem removê-lo


int main(){
  FILA fila1;
  criar(&fila1);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  printf("Dequeue em Fila1 -> %d\n",dequeue(&fila1));

  imprimir(&fila1);

  apagar(&fila1);

  return 0;
}

void criar(FILA *fila){
  fila->inicio = fila->fim = NULL;
}
void apagar(FILA *fila){
  NO *auxiliar = fila->inicio, *anterior = NULL;

  while(auxiliar){
    anterior = auxiliar;
    auxiliar = auxiliar->proximo;
    free(anterior);
  }
  fila->inicio = fila->fim = NULL;
}
void imprimir(FILA *fila){
  NO *auxiliar = fila->inicio;
  printf("[ ");
  while(auxiliar){
    printf("%d ", auxiliar->dado);
    auxiliar = auxiliar->proximo;
  }
  printf("]\n");
}
int tamanho(FILA *fila){
  NO *auxiliar = fila->inicio;
  int contador = 0;
  while(auxiliar){
    contador++;
    auxiliar = auxiliar->proximo;
  }
  return contador;
}
void enqueue(FILA *fila, int dado){
  NO *novoNO = malloc(sizeof(NO));
  novoNO->proximo = NULL;
  novoNO->dado = dado;

  if(fila->fim == NULL){  // Fila vazia
    fila->inicio = fila->fim = novoNO;
  } else {          // Fila não vazia
    fila->fim->proximo = novoNO;
    fila->fim = novoNO;
  }
}
int dequeue(FILA *fila){
  if (fila->inicio) {
    int dado = fila->inicio->dado;
    NO *auxiliar = fila->inicio;

    if (fila->inicio == fila->fim){         // Apenas um elemento na Fila
      fila->inicio = fila->fim = NULL;
    } else {                                // Mais de um elemento na Fila
      fila->inicio = fila->inicio->proximo;
    }
    free(auxiliar);
    return dado;
  } else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}
int getFront(FILA *fila){
  if(!fila->fim){
    printf("Fila vazia!\n");
    exit(1);
  }
  return fila->inicio->dado;
}