#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int dado;
  struct NO *proximo;
  struct NO *anterior;
} NO;
typedef struct FILA{
  struct NO *inicio;
  struct NO *fim;
} FILA;

void criar(FILA *fila);                   // Inicializa e aloca memória com campos da Fila
void apagar(FILA *fila);                  // Desaloca memória e apaga Fila
void imprimir(FILA *fila);                // Imprime os elementos da Fila
int tamanho(FILA *fila);                  // Retorna o tamanho da Fila
int getFront(FILA *fila);                 // Retorna primero elemento da Fila sem removê-lo
void inserirInicio(FILA *fila, int dado); // Insere um dado no início da Fila
void inserirFim(FILA *fila, int dado);    // Insere um dado no fim da Fila
int removerInicio(FILA *fila);            // Remove primeiro elemento da Fila
int removerFim(FILA *fila);               // Remove último elemento da Fila

int main(){
  FILA fila;
  criar(&fila);

  inserirInicio(&fila, 1);
  inserirInicio(&fila, 2);
  imprimir(&fila);
  
  inserirFim(&fila, 3);
  inserirFim(&fila, 4);
  imprimir(&fila);

  removerInicio(&fila);
  imprimir(&fila);

  removerFim(&fila);
  imprimir(&fila);

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
int getFront(FILA *fila){
  if(!fila->fim){
    printf("Fila vazia!\n");
    exit(1);
  }
  return fila->inicio->dado;
}
void inserirInicio(FILA *fila, int dado){
  NO *novoNO = malloc(sizeof(NO));
  novoNO->proximo = novoNO->anterior = NULL;
  novoNO->dado = dado;
  if(fila->fim == NULL){  // Fila vazia
    fila->inicio = fila->fim = novoNO;
  } else {                // Fila não vazia
    novoNO->proximo = fila->inicio;
    fila->inicio->anterior = novoNO;
    fila->inicio = novoNO;
  }
}
void inserirFim(FILA *fila, int dado){
  NO *novoNO = malloc(sizeof(NO));
  novoNO->proximo = novoNO->anterior = NULL;
  novoNO->dado = dado;
  if(fila->fim == NULL){  // Fila vazia
    fila->inicio = fila->fim = novoNO;
  } else {                // Fila não vazia
    fila->fim->proximo = novoNO;
    novoNO->anterior = fila->fim;
    fila->fim = novoNO;
  }
}
int removerInicio(FILA *fila){
  if (fila->inicio) {
    int dado = fila->inicio->dado;
    NO *auxiliar = fila->inicio;
    if (fila->inicio == fila->fim){         // Apenas um elemento na Fila
      fila->inicio = fila->fim = NULL;
    } else {                                // Mais de um elemento na Fila
      fila->inicio = fila->inicio->proximo;
      fila->inicio->anterior = NULL;             // Ajusta o novo último elemento
    }
    free(auxiliar);
    return dado;
  } else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}
int removerFim(FILA *fila){
  if (fila->inicio) {
    int dado = fila->fim->dado;
    NO *auxiliar = fila->fim;
    if (fila->inicio == fila->fim){          // Apenas um elemento na Fila
      fila->inicio = fila->fim = NULL;
    } else {                                 // Mais de um elemento na Fila
      fila->fim = fila->fim->anterior;
      fila->fim->proximo = NULL;             // Ajusta o novo último elemento
    }
    free(auxiliar);
    return dado;
  } else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}