#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int dado;
struct NO *esquerda, *direita;
} NO;

NO *raiz = NULL;

NO *inserir(NO *no, int dado);
NO *remover(NO *no, int dado);
void emOrdem(NO *no);
void preOrdem(NO *no);
void posOrdem(NO *no);
NO *buscar(NO *no, int dado);
int obter(NO *no);
NO *apagar(NO *no);

NO *mostrarFolhas(NO *no);
int getMax(NO *no);
int getMin(NO *no);
int distanciaRaiz(NO *no, int dado);
int alturaArvore(NO *no);

int main(){
  int array[10] = {5, 3, 6, 7, 4, 1, 2, 0, 9, 8};
  for(int i = 0; i < 10; i++){
    raiz = inserir(raiz, array[i]);
  }
  
  emOrdem(raiz);
  printf("\n");
  mostrarFolhas(raiz);
  printf("\n");

  printf("Maior elemento da arvore: %d\n", getMax(raiz));
  printf("Menor elemento da arvore: %d\n", getMin(raiz));

  printf("Distancia do elemento %d da raiz: %d\n", 8, distanciaRaiz(raiz, 8));
  printf("Distancia do elemento %d da raiz: %d\n", 10, distanciaRaiz(raiz, 10));

  printf("A maior distancia da raiz e %d\n", alturaArvore(raiz));

  return 0;
}

NO *inserir(NO *no, int dado){
  if (!no) {
  no = (NO*) malloc(sizeof(NO));
  no->dado = dado;
  no->esquerda = no->direita = NULL;
  } else if (dado < no->dado)
  no->esquerda = inserir(no->esquerda,dado);
  else
  no->direita = inserir(no->direita,dado);

  return no;  
}
NO *remover(NO *no, int dado){
  NO *aux = NULL, *aux2 = NULL;

  if (no) {
  if (no->dado == dado) {
       if (no->esquerda == no->direita) {
            free(no);
            return NULL;
       }
       else if (!no->esquerda) {
            aux = no->direita;
            free(no);
            return aux;
       }
       else if (!no->direita) {
            aux = no->esquerda;
            free(no);
            return aux;
       } else {
            aux = aux2 = no->direita;
            while (aux->esquerda)
           aux = aux->esquerda;
            aux->esquerda = no->esquerda;
            free(no);
            return aux2;
       }
  }
  else {
       if (dado < no->dado)
            no->esquerda = remover(no->esquerda, dado);
       else
            no->direita = remover(no->direita, dado);
  }
  }
  return no;
}
void emOrdem(NO *no){
  if (no) {
    emOrdem(no->esquerda);
    printf("%d ",no->dado);
    emOrdem(no->direita);
  }
}
void preOrdem(NO *no){
  if (no) {
  printf("%d ",no->dado);
  preOrdem(no->esquerda);
  preOrdem(no->direita);
  }
}
void posOrdem(NO *no){
  if (no) {
  posOrdem(no->esquerda);
  posOrdem(no->direita);
  printf("%d ",no->dado);
  }
}
NO *buscar(NO *no, int dado){
  if(no){
    if(no->dado == dado){
      return no;
    } else if(dado < no->dado){
      return buscar(no->esquerda, dado);
    } else {
      return buscar(no->direita, dado);
    }
  }
  return NULL;
}
int obter(NO *no) {
  if (no)
  return no->dado;
  else {
  printf("Nenhum dado para retornar.");
  exit(0);
  }
}
NO *apagar(NO *no){
  if (no) {
  no->esquerda = apagar(no->esquerda);
  no->direita = apagar(no->direita);
  free(no);
  }
  return NULL;
}

NO *mostrarFolhas(NO *no){
  if(no){
    if(no->esquerda == no->direita){
      printf("%d ",no->dado);
    }
    mostrarFolhas(no->esquerda);
    mostrarFolhas(no->direita);
  }
  return no;
}
int getMax(NO *no){
  NO *auxiliar = no;
  while(auxiliar->direita){
    auxiliar = auxiliar->direita;
  }
  return auxiliar->dado;
}
int getMin(NO *no){
  NO *auxiliar = no;
  while(auxiliar->esquerda){
    auxiliar = auxiliar->esquerda;
  }
  return auxiliar->dado;
}
int distanciaRaiz(NO *no, int dado){
  if(no){
    int distancia = -1;
    if(no->dado == dado){
      return 0;
    } else if(dado < no->dado){
      distancia =  1 + distanciaRaiz(no->esquerda, dado);
    } else {
      distancia = 1 + distanciaRaiz(no->direita, dado);
    }

    if(distancia == 0){  // Não encontrou dado. Distancia = 1-1 == 0
      return(-1);
    } else {             // Encontrou dado. Distancia = 1+0 == 1
      return distancia;
    }
  }
  return -1;
}
int alturaArvore(NO *no){
    int tamanho = 0;
    if(no){
        if (alturaArvore(no->esquerda) > alturaArvore(no->direita)){
            tamanho = 1 + alturaArvore(no->esquerda);
        } else {
            tamanho = 1 + alturaArvore(no->direita);
        }
    } else {
        return -1;
    }
    return tamanho;
}