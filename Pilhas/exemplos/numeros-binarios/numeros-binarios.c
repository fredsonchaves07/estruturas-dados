#include <stdio.h>
#include <stdlib.h>


typedef struct dados{
    int valor;
} Dados;

Dados numero;

#include "pilha.h"


void calcula_binario(Dados numero){
    int numero_aux = numero.valor;
    int divisao_inteira;
    Dados resto_divisao;
    Pilha p = criap(100);
    do{
        resto_divisao.valor = numero_aux % 2;
        divisao_inteira = numero_aux / 2;
        numero_aux = divisao_inteira;
        empilha(p, resto_divisao);
    } while(numero_aux != 0);

    printf("O número %d em binário é igual a: ", numero.valor);
    while(!vaziap(p)){
        acessap(p, &numero);
        printf("%d", numero.valor);
        desempilha(p);
    }
    printf("\n");
}


int main(){

    printf("Digite um número inteiro: ");
    scanf("%d", &numero.valor);

    calcula_binario(numero);
}