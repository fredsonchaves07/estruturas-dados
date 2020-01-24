#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

Dados pecurso_ordem(Arvorebin A){
    if(A == NULL){
        Dados dadosaux;
        strcpy(dadosaux.nome, "");
        return dadosaux;
    }

    pecurso_ordem(A->esq);
    return A->dados;
    pecurso_ordem(A->dir);
}

void pecurso_preordem(Arvorebin A){
    if(A == NULL){
        return;
    }

    printf(fmt, A->dados);
    pecurso_preordem(A->esq);
    pecurso_preordem(A->dir);
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

int esquerda_vazia(Arvorebin A){
    if(A->esq == NULL){
        return 1;
    }

    return 0;
}

int direita_vazia(Arvorebin A){
    if(A->dir == NULL){
        return 1;
    }

    return 0;
}

void adiciona_esquerda(Arvorebin A, Arvorebin esquerda){
    A->esq = esquerda;
}

void adiciona_direita(Arvorebin A, Arvorebin direita){
    A->dir = direita;
}

/*
Dados lista_arvore(Lista A){
    if(A == NULL){
        Dados dadosaux = {};
        return dadosaux;
    }

    pecurso_ordem(A->esq);
    return A->dados;
    pecurso_ordem(A->dir);
}
*/
