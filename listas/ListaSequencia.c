#include "ListaSequencial.h";

struct lista{
    int qtd;
    aluno dados[MAX];
};

Lista * cria_lista(){
    // Cria um ponteiro do tipo lista
    Lista *li;

    // Realiza a alocação estática na memória
    li = (Lista*)  malloc(sizeof(struct lista));
    // Verifica se a lista está alocada;
    if(li != NULL){
        li -> qtd = 0;
    }

    // Retorna a lista de dados;
    return li;

}

void libera_lista(Lista *li){
    free(li);
}

int lista_invalida(Lista *li){
    if(li == NULL){
        return 0;
    }

    return 1;
}

int tamanho_lista(Lista *li){
    if(lista_invalida(li)){
        return -1;
    } else{
        return li -> qtd;
    }
}

int lista_cheia(Lista *li){
    if(lista_invalida(li)){
        return -1;
    } else{
        return (li ->qtd == MAX);
    }
}

int lista_vazia(Lista *li){
    if(lista_invalida(li)){
        return -1;
    } else{
        return (li ->qtd == 0);
    }
}

int insere_elemento_final(Lista *li, aluno a1){
    if(lista_invalida(li) || lista_cheia(li)){
        return 0;
    }

    li ->dados[li ->qtd] = a1;
    li ->qtd ++;

    return 1;
}

int insere_elemento_inicio(Lista *li, aluno a1){
    if(lista_invalida(li) || lista_cheia(li)){
        return 0;
    }

    for(int c = li ->qtd -1; c > 0; c --){
        li ->dados[c + 1] = li ->dados[c];
    }

    li -> dados[0] = a1;
    li -> qtd ++;
    return 1;
}

int insere_elemento_ordenado(Lista *li, aluno a1){
    aluno aux;
    if(lista_invalida(li) || lista_cheia(li)){
        return 0;
    }

    insere_elemento_final(li, a1);

    for(int c = 0; c < li->qtd; c ++){
        for(int k = c + 1; k < li -> qtd ; k++){
            if(li->dados[k].matricula < li ->dados[c].matricula){
                aux = li->dados[k];
                li ->dados[k] = li->dados[c];
                li ->dados[c] = aux;
            }
        }
    }

    li -> qtd ++;
    return 1;
}

int remove_elemento_final(Lista *li){
    if(lista_invalida(li) || lista_vazia(li)){
        return 0;
    }

    li->qtd --;
    return 1;
}

int remove_elemento_inicio(Lista *li){
    if(lista_invalida(li) || lista_vazia(li)){
        return 0;
    }

    for(int c = 0; c < li->qtd - 1; c ++){
        li ->dados[c] = li -> dados[c + 1];
    }

    li->qtd --;
    return 1;
}