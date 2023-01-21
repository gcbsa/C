#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no_lista No_lista;

struct lista{
  int nro_elementos;
  No_lista * cabeca;
};

struct no_lista{
  int elemento;
  No_lista * proximo;
};

Lista * criar_lista(){
  Lista * nova_lista = (Lista *)malloc(sizeof(Lista));

  if(nova_lista != NULL){
    nova_lista->cabeca = NULL;
    nova_lista->nro_elementos = 0;
  }

  return nova_lista;
}

int tamanho_lista(Lista * lista){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  return lista->nro_elementos;
}

int existe_elemento(Lista * lista, int elemento){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(lista->nro_elementos < 1) return FALHA;
  
  for(No_lista * no_auxiliar = lista->cabeca; no_auxiliar->elemento != elemento; no_auxiliar = no_auxiliar->proximo)
    if(no_auxiliar->proximo == NULL) return FALHA;
  
  return SUCESSO;
}

int encontrar_elemento(Lista * lista, int posicao, int * elemento){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(posicao < 1 || posicao > lista->nro_elementos) return FALHA;

  No_lista * no_auxiliar = lista->cabeca;
  for(int i = 1; i < posicao; i++)
      no_auxiliar = no_auxiliar->proximo;

  *elemento = no_auxiliar->elemento;

  return SUCESSO;
}

int encontrar_posicao(Lista * lista, int * posicao, int elemento){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  *posicao = 1;
  for(No_lista * no_auxiliar = lista->cabeca; no_auxiliar->elemento != elemento; no_auxiliar = no_auxiliar->proximo){
    if(no_auxiliar->proximo == NULL){
      *posicao = -1;
      return FALHA;
    }
    (*posicao)++;
  }
    
  return SUCESSO;
}

int inserir_lista(Lista * lista, int posicao, int elemento){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(posicao < 1 || posicao > lista->nro_elementos+1) return FALHA;

  No_lista * novo_no = (No_lista *)malloc(sizeof(No_lista));
  if(novo_no == NULL) return SEM_MEMORIA;
  novo_no->elemento = elemento;
  
  if(posicao == 1){
    novo_no->proximo = lista->cabeca;
    lista->cabeca = novo_no;
  }else{  
    No_lista * no_auxiliar = lista->cabeca;
    for(int i = 2; i < posicao; i++)
      no_auxiliar = no_auxiliar->proximo;
    
    novo_no->proximo = no_auxiliar->proximo;
    no_auxiliar->proximo = novo_no;
  }
  
  lista->nro_elementos++;
  
  return SUCESSO;
}

int atualizar_lista(Lista * lista, int posicao, int elemento){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(posicao < 1 || posicao > lista->nro_elementos) return FALHA;

  No_lista * no_auxiliar = lista->cabeca;
  for(int i = 1; i < posicao; i++)
    no_auxiliar = no_auxiliar->proximo;
    
  no_auxiliar->elemento = elemento;
  
  return SUCESSO;
}

int remover_lista(Lista * lista, int posicao){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(posicao < 1 || posicao > lista->nro_elementos) return FALHA;

  No_lista * no_destruir = lista->cabeca;
  
  if(posicao == 1)
    lista->cabeca = lista->cabeca->proximo;
  else{
    No_lista * no_anterior;
    for(int i = 1; i < posicao; i++){
      no_anterior = no_destruir;
      no_destruir = no_destruir->proximo;
    }
    
    no_anterior->proximo = no_destruir->proximo;
  }
  
  free(no_destruir);
  lista->nro_elementos--;
  
  return SUCESSO;
}

int reverter_lista(Lista * lista){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(lista->nro_elementos < 2) return FALHA;

  int nro_trocas = lista->nro_elementos/2;

  for(int i = 0; nro_trocas; i++){
    int temp[2];
    encontrar_elemento(lista, i+1, &temp[0]);
    encontrar_elemento(lista, lista->nro_elementos-i, &temp[1]);
    atualizar_lista(lista, i+1, temp[1]);
    atualizar_lista(lista, lista->nro_elementos-i, temp[0]);
    nro_trocas--;
  }
  
  return SUCESSO;
}

int imprimir_lista(Lista * lista){
  if(lista == NULL) return PONTEIRO_INVALIDO;
  
  for(No_lista * no_auxiliar = lista->cabeca; no_auxiliar != NULL; no_auxiliar = no_auxiliar->proximo)
    printf("[ %d ]  ->  ", no_auxiliar->elemento);
  printf("NULL\n");

  return SUCESSO;
}

int esvaziar_lista(Lista * lista){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(lista->nro_elementos < 1) return FALHA;

  while(lista->nro_elementos > 0)
    remover_lista(lista, 1);

  return SUCESSO;
}

int destruir_lista(Lista * lista){
  if(lista == NULL) return PONTEIRO_INVALIDO;

  if(lista->nro_elementos > 0){
    No_lista * no_auxiliar = lista->cabeca;
    while(no_auxiliar != NULL){
      No_lista * no_destruir = no_auxiliar;
      no_auxiliar = no_auxiliar->proximo;
      
      free(no_destruir);
    }
  }
  
  free(lista);
  
  return SUCESSO;
}
