#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int dado;
  struct NO *proximo;        // Ponteiro que aponta para proximo NO
  struct NO *anterior;       // Ponteiro que aponta para NO anterior
} NO;
typedef struct LISTA{
  struct NO *inicio, *fim;   // Ponteiros auxiliares da LISTA
} LISTA;

// ============================= CABEÇALHO =============================
void inicializar(LISTA *lst);             // Inivializa ponteiros da LISTA
void apagar(LISTA *lst);                  // Apaga LISTA e liberando memoria
void imprimir(LISTA *lst);                // Imprime LISTA
void imprimir_reverso(LISTA *lst);        // Imprime LISTA de trás para frente
void inserir_ini(LISTA *lst, int dado);   // Insere no início da LISTA
void inserir_ord(LISTA *lst, int dado);   // Insere de forma ordenada na LISTA
void remover(LISTA *lst, int dado);       // Remove dado da LISTA
NO *buscar(LISTA *lst, int dado);         // Busca ponteiro através do dado
int obter(NO *no);                        // Retorna o dado através de um ponteiro
int tamanho(LISTA *lst);                  // Retorna tamanho da LISTA

int main(void) {
  LISTA Lista;
  inicializar(&Lista);
  inserir_ord(&Lista, 6);
  inserir_ord(&Lista, 7);
  inserir_ord(&Lista, 3);
  inserir_ord(&Lista, 4);

  imprimir(&Lista);
  return 0;
}

