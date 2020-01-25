#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  Arvore dadosarvore;
  struct no *prox;
} *Lista;

Lista no(Arvore A, Lista L){
  Lista p = malloc(sizeof(struct no));
  p->dadosarvore = A;
  p->prox = L;

  return p;
}

int tamanhoLista(Lista L){
  if(L == NULL){
    return 0;
  }

  return 1 + tamanhoLista(L->prox);
}

void adicionaLista(Lista *L, Arvore A){
  while(*L != NULL && (*L)->dadosarvore < A){
    L = &(*L)->prox;
  }

  *L = no(A, *L);
}

int verificaDados(Lista L, Dados dados){
    if(L == NULL){
        return 0;
    }

    if(strcmp(dados.nome, L->dadosarvore->dados.nome) == 0){
        return 1;
    }

    return verificaDados(L->prox, dados);
}

Arvore retornaArvore(Lista L, Dados dados){
    if(L == NULL){
        return NULL;
    }

    if(strcmp(dados.nome, L->dadosarvore->dados.nome) == 0){
        return L->dadosarvore;
    }

    return retornaArvore(L->prox, dados);
}

int alteraLista(Lista L, Dados dados){
    if(L == NULL){
        return 0;
    }

    if(strcmp(dados.nome, L->dadosarvore->dados.nome) == 0){
        L->dadosarvore->dados = dados;
        return 1;
    }

    return alteraLista(L->prox, dados);
}

void exibeClientes(Lista L){
    while(L != NULL){
         printf("%s\n", L->dadosarvore->dados.nome);
         L = L->prox;
    }
}

