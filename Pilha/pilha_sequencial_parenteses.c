#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PILHA {
  int posicao;
  int MAX;
  char *string;
} PILHA;

// ============================== CABEÇALHO ==============================

void criar(PILHA *pilha);    // Inicializa memória e dados dos campos da Pilha
void apagar(PILHA *pilha);   // Apaga registro do tipo Pilha desalocando memória
void imprimir(PILHA *pilha); // Imprime o campo "string" da Pilha
int tamanho(PILHA *pilha);   // Retorna o tamanho do "string" da Pilha
void push(PILHA *pilha, char dado);
int pop(PILHA *pilha);

void parenteses(char string[100]){
  int tamanho = strlen(string);

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

      if(string[i] == '('){
        push(&Parenteses, '(');
      } else if(string[i] == ')'){
        if(Parenteses.posicao == 0){
          push(&Parenteses, ')');
          break;
        } else {
          pop(&Parenteses);
        }

      } else if(string[i] == '['){
        push(&Colchetes, '[');
      } else if(string[i] == ']'){
        if(Colchetes.posicao == 0){
          push(&Colchetes, ']');
          break;
        } else {
          pop(&Colchetes);
        }

      } else if(string[i] == '{'){
        push(&Chaves, '{');
      } else if(string[i] == '}'){
        if(Chaves.posicao == 0){
          push(&Chaves, '{');
          break;
        } else {
          pop(&Chaves);
        }

      } else if(strchr("0123456789*/+-", string[i]) == 0){
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

int main(){
  // Testes que devem dar "OK"
  parenteses("(2+3)-(9/9)");  
  parenteses("((2+3)-(9/9))");  
  parenteses("((2+3)-(9/9))");  

  // Testes que devem dar "Nâo OK"
  parenteses(")2+3(-(9/9)");  
  parenteses("(2+3-(9/9)");  

  // Teste que deve dar "Elemento desconhecido na string!"
  parenteses("(a+b)");  
  
  return 0;
}

// ============================== CABEÇALHO ==============================

void criar(PILHA *pilha){
  pilha->MAX = 100;
  pilha->string = (char*)malloc(pilha->MAX * sizeof(char));
  pilha->posicao = 0;
}
void apagar(PILHA *pilha){
  free(pilha->string);
  pilha->posicao = 0;
}
void imprimir(PILHA *pilha){
  for(int i = 0; i < pilha->posicao; i++){
    printf("%c", pilha->string[i]);
  } printf("\n");
}
int tamanho(PILHA *pilha){
  return pilha->posicao;
}
void push(PILHA *pilha, char dado){
  if(pilha->posicao >= pilha->MAX){
    printf("Pilha cheia!\n");
  } else {
    pilha->string[pilha->posicao] = dado;
    pilha->posicao++;
  }
}
int pop(PILHA *pilha){
  if(pilha->posicao == 0){
    printf("Pilha vazia!\n");
    return -1;
  } else {
    return pilha->string[--(pilha->posicao)];
  }
}