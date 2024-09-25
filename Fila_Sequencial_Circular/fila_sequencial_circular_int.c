#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned MAX;
  int *fila; 
  int inicio;
  int fim;
} FILA;

// ============================= CABEÇALHO =============================
void criar(FILA *pontFila, int tam_MAX);
int tamanho(FILA *pontFila);
void imprimir(FILA *pontFila);
void apagar(FILA *pontFila);
void enqueue(FILA *pontFila, int elemento);
int dequeue(FILA *pontFila);

int main(){
    FILA Fila;
    criar(&Fila, 3);
    imprimir(&Fila);

    enqueue(&Fila, 1);
    enqueue(&Fila, 2);
    enqueue(&Fila, 3);
    imprimir(&Fila);

    dequeue(&Fila);
    imprimir(&Fila);

    return 0;
}

// ============================== FUNÇÕES ==============================
void criar(FILA *pontFila, int tam_MAX) {
  pontFila->inicio = pontFila->fim = 0;
  pontFila->MAX = tam_MAX+1;
  pontFila->fila = (int *)(malloc(tam_MAX * sizeof(int)));
  if (pontFila->fila == NULL)
    printf("Falha na alocacao de memoria.");
}
int tamanho(FILA *pontFila){
  if(pontFila->inicio <= pontFila->fim){
	return pontFila->fim - pontFila->inicio;
  } else {
	return pontFila->MAX - (pontFila->inicio - pontFila->fim);
  }
}
void imprimir(FILA *pontFila){
  printf("[ ");
  for(int i = pontFila->inicio;  ; i++){
	if (i == (int)pontFila->MAX) i = 0;
	if (i == pontFila->fim) break;
	printf("%d ", pontFila->fila[i]);
  }
  printf("]\n");
}
void apagar(FILA *pontFila){
  pontFila->inicio = pontFila->fim = 0;
}
void enqueue(FILA *pontFila, int elemento){
  if((pontFila->fim + 1) != pontFila->inicio && !(pontFila->fim + 1 == (int)pontFila->MAX && !pontFila->inicio)){
	pontFila->fila[pontFila->fim] = elemento;
	pontFila->fim++;
	if(pontFila->fim == (int)pontFila->MAX) pontFila->fim = 0;
  }
  else{
	printf("Nao foi possivel inserir %d. Fila cheia.\n", elemento);
  }
}
int dequeue(FILA *pontFila){
  if(pontFila->inicio != pontFila->fim){
	int dado = pontFila->fila[pontFila->inicio];
	pontFila->inicio++;
	if(pontFila->inicio == (int)pontFila->MAX) pontFila->inicio = 0;
	return dado;
  }
  else{
	printf("Nao ha elementos. Fila vazia.\n");
	exit(1);
  }
}