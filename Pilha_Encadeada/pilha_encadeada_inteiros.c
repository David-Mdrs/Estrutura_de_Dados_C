#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  struct NO *proximo;
  int dado;
} NO;

typedef struct PILHA{
  struct NO *topo;
} PILHA;

void inicializar(PILHA *pilha){
  pilha->topo = NULL;
}
void imprimir(PILHA *pilha){
  NO *auxiliar = pilha->topo;
  printf("[ ");
  while(auxiliar){
    printf("%d ", auxiliar->dado);
  } printf("]");
}
void apagar(PILHA *pilha){
  if(pilha->topo){
    NO *auxiliar = pilha->topo;
    NO *anterior = NULL;
    while(auxiliar){
      anterior = auxiliar;
      auxiliar = auxiliar->proximo;
      free(anterior);
    }
    pilha->topo = NULL;
  }
}  

void push(PILHA *pilha, int dado){
  NO *novoNO = (NO*)(malloc(sizeof(NO)));
  novoNO->dado = dado;
  novoNO->proximo = NULL;
  if(pilha->topo){
    novoNO->proximo = pilha->topo;
    pilha->topo = novoNO;
  } else {
    pilha->topo = novoNO;
  }
}
void pop(PILHA *pilha){
  if(pilha->topo){
    NO *auxiliar = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(auxiliar);
  }
}
int getTopo(PILHA *pilha){
    if (pilha->topo == NULL){  // Pilha vazia
    return -1;
  }
  return pilha->topo->dado;    // Retornando topo
}

int main(void) {
  PILHA pilha;
  inicializar(&pilha);
  imprimir(&pilha);

  return 0;
}