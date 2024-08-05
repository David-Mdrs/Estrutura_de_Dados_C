#include <stdio.h>
#include <stdlib.h>

// Registro do tipo "LISTA"
typedef struct {
  unsigned MAX;
  int *arr, pos;
} LISTA;

// ======================================== CABEÇALHO ========================================
void Imprimir(LISTA *lst);                          // Retorna os valores da lista
void Criar(LISTA *lst, int tam_MAX);                // Cria um novo registro do tipo "LISTA"
void Apagar(LISTA *lst);                            // Apaga registro
int Contar(LISTA *lst, int valor);                  // Conta quantas ocorrências tem na lista
int Pop(LISTA *lst);                                // Remove e retorna o último elemento da Lista.
void InserirPos(LISTA *lst, int pos, int valor);    // Insere elementos a partir da posição dada
void Copiar(LISTA *lst1, LISTA *lst2);              // Faz cópia da segunda lista na primeira
void Estender(LISTA *lst1, LISTA *lst2);            // Faz cópia da segunda no fim da primeira
void Inverter(LISTA *lst1, LISTA *lst2);            // Faz cópia da segunda lista na primeira na ordem inversa
void Redimensionar(LISTA *lst, int MAX);            // Redimensionar a memória alocada dinamicamente, para mais ou para menos
void Ordenar(LISTA *lst);                           // Pega lista desordenada e ordena em ordem crescente

void InserirPos_V2(LISTA *lst, int pos, int valor); // Insere elementos a partir da posição dada
void Copiar_V2(LISTA *lst1, LISTA *lst2);           // Faz cópia da segunda lista na primeira
void Estender_V2(LISTA *lst1, LISTA *lst2);         // Faz cópia da segunda no fim da primeira
void Inverter_V2(LISTA *lst1, LISTA *lst2);         // Faz cópia da segunda lista na primeira na ordem inversa
void Inserir_Ord(int arr[], int pos, int MAX, int elemento); // Insere elementos na lista ordenadamente

// ======================================== FUNÇÕES ========================================
void Imprimir(LISTA *lst) {                         // Retorna os valores da lista
  printf("[");
  for (int i = 0; i < lst->pos; i++) {
    if (i < lst->pos-1)
      printf("%d, ", lst->arr[i]);
    else
      printf("%d", lst->arr[i]);
  }
  printf("]\n");
}
void Criar(LISTA *lst, int tam_MAX) {               // Cria um novo registro do tipo "LISTA"
  lst->pos = 0;
  lst->MAX = tam_MAX;
  lst->arr = (int *)(malloc(tam_MAX * sizeof(int)));
  if (lst->arr == NULL)
    printf("Falha na alocação de memória.");
}
void Apagar(LISTA *lst) { free(lst->arr); }         // Apaga registro
int Contar(LISTA *lst, int valor){                  // Conta quantas ocorrências tem na lista
  int aux = 0;
  for (int i = 0; i < (int)lst->MAX; i++){
    if (lst->arr[i] == valor)
      aux++;
  }
  return aux;
}
int Pop(LISTA *lst){                                // Remove e retorna o último elemento da Lista.
  if (lst->pos > 0){
    lst->pos--;
    if (lst->pos == 0)
      return(-1);
    else
      return(lst->arr[lst->pos]);
  }
  return(-1);
}
void InserirPos(LISTA *lst, int pos, int valor){    // Insere elementos a partir da posição dada
  if (pos < 0 || pos > lst->pos || pos >= (int)lst->MAX || lst->pos >= (int)lst->MAX){
    printf("Posição inválida!\n");
    return;
  } else {
    for (int i = lst->pos; i > pos; i--){ // Arrastando elementos da lista
      lst->arr[i] = lst->arr[i-1];        // Inserindo elemento
    }
  }
  lst->arr[pos] = valor;
  lst->pos++;
}
void Copiar(LISTA *lst1, LISTA *lst2){              // Faz cópia da segunda lista na primeira
  if (lst2->pos <= 0) {
    printf("Não há elementos na lista.\n");
    return;
  } else {
    if ((int)lst1->MAX < lst2->pos+1) { // Lista não tem espaço suficiente
      int MAXaux = lst2->pos-1;
      int *pAux = (int*)(realloc(lst1->arr, MAXaux * sizeof(int))); 
      if (pAux == NULL){  // Realocando memória
        printf("Falha na realocação de memória\n");
        free(pAux);
        return;
      } else {
        lst1->arr = pAux;
        lst1->MAX = MAXaux;
      }
    }
    lst1->pos = lst2->pos;
    for (int i = 0; i < lst2->pos; i++){  // Inserindo elementos
      lst1->arr[i] = lst2->arr[i];
    }
  }
}
void Estender(LISTA *lst1, LISTA *lst2){            // Faz cópia da segunda no fim da primeira
  if (lst2->pos <= 0) {
    printf("Não há elementos na lista.\n");
    return;
  } else {
    if ((int)lst1->MAX < lst2->pos+1) { // Lista não tem espaço suficiente
      int MAXaux = lst2->pos-1 + lst1->pos;
      int *pAux = (int*)(realloc(lst1->arr, MAXaux * sizeof(int))); 
      if (pAux == NULL){  // Realocando memória
        printf("Falha na realocação de memória\n");
        free(pAux);
        return;
      } else {
        lst1->arr = pAux;
        lst1->MAX = MAXaux;
      }
    }
    for (int i = lst1->pos; i < lst2->pos + lst1->pos; i++){  // Inserindo elementos
      lst1->arr[i] = lst2->arr[i-lst1->pos];
    }
    lst1->pos = lst1->pos + lst2->pos;
  }
}
void Inverter(LISTA *lst1, LISTA *lst2){            // Faz cópia da segunda lista na primeira na ordem inversa
  if (lst2->pos <= 0)
    printf("Não há elementos na lista.\n");
  else {
    if ((int)lst1->MAX < lst2->pos+1) { // Lista não tem espaço suficiente
      int MAXaux = lst2->pos;
      int *pAux = (int*)(realloc(lst1->arr, MAXaux * sizeof(int))); 
      if (pAux == NULL){  // Realocando memória
        printf("Falha na realocação de memória\n");
        free(pAux);
        return;
      } else {
        lst1->arr = pAux;
        lst1->MAX = MAXaux;
      }
    }
    lst1->pos = lst2->pos;
    for (int i = 0; i < lst1->pos; i++){  // Inserindo elementos na ordem inversa
      lst1->arr[(lst2->pos-1)-i] = lst2->arr[i];
    }
  }
}
void Redimensionar(LISTA *lst, int MAX){            // Redimensionar a memória alocada dinamicamente, para mais ou para menos
  if (lst->pos > MAX){
    printf("Impossível desalocar memória. Elementos presentes na lista.\n");
  } else {
    int *pAux = (int*)(realloc(lst->arr, MAX * sizeof(int))); 
    if (pAux == NULL){  // Realocando memória
      printf("Falha na realocação de memória\n");
      free(pAux);
      return;
    } else {
      lst->arr = pAux;
      lst->MAX = MAX;
    }
  }
}
void Ordenar(LISTA *lst){                           // Pega lista desordenada e ordena em ordem crescente
  if (lst->pos <= 0){
    printf("Não há elementos na lista.\n");
    return;
  } else {
    for (int i = 0; i < lst->pos; i++){ // Passando elementos da lista para função que ordena
      Inserir_Ord(lst->arr, i, lst->MAX, lst->arr[i]);
    }
  }
}

