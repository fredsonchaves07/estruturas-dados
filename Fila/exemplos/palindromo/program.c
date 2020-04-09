#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    char caracter[100];
};

#include "fila.h"

int main(){
    Dados dados;
    strcpy(dados.caracter, "carro");
    
    for(int i = 0; i <= sizeof(dados); i++){
        printf("%d\n", i);
    }
    Fila F = fila(100);
}