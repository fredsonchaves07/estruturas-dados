#include <stdlib.h>
#include <stdio.h>

struct dados{
    int codigo;
};

#include "fila.h"

int main(){
    Dados dado1;
    dado1.codigo = 1;
    Dados dado2;
    dado2.codigo = 2;
    Dados dado3;
    dado3.codigo = 3;
    Dados dado4;
    dado4.codigo = 4;
    Dados dado5;
    dado5.codigo = 5;

    Fila F = fila(5);
    efileira(dado1, F);
    efileira(dado2, F);
    efileira(dado3, F);
    efileira(desenfileira(F), F);
    efileira(desenfileira(F), F);
    efileira(dado3, F);

    printf("%d\n", desenfileira(F));
    printf("%d\n", desenfileira(F));
    printf("%d\n", desenfileira(F));
}