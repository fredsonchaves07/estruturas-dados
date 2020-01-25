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

// Estrutura de Dados que arvore armanezará
struct dados{
  char nome[100];
  float valor;
  int desconto_indicacao;
};

// Inclusão das estrutuas de dados necessárias
#include "arvore.h"
#include "lista.h"

// Declarações de variaveis das estrutuas
Dados Pedido;
Arvore A;
Lista listaarvore;

// Declarações das Funções
void limpar_tela();
void terminal();
void cadastroPedido();
void verificaIndicacao(Dados pedido);
float calculaDesconto(int desconto, Dados pedido);
void descontoArvorePaiFilha(Arvore arvorepai, Arvore arvorefilha);
void visualizarClientes();


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

// Função que retorna quantidade de clientes e indicações
void visualizarClientes(){
  limpar_tela();

  Dados dadosaux;
  Dados dadospai;

  printf("RELATÓRIO DE CLIENTES\n\n");
  printf("Total de Clientes cadastrados: %d\n\n", tamanhoLista(listaarvore));
  printf("Clientes Cadastrados:\n\n");
  exibeClientes(listaarvore);


  printf("\n\n");
  terminal();
}

//Função que retorna o percentual de desconto das arvores pai e filha
void descontoArvorePaiFilha(Arvore arvorepai, Arvore arvorefilha){
    int desconto;
    Dados retorno;

    if(isRaiz(arvorepai)){
      if(possuiFilha(arvorepai)){
        retorno = retornaDadosArvore(arvorepai);
        if(retorno.desconto_indicacao < 20){
            retorno.desconto_indicacao += 1;
            alteraLista(listaarvore, retorno);

        }

        printf("%s possui %d%% de desconto\n", retorno.nome, retorno.desconto_indicacao);
        return ;
      }
    }

    Arvore arvoreaux = arvorepai;
    arvorefilha = arvoreaux;
    arvorepai = retornaArvoreRaiz(arvorefilha);

    if(isRaiz(arvorefilha)){
      return;
    }

    if(possuiFilha(arvorefilha)){
      retorno = retornaDadosArvore(arvorepai);
      if(retorno.desconto_indicacao < 20)
        if((retorno.desconto_indicacao + 5) < 20){
            retorno.desconto_indicacao += 5;
        } else{
            retorno.desconto_indicacao = retorno.desconto_indicacao + (20 - retorno.desconto_indicacao);
        }
        alteraLista(listaarvore, retorno);
      printf("%s possui %d%% de desconto\n", retorno.nome, retorno.desconto_indicacao);

      retorno = retornaDadosArvore(arvorefilha);
      if(retorno.desconto_indicacao < 20){
        retorno.desconto_indicacao += 1;
        alteraLista(listaarvore, retorno);
      }

      printf("%s possui %d%% de desconto\n", retorno.nome, retorno.desconto_indicacao);

      if(isRaiz(arvorepai)){
        return;
      }

      Arvore arvoreaux = arvorepai;
      arvorefilha = arvoreaux;
      arvorepai = retornaArvoreRaiz(arvorefilha);

      retorno = retornaDadosArvore(arvorepai);
      
      if(retorno.desconto_indicacao < 20){
        if((retorno.desconto_indicacao + 10) < 20){
          retorno.desconto_indicacao += 10;
        } else{
          retorno.desconto_indicacao = retorno.desconto_indicacao + (20 - retorno.desconto_indicacao);
        }
        alteraLista(listaarvore, retorno);
      } 
      
      printf("%s possui %d%% de desconto\n", retorno.nome, retorno.desconto_indicacao); 
    }
}

//Função que realiza o calculo de desconto
float calculaDesconto(int desconto, Dados pedido){
  float valor_pagar = pedido.valor - (pedido.valor * ((float) desconto / 100));

  return valor_pagar;
}

// Função que verifica a indicação
void verificaIndicacao (Dados pedido){
  limpar_tela();
  printf("IDENTIFICAÇÃO DE INDICAÇÕES\n\n");
  
  Dados dadosaux;
  Arvore arvorepai;
  Arvore arvorefilha;

  printf("Digite o nome da pessoa quem indicou: ");
  flush_in();
  scanf("%[^\n]s", dadosaux.nome);
  

  if(verificaDados(listaarvore, dadosaux)){

   arvorepai = retornaArvore(listaarvore, dadosaux);
   arvorefilha = arvore(NULL, pedido, arvorepai);
   A = arvorefilha;
   adicionaLista(&listaarvore, A);
   adicionaArvore(arvorepai, A);

   descontoArvorePaiFilha(arvorepai, arvorefilha);

   printf("\nValor da compra: %.2f\n", pedido.valor);
   printf("%s poderá ganhar até 20%% de desconto indicando mais clientes\n\n\n", pedido.nome);
   terminal();
  } else{
    printf("Indicação não encontrada\n");
    printf("Pedido deverá ser cadastrado como sem indicação\n\n");
    terminal();
  }
}

// Função que realiza o cadastro do pedido
void cadastroPedido(){
  limpar_tela();
  int indicacao;

  printf("CADASTRO DE PEDIDO\n\n");

  printf("Digite o nome do cliente: ");
  flush_in();
  scanf("%[^\n]s", Pedido.nome);
  printf("Digite o valor da compra: ");
  scanf("%f", &Pedido.valor);

  if(verificaDados(listaarvore, Pedido)){
    Arvore arvoreaux = retornaArvore(listaarvore, Pedido);
    Dados dadosaux = retornaDadosArvore(arvoreaux);

    if(dadosaux.desconto_indicacao == 0){
      printf("%s não possui desconto\n\n", Pedido.nome);
      printf("Valor a ser pago: %.2f\n", Pedido.valor);
      printf("%s poderá ganhar até 20%% de desconto indicando mais clientes\n", dadosaux.nome);
      terminal();
    } else{
      printf("Você indicou cliente(s)! Parabéns!\n");
      printf("Ganhou %d%% de desconto\n", dadosaux.desconto_indicacao);
      printf("\nValor a ser pago: %.2f\n", calculaDesconto(dadosaux.desconto_indicacao, Pedido));
      printf("%s poderá ganhar até 20%% de desconto indicando mais clientes\n\n", dadosaux.nome);
      terminal();
    }
  } else{
       printf("Foi indicado? ([1] Sim [0] Não): ");
       scanf("%d", &indicacao);
       switch(indicacao){
          case 0:
            printf("\nValor a ser pago: %.2f\n", Pedido.valor);
            printf("%s poderá ganhar até 20%% de desconto indicando mais clientes\n\n\n", Pedido.nome);
            Pedido.desconto_indicacao = 0;
            A = arvore(NULL, Pedido, NULL);
            adicionaLista(&listaarvore, A);
            terminal();
            break;
          case 1:
            verificaIndicacao(Pedido);
            exit(0);
            break;
  }
  }
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
      exit(1);
      break;
    case 2:
      visualizarClientes();
      terminal();
      break;
    default:
    printf("Comando não localizado!\n");
  }
}

//Inicialização do Programa
int main(){
  terminal();
  return 0;
}