#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{          // Criando novo struct do tipo 'NO'.
  char *nome;               // Dado 'nome' como ponteiro (ponteiro que sinaliza início da string).
  int *notas;               // Dado 'nota' como ponteiro (ponteiro que sinaliza início da lista notas).
  int qntNotas;             // Dado 'qntNotas' do Nó.
  float media;              // Dado 'media' do Nó.
  struct NO *proximo;       // Ponteiro para próximo Nó.
} NO;
typedef struct LISTA{       // Criando novo struct do tipo 'LISTA'.
  struct NO *inicio, *fim;  // Ponteiros auxiliares para manusear 'LISTA'.
} LISTA;

// ============================== CABEÇALHO ==============================
void inicializar(LISTA *lst);   // Inicializando nova lista
void apagar(LISTA *lst);        // Apagando lista
void imprimir(LISTA *lst);      // Imprimindo elementos da Lista.
void novoAluno(LISTA *lst);     // Inserindo novos dados de um aluno na Lista.
void obter(struct NO *no);      // Retornando os dados do Nó a partir de um ponteiro.
int tamanho(LISTA *lst);        // Retornando o tamanho da Lista.

// ============================== FUNÇÕES ==============================
void inicializar(LISTA *lst){     // Inicializando nova lista
  lst->inicio = NULL;             // Iniciando ponteiro 'inicio' como NULL.
  lst->fim = NULL;                // Iniciando ponteiro 'fim' como NULL.
}
void apagar(LISTA *lst){              // Apagando lista
  NO *auxiliar = lst->inicio;         // Ponteiro auxiliar para percorrer Nós da Lista.
  NO *anterior = NULL;                // Ponteiro auxiliar para percorrer Nó anterior.
  while(auxiliar != NULL){            // Enquanto não chegar ao fim da Lista.
    anterior = auxiliar;              // Atualizando ponteiro anterior.
    auxiliar = auxiliar->proximo;     // Atualizando ponteiro auxiliar.
    free(anterior->nome);             // Liberando memória da string 'nome'.
    free(anterior->notas);            // Liberando memória da lista 'notas'.
    free(anterior);                   // Liberando memória do Nó.
  }
  lst->inicio = lst->fim = NULL;      //Atualizando elementos da lista
}
void imprimir(LISTA *lst) {        // Imprimindo elementos da Lista.
  printf("=============== DADOS DA LISTA ===============\n\n");
  NO *atual = lst->inicio;                      // Ponteiro auxiliar para percorrer os Nós.
  while(atual != NULL){                         // Rodando Lista até o fim.
    printf("NOME: %s", atual->nome);            // Printando nome.
    printf("NOTAS:");
    for (int i = 0; i < atual->qntNotas; i++) { // Percorrendo as notas.
      printf(" %d", atual->notas[i]);           // Printando notas.
    }
    printf("\nMÉDIA: %.2f\n\n", atual->media);  // Printando média.
    atual = atual->proximo;                     // Buscando próximo Nó.
  }
}
void novoAluno(LISTA *lst){
  printf("=============== INSERINDO NOVO ALUNO À LISTA. ===============\n\n");
  NO *novoNO = (NO*)malloc(sizeof(NO));         // Alocando espaço para o novo Nó da Lista.
  char stringTemporaria[70];                    // Iniciando string temporária.
  int listaNotasTemp[70];                       // Iniciando lista de notas temporária.
  int contador = 0;                             // Contador auxiliar.
  char *substring;
  float media = 0;
  
  // ============================== NOME ==============================
  printf("Nome do aluno: ");
  fgets(stringTemporaria, 70, stdin);           // Lendo novo nome.
  while(stringTemporaria[contador] != '\0')     // Enquanto não chegar ao fim da string.
    contador++;                                 // Acrescente 1 para cada caractere.
  novoNO->nome = (char*)malloc((contador + 1) * sizeof(char));  // Alocando memória para tamanho da string.
  strcpy(novoNO->nome, stringTemporaria);       // Passando nome temporário para 'nome' do novo Nó.
  
  // ========================== NOTAS e MÉDIA e QNT.NOTAS ==========================
  printf("\nNotas do aluno. Exemplo(8 7 10): ");
  fgets(stringTemporaria, 70, stdin);                // Lendo notas como string.
  substring = strtok(stringTemporaria, " ");         // Separando notas para uma substring ["2", "32", NULL].
  contador = 0;
  while (substring != NULL) {                        // Enquanto a substring não chegar ao fim.
    listaNotasTemp[contador] = atoi(substring);      // Converte o cada valor para inteiro e armazena na lista.
    substring = strtok(NULL, " ");                   // Obtém o próximo token.
    media += listaNotasTemp[contador];               // Somando notas.
    contador++;                                      // Passando índices da lista.
  }
  novoNO->notas = (int*)malloc((contador) * sizeof(int));  // Alocando memória para tamanho da lista notas.
  for (int i = 0; i < contador; i++)                 // Contagem referente a quantidade de notas.
    novoNO->notas[i] = listaNotasTemp[i];            // Passando dados da lista temporária para a lista notas.
  novoNO->media = (float)media/(float)contador;      // Passando valor da média para Nó.
  novoNO->qntNotas = contador;
  
  printf("\nNome, notas e média do aluno inseridas com sucesso!\n\n");
  
  // =============================== NÓS ===============================  

  if (lst->inicio == NULL || lst->inicio->media <= novoNO->media) {  // Se a Lista estiver vazia ou o dado for inserido no início.
    novoNO->proximo = lst->inicio;                  // Inserindo Nó ao início da Lista (Maior ou único dado da lista).
    lst->inicio = novoNO;                           // Atualizando ponteiro inicio para o novo Nó.
    if (lst->fim == NULL) {                         // Se for o único dado da Lista.
      lst->fim = novoNO;                            // Atualizando ponteiro fim para o novo Nó.
    }
  } else {
    NO *auxiliar = lst->inicio;                     // Ponteiro auxiliar para percorrer Nós da Lista.
    while (auxiliar->proximo != NULL && auxiliar->proximo->media > novoNO->media) {
      auxiliar = auxiliar->proximo;                 // Atualizando ponteiro auxiliar.
    }
    novoNO->proximo = auxiliar->proximo;            // Interligando Nó na Lista (Meio ou fim).
    auxiliar->proximo = novoNO;                     // Atualizando ponteiro auxiliar para o novo Nó.
    if (novoNO->proximo == NULL) {                  // Se o novo Nó for o último elemento.
      lst->fim = novoNO;                            // Atualizando ponteiro fim para o novo Nó.
    }
  }
  }
