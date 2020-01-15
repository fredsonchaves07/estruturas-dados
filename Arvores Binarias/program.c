#include <stdio.h>
#include <stdlib.h>

struct dados{
    int codigo;
};

#include "arvore_binaria.h"

Dados dados1;

int main(){
    dados1.codigo = 1;
    Arvorebin A = arvore(NULL, NULL, dados1);
    
}