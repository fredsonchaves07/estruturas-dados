#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
    char valor;
} Dados;

Dados palavra;


#include "pilha.h"



void palindromo(char *palavra, Pilha *p){
    Dados dados_aux;

    for(int i = 0; i < strlen(palavra); i++){
        dados_aux.valor = palavra[i];
        empilha(*p, dados_aux);
    }
    char nova_palavra [strlen(palavra) - 1];
    
    for(int i = 0; i <= strlen(palavra); i++){
        acessap(*p, &dados_aux);
        strcpy(&nova_palavra[i], &dados_aux.valor);
        desempilha(*p);
    }

    printf("%d\n%d\n", strlen(palavra), strlen(nova_palavra));

    if(strcmp(palavra, nova_palavra) == 0){
        printf("A palavra digitada é um palíndromo\n");
    } else{
        printf("A palavra digitada não é palíndromo\n");
    }

}

int main(){
    Pilha p = criap(100);
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    palindromo(palavra, &p);
}