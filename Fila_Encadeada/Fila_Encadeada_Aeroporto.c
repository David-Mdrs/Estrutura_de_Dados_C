#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VOO{        // Registro de cada Voo
  int numero, passageiros;
  char *modelo, *piloto;
} VOO;
typedef struct NO{         // No simplesmente encadeado
  struct VOO voo;          // Cada NO vai armazenar um Voo
  struct NO *proximo;
} NO;
typedef struct FILA{       // Fila para armazenar Voos
  struct NO *inicio;
  struct NO *fim;
} FILA;

void criar(FILA *fila);           // Inicializa e aloca memória com campos da Fila
void apagar(FILA *fila);          // Desaloca memória e apaga Fila
void listarVoos(FILA *fila);      // Lista cada aeronave da Fila (Número do voo e piloto)
int qntVoos(FILA *fila);          // Retorna o tamanho da Fila
// Insere um novo Voo ao fim da Fila
void novoVoo(FILA *fila, int numero, int passageiros, char *modelo, char *piloto);
VOO *decolagem(FILA *fila);       // Remove primeiro Voo da Fila
VOO *primeiroVoo(FILA *fila);     // Lista as informações do primeiro Voo

int main(){
  FILA fila;
  criar(&fila);

  novoVoo(&fila, 10, 50, "AZUL", "Geremias");
  novoVoo(&fila, 20, 60, "TAM", "Marciel");
  novoVoo(&fila, 30, 70, "VASP", "Isadora");
  listarVoos(&fila);
  decolagem(&fila);
  listarVoos(&fila);
  primeiroVoo(&fila);

  apagar(&fila);

  return 0;
}

void criar(FILA *fila){
  fila->inicio = fila->fim = NULL;
}
void apagar(FILA *fila){
  NO *auxiliar = fila->inicio, *anterior = NULL;

  while(auxiliar){
    anterior = auxiliar;
    auxiliar = auxiliar->proximo;
    free(anterior);
  }
  fila->inicio = fila->fim = NULL;
}
void listarVoos(FILA *fila){
  NO *auxiliar = fila->inicio;
  int contador = qntVoos(fila);
  if(contador == 0){
    printf("========== NÃO HÁ VOOS DISPONÍVEIS! ==========\n\n");
  } else {
  printf("============= %d VOOS DISPONÍVEIS ============\n", contador);
  printf("=============== LISTANDO VOOS ===============\n\n");
    while(auxiliar){
      printf("Numero do voo: %d\n", auxiliar->voo.numero);
      printf("Piloto: %s\n\n", auxiliar->voo.piloto);
      auxiliar = auxiliar->proximo;
    }
  }
}
int qntVoos(FILA *fila){
  NO *auxiliar = fila->inicio;
  int contador = 0;
  while(auxiliar){
    contador++;
    auxiliar = auxiliar->proximo;
  }
  return contador;
}
void novoVoo(FILA *fila, int numero, int passageiros, char *modelo, char *piloto){
  NO *novoNO = malloc(sizeof(NO));
  novoNO->proximo = NULL;
  novoNO->voo.numero = numero;
  novoNO->voo.passageiros = passageiros;
  novoNO->voo.modelo = modelo;
  novoNO->voo.piloto = piloto;

  if(fila->fim == NULL){                // Fila vazia
    fila->inicio = fila->fim = novoNO;
  } else {                              // Fila não vazia
    fila->fim->proximo = novoNO;
    fila->fim = novoNO;
  }
}
VOO *decolagem(FILA *fila){
  if (fila->inicio) {
    VOO *vooAuxiliar = &(fila->inicio->voo);
    NO *auxiliar = fila->inicio;

    if (fila->inicio == fila->fim){         // Apenas um elemento na Fila
      fila->inicio = fila->fim = NULL;
    } else {                                // Mais de um elemento na Fila
      fila->inicio = fila->inicio->proximo;
    }
    free(auxiliar->voo.piloto);
    free(auxiliar->voo.modelo);
    free(auxiliar);
    return vooAuxiliar;
  } else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}
VOO *primeiroVoo(FILA *fila){
  if(!fila->fim){
    printf("========== NÃO HÁ VOOS DISPONÍVEIS! ==========\n\n");
    exit(1);
  }
  printf("=============== PRIMEIRO VOO ================\n\n");
  printf("Numero do voo: %d\n", fila->inicio->voo.numero);
  printf("Numero de passageiros: %d\n", fila->inicio->voo.passageiros);
  printf("Modelo da aeronave: %s\n", fila->inicio->voo.modelo);
  printf("Piloto: %s\n\n", fila->inicio->voo.piloto);
  return &(fila->inicio->voo);
}