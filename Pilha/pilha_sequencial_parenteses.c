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
void push(PILHA *pilha, char dado); // Insere um elemento "char" na Pilha
int pop(PILHA *pilha);       // Remove um elemento da Pilha

void parenteses(char nome[100]);

int main(){

  parenteses("([[)(]][]{})");  
  
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
  for(int i = 0; i < pilha->posicao; i++){
    printf("%c", pilha->nome[i]);
  } printf("\n");
}
int tamanho(PILHA *pilha){
  return pilha->posicao;
}
void push(PILHA *pilha, char dado){
  if(pilha->posicao >= pilha->MAX){
    printf("Pilha cheia!\n");
  } else {
    pilha->nome[pilha->posicao] = dado;
    pilha->posicao++;
  }
}
int pop(PILHA *pilha){
  if(pilha->posicao == 0){
    printf("Pilha vazia!\n");
    return -1;
  } else {
    return pilha->nome[--(pilha->posicao)];
  }
}
void parenteses(char nome[100]){
  int tamanho = strlen(nome);

  if (tamanho <= 0){                    // Testa string vazia
    printf("String vazia!\n");
  } else {                              // String não vazia
    PILHA Parenteses;                   // Iniciando Pilha
    PILHA Colchetes;                    // Iniciando Pilha
    PILHA Chaves;                       // Iniciando Pilha
    criar(&Parenteses);                 // Preparando ambiente da Pilha
    criar(&Colchetes);                  // Preparando ambiente da Pilha
    criar(&Chaves);                     // Preparando ambiente da Pilha

    for(int i = 0; i < tamanho; i++){ 

      if(nome[i] == '('){
        push(&Parenteses, '(');
      } else if(nome[i] == ')'){
        if(Parenteses.posicao == 0){
          push(&Parenteses, ')');
          break;
        } else {
          pop(&Parenteses);
        }

      } else if(nome[i] == '['){
        push(&Colchetes, '[');
      } else if(nome[i] == ']'){
        if(Colchetes.posicao == 0){
          push(&Colchetes, ']');
          break;
        } else {
          pop(&Colchetes);
        }

      } else if(nome[i] == '{'){
        push(&Chaves, '{');
      } else if(nome[i] == '}'){
        if(Chaves.posicao == 0){
          push(&Chaves, '{');
          break;
        } else {
          pop(&Chaves);
        }

      } else {
        printf("Elemento desconhecido na string!\n");
        return;
      }
    }

    if(Parenteses.posicao != 0 ||Colchetes.posicao != 0 || Chaves.posicao != 0){
      printf("Não Balanceada!\n");
    } else {
      printf("Balanceada!\n");
    }
  }
}