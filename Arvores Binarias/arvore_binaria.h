#include <stdlib.h>
#include <stdio.h>
#define fmt "%d\n"

typedef struct dados Dados;

typedef struct arvore{
    struct arvore *esq;
    Dados dados;
    struct arvore *dir;
} *Arvorebin;

Arvorebin arvore(Arvorebin esq, Dados dados, Arvorebin dir){
    Arvorebin A = malloc(sizeof(struct arvore));
    A->esq = esq;
    A->dir = dir;
    A->dados = dados;

    return A;
}

void pecurso_ordem(Arvorebin A){
    if(A == NULL){
        return;
    }

    pecurso_ordem(A->esq);
    printf(fmt, A->dados);
    pecurso_ordem(A->dir);
}

void pecurso_preordem(Arvorebin A){
    if(A == NULL){
        return;
    }

    printf(fmt, A->dados);
    pecurso_preordem(A->esq);
    pecurso_ordem(A->dir);
}

void pecurso_posordem(Arvorebin A){
    if(A == NULL){
        return;
    }

    pecurso_posordem(A->esq);
    pecurso_posordem(A->dir);
    printf(fmt, A->dados);
}

void destroi(Arvorebin *A){
    if(*A == NULL){
        return;
    }

    destroi(&(*A)->esq);
    destroi(&(*A)->dir);
    free(*A);
    *A = NULL;
}