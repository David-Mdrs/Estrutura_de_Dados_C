#include <stdio.h>
#include <stdlib.h>

typedef struct sNODE {         // Criando novo struct do tipo 'sNODE'.
  int dado;                    // Dado do Nó.
  struct sNODE *proximo;       // Ponteiro para próximo Nó.
} sNODE;
typedef struct sLISTA {        // Criando novo struct do tipo 'sLISTA'.
  struct sNODE *inicio, *fim;  // Ponteiros auxiliares para manusear 'sLISTA'.
} sLISTA;

// ============================== CABEÇALHO ==============================
void inicializar(sLISTA *lst);                 // Inicializando nova lista
void apagar(sLISTA *lst);                      // Apagando lista
void imprimir(sLISTA *lst);                    // Imprimindo dados da Lista.
void inserir_ini(sLISTA *lst, int dado);       // Inserindo dado no início da Lista.
void inserir_ord(sLISTA *lst, int dado);       // Inserindo dado de forma ordenada na Lista.
void remover(sLISTA *lst, int dado);           // Removendo dado da Lista.
sNODE *buscar(sLISTA *lst, int dado);          // Retornando o ponteiro a partir do dado.
int obter(struct sNODE *node);                 // Retornando o dado a partir do ponteiro.
int tamanho(sLISTA *lst);                      // Retornando o tamanho da Lista.
sLISTA juntar_ord(sLISTA *lst1, sLISTA *lst2); // Soma duas Listas de forma ordenada.

