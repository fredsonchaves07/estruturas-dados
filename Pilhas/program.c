#include <stdio.h>
#include <stdlib.h>

struct dados{
    int codigo;
};

#include "pilha.h"

Dados dado1;

int main(){
    dado1.codigo = 3;
    Pilha p = criap(dado1.codigo);
    empilha(p, dado1);


    acessap(p, &dado1);
    printf("%d\n", dado1.codigo);
    desempilha(p);
    acessap(p, &dado1);
    printf("%d\n", dado1.codigo);
    
}