// ============================== FUNÇÕES ==============================
void inicializar(LISTA *lst){       // Inivializando ponteiros da LISTA
  lst->inicio = lst->fim = NULL;    // Atualizando "inicio" e "fim" para NULL;
}
void apagar(LISTA *lst){            // Apagando LISTA e liberando memoria
  NO *auxiliar = lst->inicio;       // ponteiro "auxiliar" para percorrer NO's
  NO *antAuxiliar = NULL;           // ponteiro "antAuxiliar" para percorrer NO's anteriores
  while (auxiliar){                 // Enquanto não chegar ao fim da LISTA
    antAuxiliar = auxiliar;         // Atualizando "antAuxiliar"
    auxiliar = auxiliar->proximo;   // Atualizando "auxiliar"
    free(antAuxiliar);              // Liberando memória de cada NO
  }
  lst->inicio = lst->fim = NULL;    // Atualizando "inicio" e "fim" para NULL;
}
void imprimir(LISTA *lst){            // Imprimindo LISTA
  NO *auxiliar = lst->inicio;         // ponteiro "auxiliar" para percorrer NO's
  printf("[ ");                       // Formatação
    while(auxiliar){                  // Enquanto não chegar ao fim da LISTA
      printf("%d ", auxiliar->dado);  // Printe o dado de cada NO
      auxiliar = auxiliar->proximo;   // Passando "auxiliar" para proximo NO
    }
  printf("]");                        // Formatação
}
void imprimir_reverso(LISTA *lst){    // Imprimindo LISTA de trás para frente
  NO *auxiliar = lst->fim;            // ponteiro "auxiliar" para percorrer NO's
  printf("[ ");                       // Formatação
    while(auxiliar){                  // Enquanto não chegar ao fim da LISTA
      printf("%d ", auxiliar->dado);  // Printe o dado de cada NO
      auxiliar = auxiliar->anterior;  // Passando "auxiliar" para NO anterior
    }
  printf("]");                        // Formatação
}
void inserir_ini(LISTA *lst, int dado){  // Inserir no início da LISTA
  NO *no = (NO*)(malloc(sizeof(NO)));    // Alocando memória
  no->dado = dado;                       // Passando dado para NO
  no->anterior = no->proximo = NULL;     // Iniciando ponteiros como NULL
  if (lst->inicio == NULL){              // LISTA vazia
    lst->inicio = lst->fim = no;         // Atualizando "inicio" e "fim" para o NO
  } else {                               // LISTA já possui elementos
    no->proximo = lst->inicio;           // Atualizando "proximo"
    lst->inicio->anterior = no;          // Atualizando "anterior"
    lst->inicio = no;                    // Atualizando "inicio"
  }
}
void inserir_ord(LISTA *lst, int dado){      // Inserir de forma ordenada na LISTA
  NO *no = (NO*)(malloc(sizeof(NO)));        // Alocando memória   
  no->dado = dado;                           // Passando dado para NO
  no->anterior = no->proximo = NULL;         // Iniciando ponteiros como NULL
  
  NO *posAuxiliar = lst->inicio;             // Ponteiro "auxiliar" para guardar posição de inserção
  while(posAuxiliar && dado > posAuxiliar->dado){  // Enquanto não chegar ao fim e dado for maior
    posAuxiliar = posAuxiliar->proximo;      // Atualizando ponteiro "auxiliar" para próximo NO
  }
  if(lst->inicio == NULL){                   // LISTA vazia
    lst->inicio = lst->fim = no;             // Atualizando "inicio" e "fim" para o NO
  } else if(lst->inicio == posAuxiliar){     // Inserindo no inicio da LISTA
    lst->inicio->anterior = no;              // Atualizando
    no->proximo = lst->inicio;               // Atualizando
    lst->inicio = no;                        // Atualizando
  } else if(posAuxiliar == NULL){            // Inserindo no fim da LISTA
    no->anterior = lst->fim;                 // Atualizando
    lst->fim->proximo = no;                  // Atualizando
    lst->fim = no;                           // Atualizando
  } else {                                   // Inserindo no meio da LISTA
    posAuxiliar->anterior->proximo = no;     // Atualizando
    no->anterior = posAuxiliar->anterior;    // Atualizando
    posAuxiliar->anterior = no;              // Atualizando
    no->proximo = posAuxiliar;               // Atualizando
  }
}
void remover(LISTA *lst, int dado){           // Remove dado da LISTA
  NO *auxiliar = lst->inicio;                 // Ponteiro "auxiliar" para percorrer NO's
  while(auxiliar && auxiliar->dado != dado){  // Enquanto não tiver fim e dado não for encontrado
    auxiliar = auxiliar->proximo;             // Atualizando ponteiro "auxiliar" para próximo NO
  }
  if (auxiliar == lst->inicio){               // Dado no inicio da LISTA
    if(auxiliar == lst->fim){                 // Único e primeiro elemento da LISTA
      lst->inicio = lst->fim = NULL;          // Atualizando "inicio" e "fim" para NULL
    } else {                                  // Primeiro elemento da LISTA
      lst->inicio = lst->inicio->proximo;     // Atualizando
      lst->inicio->anterior = NULL;           // Atualizando
    }
  }  else if (auxiliar == lst->fim){          // Último elemento da LISTA
    lst->fim = lst->fim->anterior;            // Atualizando
    lst->fim->proximo = NULL;                 // Atualizando
  } else {
    auxiliar->anterior->proximo = auxiliar->proximo;   // Atualizando
    auxiliar->proximo->anterior = auxiliar->anterior;  // Atualizando
  }
  free(auxiliar);                             // Liberando memória
}
NO *buscar(LISTA *lst, int dado){             // Buscando ponteiro através do dado
  NO *auxiliar = lst->inicio;                 // Ponteiro "auxiliar" para percorrer NO's
  while(auxiliar && auxiliar->dado != dado){  // Enquanto não tiver fim e dado não for encontrado
    auxiliar = auxiliar->proximo;             // Atualizando ponteiro "auxiliar" para próximo NO
  } return auxiliar;                          // Retornando ponteiro para dado
}
int obter(NO *no){  // Retorna o dado através de um ponteiro
  return no->dado;  // Retornando dado
}
int tamanho(LISTA *lst){            // Retornando tamanho da LISTA
  int contador = 0;
  NO *auxiliar = lst->inicio;       // Ponteiro "auxiliar" para percorrer NO's
  while(auxiliar){                  // Enquanto não tiver fim e dado não for encontrado
    contador++;
    auxiliar = auxiliar->proximo;   // Atualizando ponteiro "auxiliar" para próximo NO
  } return contador;                // Retornando tamanho a partir da variável "contador"
}