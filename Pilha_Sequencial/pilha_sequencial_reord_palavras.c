#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PILHA {
  int posicao;
  int MAX;
  char *nome;
} PILHA;

// ============================== CABEÇALHO ==============================

void criar(PILHA *pilha);    // Inicializa memória e dados dos campos da Pilha
void apagar(PILHA *pilha);   // Apaga registro do tipo Pilha desalocando memória
void imprimir(PILHA *pilha); // Imprime o campo "nome" da Pilha
int tamanho(PILHA *pilha);   // Retorna o tamanho do "nome" da Pilha
void inverterNome(PILHA *pilha, char nome[100]); // Inverte as palavras da string preservando ordem

int main(){
  PILHA pilha;
  criar(&pilha);
  apagar(&pilha);
  
  inverterNome(&pilha, "Estrutura de Dados");

  return 0;
}

// ============================== CABEÇALHO ==============================

void criar(PILHA *pilha){
  pilha->MAX = 100;
  pilha->nome = (char*)malloc(pilha->MAX * sizeof(char));
  pilha->posicao = 0;
}
void apagar(PILHA *pilha){
  free(pilha->nome);
  pilha->posicao = 0;
}
void imprimir(PILHA *pilha){
  printf("%s \n", pilha->nome);
}
int tamanho(PILHA *pilha){
  return pilha->posicao;
}

void inverterNome(PILHA *pilha, char nome[100]){
  int tamanho = strlen(nome);
  if (tamanho > 0){  // String não vazia
    for(int i = 0; i < tamanho; i++){
      pilha->nome[pilha->posicao] = nome[i];
      pilha->posicao++;
      if(nome[i] == ' ' || i == tamanho-1){
        if(nome[i] == ' ')
          pilha->posicao--;
        for(int j = i-1; pilha->nome[j] != ' ' && j >= 0; j--){
          printf("%c", pilha->nome[pilha->posicao-1]);
          pilha->posicao--;
        }
        printf(" ");
      }
    }
  }
}