// ============================= FUNÇÕES COM ALOCAÇÃO DINÂMICA =============================
void InserirPos_V2(LISTA *lst, int pos, int valor){     // Insere elementos a partir da posição dada
  if (pos < 0 || pos > lst->pos){
    printf("Posição inválida!\n");
    return;
  } else {
    for (int i = lst->pos; i > pos; i--){ // Arrastando elementos da lista
      lst->arr[i] = lst->arr[i-1];        // Inserindo elemento
    }
    printf("%d %d\n", lst->pos, lst->MAX);
    if (lst->pos >= (int)lst->MAX) {  // Aumentando memória dicamicamente quando lista chega ao fim
       Redimensionar(lst, lst->MAX+1);
    }
  }
  lst->arr[pos] = valor;
  lst->pos++;
}
void Copiar_V2(LISTA *lst1, LISTA *lst2){               // Faz cópia da segunda lista na primeira
  if (lst2->pos <= 0) {
    printf("Não há elementos na lista.\n");
    return;
  } else {
    if ((int)lst1->MAX < lst2->pos+1) { // Lista não tem espaço suficiente
      Redimensionar(lst1, lst2->pos);
    }
    lst1->pos = lst2->pos;
    for (int i = 0; i < lst2->pos; i++){  // Inserindo elementos
      lst1->arr[i] = lst2->arr[i];
    }
  }
}
void Estender_V2(LISTA *lst1, LISTA *lst2){             // Faz cópia da segunda no fim da primeira
  if (lst2->pos <= 0) {
    Redimensionar(lst1, lst2->pos);
  }
  for (int i = lst1->pos; i < lst2->pos + lst1->pos; i++){  // Inserindo elementos
    lst1->arr[i] = lst2->arr[i-lst1->pos];
  }
  lst1->pos = lst1->pos + lst2->pos;
}
void Inverter_V2(LISTA *lst1, LISTA *lst2){             // Faz cópia da segunda lista na primeira na ordem inversa
  if (lst2->pos <= 0)
    printf("Não há elementos na lista.\n");
  else {
    if ((int)lst1->MAX < lst2->pos+1) { // Lista não tem espaço suficiente
      Redimensionar(lst1, lst2->pos);
    }
    lst1->pos = lst2->pos;
    for (int i = 0; i < lst1->pos; i++){  // Inserindo elementos na ordem inversa
      lst1->arr[(lst2->pos-1)-i] = lst2->arr[i];
    }
  }
}
void Inserir_Ord(int arr[], int pos, int MAX, int elemento) {   // Insere elementos na lista ordenadamente
  int aux = pos;
  if (pos >= MAX) {
    printf("Lista cheia!\n");
    return;
  } else {
    for (int i = 0; i < pos; i++) // Buscar índice de inserir
      if (arr[i] > elemento){
        aux = i;
        break;
      }
    for (int i = pos; i > aux; i--) // Arrastanto elementos
      arr[i] = arr[i-1];
    arr[aux] = elemento; // Inserindo elemento
    pos++;
  }
}

int main(){
  
  LISTA Lista1;        // Iniciando novo registro
  Criar(&Lista1, 2);   // Criando lista
  Imprimir(&Lista1);

  return 0;
}