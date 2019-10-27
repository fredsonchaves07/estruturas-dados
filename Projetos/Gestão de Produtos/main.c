
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

// Estrutura principal de produtos
typedef struct {
    int codigo;
    char descricao[100];
} elemento;

elemento produto;


//Declarações das funções principais
int terminal();
void limpar_tela();
int adicionaProduto();
int buscaProduto();
int buscarProdutoCodigo();
int buscarProdutoDescricao();
int alterarProduto();
int alterarProdutoCodigo();
int alterarProdutoDescricao();
int relatorio();

//Inclusão da lista sequencial
#include "ListaSequencial.h"

//Declaração do tipo lista
Lista lista_produtos;

//Funçoes auxiliares
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

//Função principal de adicionar produto
int adicionaProduto(){
  int comando;
  int codigo;
  char descricao[100];
  elemento resultado;
  int pos;

  limpar_tela();

  printf("CADASTRO DE PRODUTOS\n\n");

  printf("Digite o código do produto: ");
  scanf("%d", &codigo);
  flush_in();

  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c, &produto)){
      if(produto.codigo == codigo){
         resultado = produto;
         pos = c;
      }
    }
  }

  buscar_elemento(&lista_produtos, pos, &produto);

  if(resultado.codigo != produto.codigo || tamanho_lista(&lista_produtos) == 0){
    printf("Digite a descrição do produto: ");
    scanf("%[^\n]s", descricao);
    flush_in();

    produto.codigo = codigo;
    strcpy(produto.descricao, descricao);
    if(insere_elemento_final(&lista_produtos, produto)){
      printf("Produto Adicionado!\n");
    } 
  } else{
    printf("Insira um produto com código diferente \n");
  }

  printf("Adicionar mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);
  flush_in();
    
  switch(comando){
    case 1:
      adicionaProduto();
      break;
    case 0:
      limpar_tela();
      return 0;
      break;
    default:
      printf("Comando não localizado! Tente novamente\n");
      return 0;
  }
}

//Função principal de busca de produto
int buscarProduto(){
  limpar_tela();
  int comando;
  
  printf("BUSCA POR PRODUTO\n\n");
  printf("[1] - Buscar por código\n");
  printf("[2] - Buscar por descrição\n");
  printf("\n");
  printf("Digite o comando: ");
  scanf("%d", &comando);

  switch(comando){
    case 1:
      buscarProdutoCodigo();
      break;
    case 2:
       buscarProdutoDescricao();
      break;
    default:
      printf("Não foi possível identificar! Tente novamente\n");
      return 0;
  }
}

//Função de busca por código
int buscarProdutoCodigo(){
  int codigo;
  int comando;
  int pos;
  elemento resultado;

  limpar_tela();
  printf("BUSCA POR CÓDIGO DO PRODUTO\n\n");
  printf("Digite o código do produto: ");
  scanf("%d", &codigo);
  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c, &produto)){
      if(produto.codigo == codigo){
         resultado = produto;
         pos = c;
      }
    }
  }

  buscar_elemento(&lista_produtos, pos, &produto);

  if(resultado.codigo == produto.codigo){
    printf("Resultado da busca:\n");
    printf("Código: %d\n", resultado.codigo);
    printf("Descrição: %s\n\n", resultado.descricao);
  } else{
    printf("Produto não localizado! Tente novamente\n");
  }

  printf("Buscar mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      buscarProduto();
      break;
    default:
      printf("Comando não localizado! Tente novamente\n");
      return 0;
      break;
  }
}

