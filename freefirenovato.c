#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct 
typedef struct
{
  char nome[50];
  char tipo[50];
  int quantidade;
} Itens;

// Capacidade máxima da mochila
#define MAX_ITENS 10

//ARMAZENAR ITENS
Item mochila[MAX_ITENS];
int totalitens = 0; // Quantos itens estão cadastrados 

// FUNÇÃO INSERIR ITENS 
void inseriritem()
{
  if (totalitens>= MAX_ITENS)
  {
    printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
    return;
  }

  Itens novo;
  printf("\n=== Cadastro de Item ===\n");
  printf("Nome do item: ");
  scanf("%s", novo.nome); 
  printf("Tipo do item (arma, municao, cura...): ");
  scanf("%s", novo.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo.quantidade);

  // Adiciona o item ao vetor
  mochila[totalitens] = novo;
  totalitens++;

  printf("\nItem cadastrado com sucesso!\n");
}

// Função para remover item da mochila pelo nome
void removeritem()
{
  if (totalitens == 0)
  {
    printf("\nA mochila está vazia. Nada a mover.\n");
    return;
  }

  char nomeRemover[30];
  printf("\nDigite o nome do item que deseja remover: ");
  scanf("%s", nomeRemover);

  int iteencontrado = -1;
  for (int i = 0; i < totalitens; i++)
  {
    if (strcmp(mochila[i].nome, nomeRemover) == 0)
    {
      encontrado = i;
      break;
    }
  }

  if (iteencontrado == -1)
  {
    printf("\nItem não encontrado na mochila.\n");
    return;
  }

  // "Puxa" os itens seguintes para frente 
  for (int i = iteencontrado; i < totalitens - 1; i++)
  {
    mochila[i] = mochila[i + 1];
  }
  totalitens--;

  printf("\nItem removido com sucesso!\n");
}

// FUNÇÃO PARA LISTAR ITENS
void listaritens()
{
  if (totalitens == 0)
  {
    printf("\nA mochila está vazia.\n");
    return;
  }

  printf("\n=== Itens na Mochila ===\n");
  for (int i = 0; i < totalitens; i++)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
  }
}

// FUNÇÃO PARA BUSCAR ITENS
void buscaritem()
{
  if (totalitens == 0)
  {
    printf("\nA mochila está vazia. Nada para buscar.\n");
    return;
  }

  char nomeBusca[30];
  printf("\nDigite o nome do item que deseja buscar: ");
  scanf("%s", nomeBusca);

  for (int i = 0; i < totalitens; i++)
  {
    if (strcmp(mochila[i].nome, nomeBusca) == 0)
    {
      printf("\nItem encontrado!\n");
      printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
             mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
      return;
    }
  }

  printf("\nItem não encontrado na mochila.\n");
}

// FUNÇÃO PRINCIPAL COM MENU
int main()
{
  int opcao;

  do
  {
    printf("\n=== INVENTARIO ===\n");
    printf("1. Inserir item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("4. Buscar item\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      inseriritem();
      listaritens();
      break;
    case 2:
      removeritem();
      listaritens();
      break;
    case 3:
      listaritens();
      break;
    case 4:
      buscaritem();
      break;
    case 0:
      printf("\n FECHANDO O JOGO!\n");
      break;
    default:
      printf("\nOpção inválida! Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}
