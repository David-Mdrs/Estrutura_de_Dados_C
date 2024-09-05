#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NOME {
  char nome[18];
  int freq;
} NOME;

typedef struct NO {
  struct NOME pessoa;
  struct NO *anterior, *proximo;
} NO;

typedef struct LISTA {
  NO *inicio, *fim;
} LISTA;

void inicializar(LISTA *lst) { lst->inicio = lst->fim = NULL; }
void imprimir(LISTA *lst) {
  printf("=============== Usuarios ===============\n\n");
  NO *auxiliar = lst->inicio;
  while (auxiliar) {
    printf("Nome: %s\nFrequencia: %d\n\n", auxiliar->pessoa.nome,
           auxiliar->pessoa.freq);
    auxiliar = auxiliar->proximo;
  }
}
void novaPessoa(LISTA *lst, char nome[18]) {
  // Insere uma emoção caso não exista. Caso exista, apenas acrescente à
  // frequência
  NO *no = (NO *)(malloc(sizeof(NO)));
  strcpy(no->pessoa.nome, nome);
  no->pessoa.freq = 1;
  no->anterior = no->proximo = NULL;

  if (lst->inicio == NULL) {
    lst->inicio = lst->fim = no;
  } else {
    NO *aux = lst->inicio;
    while (aux) {
      if (strcmp(aux->pessoa.nome, nome) ==
          0) { // Se já ouver esta emoção na Lista
        aux->pessoa.freq++;
        break;
      }
      aux = aux->proximo;
    }
    if (aux == NULL) {
      no->proximo = lst->inicio;
      lst->inicio->anterior = no;
      lst->inicio = no;
    }
  }
}
NO *nomeDominante(LISTA *lst) {
  NO *auxiliar = lst->inicio;
  NO *maiorFreq = lst->inicio;
  while (auxiliar) {
    if (maiorFreq->pessoa.freq <= auxiliar->pessoa.freq) {
      maiorFreq = auxiliar;
    }
    auxiliar = auxiliar->proximo;
  }
  return maiorFreq;
}
NO *nomeSubmissivo(LISTA *lst) {
  NO *auxiliar = lst->inicio;
  NO *menorFreq = lst->inicio;
  while (auxiliar) {
    if (menorFreq->pessoa.freq >= auxiliar->pessoa.freq) {
      menorFreq = auxiliar;
    }
    auxiliar = auxiliar->proximo;
  }
  return menorFreq;
}

int main(void) {
  LISTA Lista;
  inicializar(&Lista);
  novaPessoa(&Lista, "Eduarda");
  novaPessoa(&Lista, "Arthur");
  novaPessoa(&Lista, "Arthur");
  novaPessoa(&Lista, "Eduarda");
  novaPessoa(&Lista, "Eduarda");
  novaPessoa(&Lista, "Arthur");
  novaPessoa(&Lista, "Eduarda");
  novaPessoa(&Lista, "Bruno");
  novaPessoa(&Lista, "Bruno");
  novaPessoa(&Lista, "Bruno");
  novaPessoa(&Lista, "Bruno");

  imprimir(&Lista);

  NO *pAux = nomeDominante(&Lista);
  printf("No endereco %p temos o nome %s com maior frequencia: %d\n", pAux,
         pAux->pessoa.nome, pAux->pessoa.freq);
  pAux = nomeSubmissivo(&Lista);
  printf("No endereco %p temos o nome %s com menor frequencia: %d\n", pAux,
         pAux->pessoa.nome, pAux->pessoa.freq);

  return 0;
}