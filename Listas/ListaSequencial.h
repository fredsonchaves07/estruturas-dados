#define MAX 100
#include  <stdlib.h>
const elemento VL_NULO = {0, ""};


struct lista{
    int qtd;
    elemento dados[100] ;
};

typedef struct lista Lista;

Lista * cria_lista(Lista *li);

void libera_lista(Lista *li);

// int lista_invalida(Lista *li);

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_elemento_final(Lista *li, elemento a1);

int insere_elemento_inicio(Lista *li, elemento a1);

int insere_elemento_ordenado(Lista *li, elemento a1);

int remove_elemento_inicio(Lista *li);

int remov_elemento_meio(Lista *li);

int buscar_elemento(Lista *li, int pos, elemento *a1);

int alteracao_elemento(Lista *li, int pos, elemento *a1);

int remove_elemento(Lista *li, int pos);

Lista * cria_lista(Lista *li){
    li = (Lista*)  malloc(sizeof(struct lista));
    li -> qtd = 0;

    return li;
}

void libera_lista(Lista *li){
    free(li);
}

// int lista_invalida(Lista *li){
//     if(li == 0){
//         return 0;
//     }
//     return 1;
// }

int tamanho_lista(Lista *li){
  return li -> qtd;
    
}

int lista_cheia(Lista *li){
  return (li ->qtd == MAX);
}

int lista_vazia(Lista *li){
  return (li ->qtd == 0);
}

int insere_elemento_final(Lista *li, elemento a1){
  if(lista_cheia(li)){
    return 0;
  }

  li ->dados[li ->qtd] = a1;
  li ->qtd ++;

  return 1;
}

int buscar_elemento(Lista *li, int pos, elemento *a1){
  if(pos < 0 || pos == 0 || pos > li->qtd){
    return 0;
  }
  
  *a1 = li->dados[pos -1];
  return 1;
}

int alterar_elemento(Lista *li, int pos, elemento a1){
    if(pos < 0 || pos == 0 || pos > li->qtd){
    return 0;
  }

  li->dados[pos - 1] = a1;
  return 1;
}

int remove_elemento(Lista *li, int pos){
  if(pos < 0 || pos == 0 || pos > li->qtd){
    return 0;
  }

  for(int i = pos - 1; i < li->qtd - 1; i++){
    li->dados[i] = li->dados[i + 1];
  }
  li->qtd -- ;
  return 1;
}