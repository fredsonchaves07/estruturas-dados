#define MAX 100
#include  <stdlib.h>
#include "arvore_binaria.h"

struct lista{
    int qtd;
    Arvorebin arvores;
};

typedef struct lista Lista;

Lista * cria_lista(Lista *li){
    li = (Lista*)  malloc(sizeof(struct lista));
    li -> qtd = 0;

    return li;
}

void libera_lista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
  return li -> qtd;  
}

int lista_cheia(Lista *li){
  return (li ->qtd == MAX);
}

int lista_vazia(Lista *li){
  return (li ->qtd == 0);
}

int insere_elemento_final(Lista *li, Arvorebin a1){
  if(lista_cheia(li)){
    return 0;
  }

  li ->arvores[li ->qtd] = *a1;
  li ->qtd ++;

  return 1;
}

int buscar_elemento(Lista *li, int pos, Arvorebin a1){
  if(pos < 0 || pos == 0 || pos > li->qtd){
    return 0;
  }
  
  *a1 = li->arvores[pos -1];
  return 1;
}

int remove_elemento(Lista *li, int pos){
  if(pos < 0 || pos == 0 || pos > li->qtd){
    return 0;
  }

  for(int i = pos - 1; i < li->qtd - 1; i++){
    li->arvores[i] = li->arvores[i + 1];
  }
  li->qtd -- ;
  return 1;
}