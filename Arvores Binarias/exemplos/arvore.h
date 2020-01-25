#include <stdio.h>
#include <stdlib.h>

typedef struct dados Dados;

typedef struct arvore{
  struct arvore *arvorefilha;
  Dados dados;
  struct arvore *arvorepai;
} *Arvore ;

Arvore arvore(Arvore arvorefilha, Dados dados, Arvore arvorepai){
  Arvore A = malloc(sizeof(struct arvore));
  A->arvorefilha = arvorefilha;
  A->dados = dados;
  A->arvorepai = arvorepai;

  return A;
}

void adicionaArvore(Arvore A, Arvore arvorefilha){
  A->arvorefilha = arvorefilha;
}

Dados retornaDadosArvore(Arvore A){
  return A->dados;
}

int isRaiz(Arvore A){
  if(A->arvorepai == NULL){
    return 1;
  }

    return 0;
}

int possuiFilha(Arvore A){
  if(A->arvorefilha == NULL){
    return 0;
  }

  return 1;
}

int possuiPai(Arvore A){
  if(A->arvorepai == NULL){
    return 0;
  }

  return 1;
}

Arvore retornaArvoreRaiz(Arvore A){
  if(A == NULL){
    return NULL;
  }

  return A->arvorepai;
}

Arvore retornaArvoreFilha(Arvore A){
  return A->arvorefilha;
}


