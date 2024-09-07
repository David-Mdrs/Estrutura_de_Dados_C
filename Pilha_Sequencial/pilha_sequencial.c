#include <stdio.h>
#include <stdlib.h>

typedef struct PILHA{
  int posicao, *arr;
  int MAX;
} PILHA;


void criar(PILHA *pilha, int MAX){
  pilha->arr = (int*)malloc(MAX * sizeof(int));
  pilha->posicao = 0;
  pilha->MAX = MAX;
}
void apagar(PILHA *pilha){
  free(pilha->arr);
  pilha->posicao = 0;
}
void imprimir(PILHA *pilha){
  printf("[ ");
  for(int i = 0; i < pilha->posicao; i++){
    printf("%d ", pilha->arr[i]);
  } printf("]\n");
}
int tamanho(PILHA *pilha){
  return pilha->posicao;
}

void push(PILHA *pilha, int dado){
  if(pilha->posicao >= pilha->MAX){
    printf("Pilha cheia!\n");
  } else {
    pilha->arr[pilha->posicao] = dado;
    pilha->posicao++;
  }
}
int pop(PILHA *pilha){
  if(pilha->posicao == 0){
    printf("Pilha vazia!\n");
    return -1;
  } else {
    return pilha->arr[--(pilha->posicao)];
  }
}
int getTopo(PILHA *pilha){
  if(pilha->posicao <= 0){        // Pilha vazia
    return -1;
  }
  return pilha->arr[pilha->posicao-1]; // Retornando topo
}

int main(){
  PILHA pilha;
  criar(&pilha, 10);

  push(&pilha, 100);
  push(&pilha, 50);
  push(&pilha, 200);
  imprimir(&pilha);

  printf("Pop em Pilha -> %d\n",pop(&pilha));
  imprimir(&pilha);
  apagar(&pilha);

  return 0;
}