// ============================== FUNÇÕES ==============================
void inicializar(sLISTA *lst) { // Inicializando nova lista
  lst->inicio = NULL;           // Iniciando ponteiro 'inicio' como NULL.
  lst->fim = NULL;              // Iniciando ponteiro 'fim' como NULL.
}
void apagar(sLISTA *lst) {         // Apagando lista
  sNODE *auxiliar = lst->inicio;   // Ponteiro auxiliar para percorrer Nós da Lista.
  sNODE *anterior = NULL;          // Ponteiro auxiliar para percorrer Nó anterior.
  while (auxiliar != NULL) {       // Enquanto não chegar ao fim da Lista.
    anterior = auxiliar;           // Atualizando ponteiro anterior.
    auxiliar = auxiliar->proximo;  // Atualizando ponteiro auxiliar.
    free(anterior);                // Liberando memória.
  }
  lst->inicio = lst->fim = NULL;   // Atualizando elementos da lista
}
void imprimir(sLISTA *lst) {    // Imprimindo elementos da Lista.
  sNODE *atual = lst->inicio;   // Ponteiro auxiliar para percorrer os Nós.
  printf("[ ");
  while (atual != NULL) {       // Enquanto não chegar ao fim da Lista.
    printf("%d ", atual->dado); // Printando elemento do Nó.
    atual = atual->proximo;     // Atualizando ponteiro auxiliar para próximo Nó.
  }
  printf("]\n");
}
void inserir_ini(sLISTA *lst, int dado) {         // Inserindo elemento no início da Lista.
  sNODE *novoNO = (sNODE *)malloc(sizeof(sNODE)); // Alocando espaço para o novo Nó da Lista.
  novoNO->dado = dado;                            // Inserindo novo dado no Nó.
  novoNO->proximo = NULL;                         // Tornando fim do Nó em NULL.
  if (lst->inicio == NULL) {                      // Lista vazia.
    lst->inicio = lst->fim = novoNO;              // Inicio e Fim apontam para o mesmo Elemento.
  } else {                                        // Lista já posssui algum elemento.
    novoNO->proximo = lst->inicio;                // Apontando para o próximo Nó.
    lst->inicio = novoNO;                         // Atualizando inicio para o novo nó.
  }
}
void inserir_ord(sLISTA *lst, int dado) {           // Inserindo dado de forma ordenada na Lista.
  sNODE *novoNO = (sNODE *)malloc(sizeof(sNODE));   // Alocando espaço para o novo Nó da Lista.
  novoNO->dado = dado;               // Inserindo novo dado no Nó.
  novoNO->proximo = NULL;            // Tornando fim do Nó em NULL
  if (lst->inicio == NULL || lst->inicio->dado >= dado) { // Se a Lista estiver vazia ou o dado for inserido no início.
    novoNO->proximo = lst->inicio;   // Inserindo Nó ao início da Lista (Menor ou // único dado da lista).
    lst->inicio = novoNO;            // Atualizando ponteiro inicio para o novo Nó.
    if (lst->fim == NULL) {          // Se for o único dado da Lista.
      lst->fim = novoNO;             // Atualizando ponteiro fim para o novo Nó.
    }
  } else {
    sNODE *auxiliar = lst->inicio;   // Ponteiro auxiliar para percorrer Nós da Lista.
    sNODE *anterior = NULL;          // Ponteiro auxiliar para percorrer Nó anterior.
    while (auxiliar != NULL &&
      auxiliar->dado < dado) {       // Enquanto não chegar ao fim da lista e encontrar a posição.
      anterior = auxiliar;           // Atualizando ponteiro anterior.
      auxiliar = auxiliar->proximo;  // Atualizando ponteiro auxiliar.
    }
    novoNO->proximo = auxiliar;      // Interligando Nó na Lista (Início, meio ou fim).

    if (anterior != NULL) {          // Inserção no meio ou fim da lista.
      anterior->proximo = novoNO;    // Interligando Nó na Lista.
      if (auxiliar == NULL) {        // Inserção ao fim da lista.
        lst->fim = novoNO;           // Atualizando ponteiro fim para o novo Nó.
      }
    } else {                         // Inserção no início da Lista (Menor dado)
      lst->inicio = novoNO;          // Atualizando ponteiro início para o novo Nó.
    }
  }
}
void remover(sLISTA *lst, int dado){     // Removendo elemento da Lista.
  sNODE *auxiliar = lst->inicio;         // Ponteiro auxiliar para percorrer Nós da Lista.
  sNODE *anterior = NULL;                // Ponteiro auxiliar para percorrer Nó anterior.
  while (auxiliar != NULL) {             // Enquanto não chegar ao fim da Lista.
    if (auxiliar->dado == dado) {        // Buscando dado para remoção.
      if (auxiliar == lst->inicio) {     // Dado no início da Lista.
        lst->inicio = auxiliar->proximo; // Atualizando ponteiro inicio para próximo Nó.
        if (lst->inicio == NULL) {       // Se a lista fica vazia.
          lst->fim = NULL;               // Atualizando ponteiro fim para Nó NULL.
        }
      } else if (auxiliar == lst->fim) { // Dado no fim Lista.
        lst->fim = anterior;             // Atualizando ponteiro fim para Nó anterior.
        anterior->proximo = NULL;        // Tornando fim do Nó em NULL.
      } else {                           // Dado no meio da Lista.
        anterior->proximo = auxiliar->proximo; // Interligando Nó no elemento posterior ao removido.
      }
      free(auxiliar);                    // Liberando memória.
      return;
    }
    anterior = auxiliar;                 // Atualizando ponteiro anterior.
    auxiliar = auxiliar->proximo;        // Atualizando ponteiro auxiliar.
  }
}
sNODE *buscar(sLISTA *lst, int dado) { // Retornando o ponteiro a partir do dado.
  sNODE *auxiliar = lst->inicio;       // Ponteiro auxiliar para percorrer Nós da Lista.
  while (auxiliar != NULL) {           // Enquanto não chegar ao fim da Lista.
    if (auxiliar->dado == dado) {      // Buscando dado.
      return auxiliar;                 // Retornando ponteiro para o dado.
    }
    auxiliar = auxiliar->proximo;      // Atualizando ponteiro auxiliar.
  }
  return NULL;                         // Retornando NULL caso dado não encontrado.
}
int obter(struct sNODE *node) {  // Retornando o dado a partir do ponteiro.
  if (node == NULL) {            // Se o ponteiro for NULL.
    printf("Erro! Ponteiro para NULL!"); // Mensagem de erro.
    return -1;                   // Retornando '-1' como erro.
  }
  return node->dado;             // Retornando dado do ponteiro.
}
int tamanho(sLISTA *lst) {        // Retornando o tamanho da Lista.
  sNODE *auxiliar = lst->inicio;  // Ponteiro auxiliar para percorrer Nós da Lista.
  int contador = 0;               // Contador para auxiliar contagem de elementos da Lista.
  while (auxiliar != NULL) {      // Enquanto não chegar ao fim da Lista.
    contador++;                   // Acrescentando ao contador.
    auxiliar = auxiliar->proximo; // Atualizando ponteiro auxiliar.
  }
  return contador;                // Retornando tamanho da Lista.
}
sLISTA juntar_ord(sLISTA *lst1, sLISTA *lst2) { // Soma duas Listas de forma ordenada.
  sLISTA NovaLista;                 // Criando nova Lista como auxílio.
  inicializar(&NovaLista);          // Inicializando nova Lista.
  sNODE *auxiliar = lst1->inicio;   // Ponteiro auxiliar para percorrer Nós da Lista 1.
  while (auxiliar != NULL) {        // Enquanto não chegar ao fim da Lista.
    inserir_ord(&NovaLista, auxiliar->dado); // Inserindo elementos na NovaLista com a função 'inserir_ord'.
    auxiliar = auxiliar->proximo;   // Atualizando ponteiro auxiliar.
  }
  auxiliar = lst2->inicio;          // Atualizando ponteiro auxiliar para percorrer Nós da Lista 1.
  while (auxiliar != NULL) {        // Enquanto não chegar ao fim da Lista.
    inserir_ord(&NovaLista, auxiliar->dado); // Inserindo elementos na NovaLista com a função 'inserir_ord'.
    auxiliar = auxiliar->proximo;   // Atualizando ponteiro auxiliar.
  }
  return NovaLista;                 // Retornando NovaLista.
}

int main() {
  // Criando nova lista. 
  sLISTA Lista;
  inicializar(&Lista);
  inserir_ini(&Lista, 1);
  inserir_ini(&Lista, 34);
  inserir_ini(&Lista, 557);
  inserir_ini(&Lista, 54);
  inserir_ini(&Lista, 65);
  inserir_ord(&Lista, 3);
  inserir_ord(&Lista, 10);

  // Criando nova lista.
  sLISTA Lista2;
  inicializar(&Lista2);
  inserir_ini(&Lista2, 1);
  inserir_ini(&Lista2, 63);
  inserir_ini(&Lista2, 5);
  inserir_ini(&Lista2, 58);
  inserir_ini(&Lista2, 9);
  inserir_ord(&Lista2, 264);
  inserir_ord(&Lista2, 10);

  // Juntando listas.
  sLISTA nova_lst = juntar_ord(&Lista, &Lista2);

  // Imprimindo, apagando e imprimindo as listas respectivamente.
  imprimir(&Lista);
  imprimir(&Lista2);
  imprimir(&nova_lst);
  apagar(&Lista);
  apagar(&Lista2);
  apagar(&nova_lst);
  imprimir(&Lista);
  imprimir(&Lista2);
  imprimir(&nova_lst);

  return 0;
}