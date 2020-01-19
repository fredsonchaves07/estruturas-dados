#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Diretiva principais de compilação
#ifdef __unix__   
  #include <unistd.h>

#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
  #define OS_Windows
  #include <windows.h>
#endif

// Estrutura do Pedido de Petshop
 typedef struct {
    int codigo;
    float valor;
    char cliente[100];
} Pedido;

typedef struct{
    char nome[100];
} dados;

//Importação da estrutura de arvore
#include "arvore_binaria.h"

//Variaveis das estruturas
Pedido pedido;
Dados  indicacao;

//Variavel de arvore
Arvorebin A;

// Declarações das Funções
void limpar_tela();
void terminal();
void cadastroPedido();
void verificaIndicacao(Pedido pedido);
int isPrimeiroCliente();
float calculaDesconto(float valor);

//Funções Auxiliares
void limpar_tela(){
  #ifdef OS_Windows
    system("cls");
  #else
     system("clear");
  #endif
}

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

//Cadastro de Pedido;
void cadastroPedido(){
  limpar_tela();
  flush_in();
  int indicado;

  printf("CADASTRO DO PEDIDO\n\n");
  printf("Digite o nome do cliente: ");
  scanf("%[^\n]s", pedido.cliente);
  flush_in();
  printf("Digite o valor do pedido: ");
  scanf("%f", &pedido.valor);
  printf("Foi indicado? ([1] Sim [0] Não): ");
  scanf("%d", &indicado);

  if(indicado == 1){
    verificaIndicacao(pedido);
    exit(0);
  } else{
        printf("O cliente não tem desconto por indicação\n");
        printf("Valor a ser pago: %.2f\n\n", pedido.valor);
        strcpy(indicacao.nome, pedido.cliente);
        A = arvore(NULL, indicacao, NULL);
        terminal();
    }
}

//Verifica indicação
void verificaIndicacao(Pedido pedido){
    char nome[100];
    Dados dadosaux;

    printf("Digite o nome da pessoa quem indicou: ");
    flush_in();
    scanf("%[^\n]s", nome);

    if(strcmp(pecurso_ordem(A).nome, nome) == 0){
        strcpy(dadosaux.nome, nome);
        Arvorebin arvoreaux = arvore(NULL, dadosaux, NULL);
        if(esquerda_vazia(A)){
            adiciona_esquerda(A, arvoreaux);
            printf("Como indicação o cliente ganhou 10%% de desconto\n");
            printf("Valor a ser pago: %.2f\n\n", calculaDesconto(pedido.valor));
            terminal();
        } else if(direita_vazia(A)){
            adiciona_direita(A, arvoreaux);
            printf("Como indicação o cliente ganhou 10%% de desconto\n");
            printf("Valor a ser pago: %.2f\n\n", calculaDesconto(pedido.valor));
            terminal();
        } else{
            printf("Não é possível adicionar o desconto pois a indicação passou do limite\n");
            printf("Valor a ser pago: %.2f\n\n", pedido.valor);
            terminal();
        }
    } else{
        printf("Indicação não encontrada\n");
        printf("Pedido deve ser cadastrado sem indicação\n\n");
        terminal();
    }
}

//Calcula Desconto
float calculaDesconto(float valor){
    return valor - (valor * 0.1);
}


//Menu principal da aplicação
void terminal(){
  int comando;

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("     BEM VINDO AO SISTEMA Petshop     \n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("\n\n");
  printf("[1] - Para Cadastrar um Pedido\n");
  printf("[2] - Para visualizar indicações\n");
  printf("[0] - Para sair\n");
  
  printf("Selecione uma opção: ");
  scanf("%d", &comando);

  switch(comando){
    case 1:
      cadastroPedido();
      break;
    case 0:
      printf("Saindo do Programa\n");
      break;
    default:
    printf("Comando não localizado!\n");
  }
}

int main(){
  terminal();
  return  0;
}
