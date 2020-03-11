#include <stdio.h>
#include <stdlib.h>

typedef struct dados Dados;

typedef struct arvore{
    struct arvore *esq;
    Dados dados;
    struct arvore *dir;
} *Arvorebin;

Arvorebin arvore(Arvorebin esq, Dados dados, Arvorebin dir){
    Arvorebin A = malloc(sizeof(struct arvore));
    A->esq = esq;
    A->dados = dados;
    A->dir = dir;

    return A;
}

