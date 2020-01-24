#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    Arvorebin dadosarvore;
    struct no *prox;
} *Lista;

Lista no(Arvorebin a, Lista p){
    Lista n = malloc(sizeof(struct no));
    n->dadosarvore = a;
    n->prox = p;

    return n;
}

void exibe(Lista L){
    while(L != NULL){
         printf("%s\n", L->dadosarvore->dados.nome);
        L = L->prox;
    }
}

int tamanho(Lista L){
    if(L == NULL){
        return 0;
    } 

    return 1 + tamanho(L->prox);
}

int pertence(Lista L, Arvorebin x){
    if(L == NULL){
        return 0;
    }

    if(x == L->dadosarvore){
        return 1;
    }

    return pertence(L->prox, x);
}

void adiciona(Lista *L, Arvorebin x){
    while(*L != NULL && (*L)->dadosarvore < x){
        L = &(*L)->prox;
        
    }
    *L = no(x, *L);
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

Arvorebin retornaArvore(Lista L, Dados dados){
    if(L == NULL){
        return NULL;
    }

    if(strcmp(dados.nome, L->dadosarvore->dados.nome) == 0){
        return L->dadosarvore;
    }

    return retornaArvore(L->prox, dados);
}