void obter(struct NO *no){                    // Retornando os dados do Nó a partir de um ponteiro.
  if (no == NULL) {                           // Se o ponteiro for NULL.
    printf("Erro! Ponteiro para NULL!");      // Mensagem de erro.
  } else{
    printf("=============== BUSCANDO DADO ===============\n\n");
    printf("NOME: %s", no->nome);             // Printando nome.
    printf("NOTAS:");                         
    for (int i = 0; i < no->qntNotas; i++) {  // Percorrendo as notas.
      printf(" %d", no->notas[i]);            // Printando notas.
    }
    printf("\nMÉDIA: %.2f\n\n", no->media);   // Printando média.
  }
}
int tamanho(LISTA *lst){            // Retornando o tamanho da Lista.
  NO *auxiliar = lst->inicio;       // Ponteiro auxiliar para percorrer Nós da Lista.
  int contador = 0;                 // Contador para auxiliar contagem de elementos da Lista.
  while (auxiliar != NULL){         // Enquanto não chegar ao fim da Lista.
    contador++;                     // Acrescentando ao contador. 
    auxiliar = auxiliar->proximo;   // Atualizando ponteiro auxiliar.
  }
  return contador;                  // Retornando tamanho da Lista.
}

int main(void) {
  LISTA Lista;
  inicializar(&Lista);
  novoAluno(&Lista);
  novoAluno(&Lista);
  imprimir(&Lista);
  return 0;
}