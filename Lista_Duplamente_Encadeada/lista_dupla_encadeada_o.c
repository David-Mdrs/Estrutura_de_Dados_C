#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FUNCIONARIO{
  char nome[30];
  char ocupacao[30];
  double salario;
} FUNCIONARIO;

typedef struct NO{
  struct FUNCIONARIO funcionario;       // Registro do tipo FUNCIONARIO
  struct NO *proximo;                   // Ponteiro que aponta para proximo NO
  struct NO *anterior;                  // Ponteiro que aponta NO anterior
} NO;

typedef struct LISTA{
  struct NO *inicio, *fim, *supervisor, *peao;  // Ponteiros auxiliares para manusear LISTA
} LISTA;

// ========================= CABEÇALHO =========================
void inicializar(LISTA *lst); // Inicializa ponteiros auxiliares da LISTA
void inserirFun(LISTA *lst, char *nome, char *ocupacao, double salario); // Insere funcionário com base no cargo e salário
void imprimir(LISTA *lst);    // Retorna o dado de todos os funcionários da LISTA

int main(void) {
  LISTA Lista;
  inicializar(&Lista);
  inserirFun(&Lista, "A", "Peao", 2);
  inserirFun(&Lista, "B", "Gerente", 2);
  inserirFun(&Lista, "C", "Peao", 1);
  inserirFun(&Lista, "D", "Supervisor", 1);
  inserirFun(&Lista, "E", "Peao", 8);
  inserirFun(&Lista, "F", "Supervisor", 9);
  inserirFun(&Lista, "G", "Gerente", 2);
  inserirFun(&Lista, "G", "Técnico", 2);

  imprimir(&Lista);
  return 0;
}

// ========================== FUNÇÕES ==========================
void inicializar(LISTA *lst){          // Inicializa ponteiros auxiliares da LISTA
  lst->inicio = lst->fim = NULL;       // Inicializa "inicio" e "fim" para NULL
  lst->supervisor = lst->peao = NULL;  // Inicializa "supervisor" e "peao" para NULL
}
void imprimir(LISTA *lst){                            // Imprime dados de cada funcionário
  NO *auxiliar = lst->inicio;                         // Ponteiro "auxiliar" que percorre todos os NO's
  printf("\n========== Funcionarios ==========\n\n");
  while(auxiliar){                                    // Enquanto não chegar ao fim da LISTA
    printf("Nome: %s\n", auxiliar->funcionario.nome);         // Imprimindo nome
    printf("Ocupacao: %s\n", auxiliar->funcionario.ocupacao); // Imprimindo ocupação
    printf("%.2f \n\n", auxiliar->funcionario.salario);       // Imprimindo salário
    auxiliar = auxiliar->proximo;                     // Atualizando "auxiliar" para próximo NO
  }
}
void inserirFun(LISTA *lst, char *nome, char *ocupacao, double salario){ // Insere FUNCIONARIO ordenadamente na LISTA
  NO *no = (NO*)(malloc(sizeof(NO)));          // Iniciando NO com novos dados
  strcpy(no->funcionario.nome, nome);          // Passando "nome" para NO
  strcpy(no->funcionario.ocupacao, ocupacao);  // Passando "ocupacao" para NO
  no->funcionario.salario = salario;           // Passando "salario" para NO
  no->anterior = no->proximo = NULL;           // Atualizando ponteiros "anterior" e "proximo" para NULL
  NO *posAuxiliar;                             // NO auxiliar que busca a posição a ser inserido
  
  if(strcmp(no->funcionario.ocupacao, "Gerente") == 0){  // Inserção de "Gerente"
    posAuxiliar = lst->inicio;
    while(posAuxiliar && strcmp(posAuxiliar->funcionario.ocupacao, "Gerente") == 0){ // Percorrendo "Gerentes"
      if(posAuxiliar->funcionario.salario < salario)     // Ordenando inserção com base no Salario
        break;                                           // Retorne se encontrar o local a ser inserido
      posAuxiliar = posAuxiliar->proximo;                // Atualizando ponteiro para próximo NO
    }
  } else if(strcmp(no->funcionario.ocupacao, "Supervisor") == 0){  // Inserção de "Supervisor"
    if(lst->supervisor == NULL){                           // Inserindo primeiro "Supervisor" na LISTA
      posAuxiliar = lst->inicio;
      while(posAuxiliar && strcmp(posAuxiliar->funcionario.ocupacao, "Gerente") == 0){ // Buscando inserção do primeiro "Supervisor"
        posAuxiliar = posAuxiliar->proximo;                // Atualizando ponteiro para próximo NO
      }
      lst->supervisor = no;                                // Inicializando ponteiro "Supervisor"
    } else {
      posAuxiliar = lst->supervisor;                       // Buscando desde o primeiro "Supervisor"
      while(posAuxiliar && strcmp(posAuxiliar->funcionario.ocupacao, "Supervisor") == 0){ // Percorrendo "Supervisores"
        if(posAuxiliar->funcionario.salario < salario)     // Ordenando inserção com base no Salario
          break;                                           // Retorne se encontrar o local a ser inserido
        posAuxiliar = posAuxiliar->proximo;                // Atualizando ponteiro para próximo NO
      }
    }
  } else if(strcmp(no->funcionario.ocupacao, "Peao") == 0){  // Inserção de "Peao"
    if(lst->peao == NULL){                                 // Inserindo primeiro "Peao" na LISTA
      posAuxiliar = lst->inicio;
      while(posAuxiliar && (strcmp(posAuxiliar->funcionario.ocupacao, "Gerente") == 0 || (strcmp(posAuxiliar->funcionario.ocupacao, "Supervisor") == 0))){ // Buscando inserção do primeiro "Peao"
        posAuxiliar = posAuxiliar->proximo;                // Atualizando ponteiro para próximo NO
      }
      lst->peao = no;                                      // Inicializando ponteiro "Peao"
    } else {
      posAuxiliar = lst->peao;                             // Buscando desde o primeiro "Peao"
      while(posAuxiliar){                                  // Percorrendo "Peoes"
        if(posAuxiliar->funcionario.salario < salario)     // Ordenando inserção com base no Salario
          break;                                           // Retorne se encontrar o local a ser inserido
        posAuxiliar = posAuxiliar->proximo;                // Atualizando ponteiro para próximo NO
      }
    }
  } else {
    printf("Ocupacao '%s' nao existe ou escrita de forma errada.\n", ocupacao);
    printf("Tente: Gerente, Supervisor ou Peao.\n");
    free(no);
    return;  // Não vai inserir na Lista, caso nome esteja com erro.
  }


  if(lst->inicio == NULL){          // Inserindo no início da LISTA (LISTA vazia)
    lst->inicio = lst->fim = no;    // Atualizando
  } else if (posAuxiliar == lst->inicio){ // Inserindo no início da LISTA (LISTA já possui elementos)
    posAuxiliar->anterior = no;     // Atualizando
    no->proximo = lst->inicio;      // Atualizando
    lst->inicio = no;               // Atualizando
  } else if(posAuxiliar == NULL){   // Inserindo  no fim da LISTA
    no->anterior = lst->fim;        // Atualizando
    lst->fim->proximo = no;         // Atualizando
    lst->fim = no;                  // Atualizando
  } else {                          // Inserindo no meio da LISTA
    posAuxiliar->anterior->proximo = no;    // Atualizando
    no->anterior = posAuxiliar->anterior;   // Atualizando
    posAuxiliar->anterior = no;             // Atualizando
    no->proximo = posAuxiliar;              // Atualizando
  }
}