#include <stdio.h>
#include <stdlib.h>

typedef struct dados Dados;

typedef struct fila{
    int max;
    int total;
    int inicio;
    int final;
    Dados *dados;
} *Fila;

Fila fila(int max){
    Fila F = malloc(sizeof(struct fila));
    F->max = max;
    F->total = 0;
    F->inicio = 0;
    F->final = 0;
    F->dados = malloc(max * sizeof(Dados));

    return F;
}

int vaziaf(Fila f){
    if(f->total == 0){
        return 1;
    }

    return 0;
}

int cheiaf(Fila f){
    if(f->total == f->max){
        return 1;
    }

    return 0;
}

void efileira(Dados dados, Fila f){
    if(cheiaf(f)){
        printf("Fila cheia. Não será possível adicionar\n");
        abort();
    }

    f->dados[f->final] = dados;
    f->final += 1;
    f->total += 1;
}

Dados desenfileira(Fila f){
    if(vaziaf(f)){
        printf("Fila vazia\n");
        abort();
    }

    Dados dados = f->dados[f->inicio];
    f->inicio ++;
    f->total --;
    return dados;
}

void destroifila(Fila *f){
    free((*f)->dados);
    free(*f);
    *f = NULL;
}