//Função busca por descrição
int buscarProdutoDescricao(){
  char descricao[100];
  int comando;
  int pos;
  elemento resultado;

  limpar_tela();
  printf("BUSCA POR DESCRIÇÃO DO PRODUTO\n\n");
  printf("Digite a descrição do produto: ");
  flush_in();
  scanf("%[^\n]s", descricao);
  flush_in();

  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c, &produto)){
      if(strcmp(produto.descricao, descricao) == 0){
         resultado = produto;
         pos = c;
      }
    }
  }

  buscar_elemento(&lista_produtos, pos, &produto);
  if(strcmp(resultado.descricao, produto.descricao) == 0){
    printf("Resultado da busca:\n");
    printf("Código: %d\n", resultado.codigo);
    printf("Descrição: %s\n\n", resultado.descricao);
  } else{
    printf("Produto não localizado! Tente novamente\n");
  }

  printf("Buscar mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      buscarProduto();
      break;
    default:
      printf("Comando não localizado! Tente novamente");
      return 0;
      break;
  }
}

//Função principal de alteração de produto
int alterarProduto(){
  limpar_tela();
  int comando;
  
  printf("ALTERAÇÃO DE PRODUTO\n\n");
  printf("[1] - Alterar código\n");
  printf("[2] - Alterar descrição\n");
  printf("\n");
  printf("Digite o comando: ");
  scanf("%d", &comando);

  switch(comando){
    case 1:
      alterarProdutoCodigo();
      break;
    case 2:
      alterarProdutoDescricao();
      break;
    default:
      printf("Não foi possível identificar! Tente novamente\n");
      return 0;
  }
}

//Função de alteração do código do produto
int alterarProdutoCodigo(){
  int codigo;
  int comando;
  int novo_codigo;
  int pos_busca;
  int pos;
  elemento resultado;

  limpar_tela();
  printf("ALTERAÇÃO DO CÓDIGO DO PRODUTO\n\n");
  printf("Digite o codigo do produto: ");
  scanf("%d", &codigo);

  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c, &produto)){
      if(produto.codigo == codigo){
         resultado = produto;
         pos = c;
      }
    }
  }

  if(resultado.codigo == codigo){
    printf("Digite o novo código do produto a ser alterado: ");
    scanf("%d", &novo_codigo);

    for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
      if(buscar_elemento(&lista_produtos, c, &produto)){
        if(produto.codigo == novo_codigo){
          resultado = produto;
          pos_busca = c;
        }
      }
    }

    buscar_elemento(&lista_produtos, pos_busca, &produto);

    if(produto.codigo == novo_codigo){
      printf("Não é possível adicionar código já existente na lista\n");
    } else{
      buscar_elemento(&lista_produtos, pos, &produto);
      resultado.codigo = novo_codigo;
      printf("Dados a ser gravados\n");
      printf("Código: %d\n", resultado.codigo);
      printf("Descrição: %s\n\n", resultado.descricao);
      if(alterar_elemento(&lista_produtos, pos, resultado)){
        printf("Alteração realizada! \n");
      }
    }

  } else{
    printf("Código não encontrado! Tente novamente\n");
  }

  printf("Alterar mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      buscarProduto();
      break;
    default:
      printf("Comando não localizado! Tente novamente\n");
      return 0;
      break;
  }
}

//Função de alteração da descrição
int alterarProdutoDescricao(){
  int codigo;
  int comando;
  char nova_descricao[100];
  int pos;
  elemento resultado;

  limpar_tela();
  printf("ALTERAÇÃO DE DESCRIÇÃO DO PRODUTO\n\n");
  printf("Digite o codigo do produto: ");
  scanf("%d", &codigo);
  flush_in();

  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c, &produto)){
      if(produto.codigo == codigo){
         resultado = produto;
         pos = c;
      }
    }
  }

  if(resultado.codigo == codigo){
    printf("Digite a nova descrição do produto a ser alterado: ");
    scanf("%[^\n]s", nova_descricao);
    flush_in();
    buscar_elemento(&lista_produtos, pos, &produto);
    strcpy(produto.descricao, nova_descricao);
    printf("Dados a ser gravados\n");
    printf("Código: %d\n", produto.codigo);
    printf("Descrição: %s\n\n", produto.descricao);
    if(alterar_elemento(&lista_produtos, pos, produto)){
      printf("Alteração realizada! \n");
    }
  }  else{
    printf("Código não encontrado! Tente novamente\n");
  }

  printf("Alterar mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      buscarProduto();
      break;
    default:
      printf("Comando não localizado! Tente novamente");
      return 0;
      break;
  }
}

