#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    char caracter;
};

#include "fila.h"

int main(){
    Fila filaCaracter = fila(100);

    char primeiraPalavra[100];
    char segundaPalavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", primeiraPalavra);
    
    for(int i = strlen(primeiraPalavra) - 1; i >= 0; i--){
        Dados caracter;
        caracter.caracter = primeiraPalavra[i];
        enfileira(caracter, filaCaracter);
    }

    for(int i = 0; i < strlen(primeiraPalavra); i++){
        segundaPalavra[i] = desenfileira(filaCaracter).caracter;
    }

    if(strcmp(primeiraPalavra, segundaPalavra) == 0){
        printf("A palavra e palindroma!\n");
    } else{
        printf("A palavra nao e palindroma!\n");
    }

}