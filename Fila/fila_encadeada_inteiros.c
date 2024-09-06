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

void inicializar(FILA *fila){
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

int main(void) {
  FILA fila;
  inicializar(&fila);
  imprimir(&fila);
  enqueue(&fila, 1);
  enqueue(&fila, 2);
  enqueue(&fila, 3);
  enqueue(&fila, 4);
  imprimir(&fila);
  dequeue(&fila);
  dequeue(&fila);
  dequeue(&fila);

  imprimir(&fila);

  return 0;
}