//Função principal de remoção de produto
int removerProduto(){
  int pos;
  int codigo;
  int comando;
  int confirmacaoExclusao;
  elemento resultado;

  limpar_tela();

  printf("REMOÇÃO DE PRODUTO\n\n");
  printf("Digite o código do produto: ");
  scanf("%d", &codigo);

  for(int c = 1; c <= tamanho_lista(&lista_produtos); c ++){
      if(buscar_elemento(&lista_produtos, c, &produto)){
        if(produto.codigo == codigo){
          resultado = produto;
          pos = c;
        }
      }
    }

  if(resultado.codigo == codigo){
    printf("Deseja remover o produto? ([0] - Não, [1] - Sim) ");
    scanf("%d", &confirmacaoExclusao);

    switch(confirmacaoExclusao){
      case 0:
        printf("Produto não excluido!\n");
        break;
      case 1:
        remove_elemento(&lista_produtos, pos);
        printf("Produto excluído!\n");
        break;
      default:
        printf("Comando não localizado! Tente novamente\n");
        break;
    }
  } else{
    printf("Produto não localizado. Tente novamente!\n");
  }

  printf("Excluir mais um produto? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      removerProduto();
      break;
    default:
      printf("Comando não localizado! Tente novamente\n");
      return 0;
      break;
  }
}

//Função de exibição de relatório
int relatorio(){
  int comando;

  limpar_tela();
  printf("RELATÓRIOS\n\n");

  printf("Quantidade de produtos cadastrados: %d\n", tamanho_lista(&lista_produtos));

  printf("---------------------------\n\n");
  for(int c = 0; c <tamanho_lista(&lista_produtos); c ++){
    if(buscar_elemento(&lista_produtos, c + 1, &produto)){
      printf("Código: %d\n", produto.codigo);
      printf("Descrição: %s\n", produto.descricao);
      printf("\n");
    }
  }

  printf("Continuar? [1] - Sim, [0] - Não: ");
  scanf("%d", &comando);

  switch(comando){
    case 0:
      limpar_tela();
      terminal();
      break;
    case 1:
      relatorio();
      break;
    default:
      printf("Comando não localizado! Tente novamente\n");
      return 0;
      break;
  }
}

//Função de exibição de terminal do usuário
int terminal(){
  cria_lista(&lista_produtos);
    while(1){
    int comando;
    if(comando == 9){
      break;
    }
    printf("======== GESTÃO DE RODUTOS =========");
    printf("\nVersão 1.0.1\n");
    printf("Feito por: Fredson Chaves\n\n");
    printf("\n\n\n");
    printf("[1] - Adicionar produto\n");
    printf("[2] - Buscar produto\n");
    printf("[3] - Alterar produto\n");
    printf("[4] - Remover produto\n");
    printf("[5] - Relatórios\n");
    printf("[9] - Sair");
    printf("\n");
    printf("Digite a opção: ");
    fflush(stdin);
    scanf("%d", &comando);

    switch(comando){
      case 1:
        fflush(stdin);
        adicionaProduto();
        break;
      case 2:
        buscarProduto();
        break;
      case 3:
        alterarProduto();
        break;
      case 4:
        removerProduto();
        break;
      case 5:
        relatorio();
        break;
      case 9:
        printf("Saindo do programa\n");
        comando = 9;
        return 0;
      default:
        printf("Não foi possível identificar o comando\n");
        break;
    }
    if(comando == 9){
      break;
    }
  }
}

//Função principal que chama outras funções
int main(){
  terminal();
}
