#include <stdlib.h>
#include <stdio.h>

typedef struct dados Dados;

typedef struct arvore{
    struct arvore *esq;
    Dados dados;
    struct arvore *dir;
} *Arvorebin;

Arvorebin arvore(Arvorebin esq, Arvorebin dir, Dados dados){
    Arvorebin A = malloc(sizeof(struct arvore));
    A->esq = esq;
    A->dir = dir;
    A->dados = dados;

    return A;
}