#include <stdlib.h>
#include <stdio.h>

typedef struct dados Dados;

typedef struct pilha{
    int max;
    int topo;
    Dados *dados;
} *Pilha;

Pilha criap(int max){
    Pilha P = malloc(sizeof(struct pilha));
    P->max = max;
    P->topo =  -1;
    P->dados = malloc(max * sizeof(Dados));
    return P;
}

int vaziap(Pilha p){
    if(p->topo == -1){
        return 1;
    }
    return 0;
}

int cheiap(Pilha p){
    if(p->topo == p->max - 1){
        return 1;
    }
    return 0;
}

void empilha(Pilha p, Dados dados){
    if(cheiap(p)){
        printf("A pilha está cheia");
        abort();
    }

    p->topo ++;
    p->dados[p->topo] = dados;
}

void desempilha(Pilha p){
    if(vaziap(p)){
        printf("A pilha está vazia");
        abort();
    }

    p->topo --;
}

void destroip(Pilha *p){
    free((*p)->dados);
    free(*p);
    *p == NULL;
}

Dados *acessap(Pilha p, Dados *dados){
    if(vaziap(p)){
        printf("Pilha Vazia\n");
        abort();
    }

    *dados = p->dados[p->topo];
}