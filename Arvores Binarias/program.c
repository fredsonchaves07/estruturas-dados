#include <stdio.h>
#include <stdlib.h>

struct dados{
    int codigo;
};

#include "arvore_binaria.h"

Dados dados1;

int main(){
    dados1.codigo = 4;
    Arvorebin A4 = arvore(NULL, dados1, NULL);
    dados1.codigo = 5;
    Arvorebin A5 = arvore(NULL, dados1, NULL);
    dados1.codigo = 6;
    Arvorebin A6 = arvore(NULL, dados1, NULL);
    dados1.codigo = 3;
    Arvorebin A3 = arvore(NULL, dados1, A6);
    dados1.codigo = 2;
    Arvorebin A2 = arvore(A4, dados1, A5);
    dados1.codigo = 1;
    Arvorebin A1 = arvore(A2, dados1, A3);
    
    printf("Pecorrendo dados em Ordem\n");
    pecurso_ordem(A1);
    printf("\nPecorrendo dados em Pré Ordem\n");
    pecurso_preordem(A1);
    printf("\nPecorrendo dados em Pós Ordem\n");
    pecurso_posordem(A1);

}