#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct
{
  char nome[50];
  char tipo[50];
  int quantidade;
} Item;


typedef struct No
{
  Item dados;
  struct No *proximo;
} No;


Item mochilaVetor[MAX_ITENS];
int totalvetor = 0;      
No *mochilaLista = NULL; 


int comparacaoseqvetor = 0;
int comparacaoseqlista = 0;


void inseriritemvetor()
{
  if (totalvetor >= MAX_ITENS)
  {
    printf("\nMochila (vetor) cheia! Não é possível adicionar mais itens.\n");
    return;
  }
  Item novo;
  printf("\n== Inserir no Vetor ==\n");
  printf("Nome: ");
  scanf(" %29s", novo.nome); 
  printf("Tipo: ");
  scanf(" %19s", novo.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo.quantidade);

  mochilaVetor[totalvetor++] = novo;
  printf("Item adicionado ao vetor!\n");
}

// Remove um item do vetor pelo nome 
void removeritemvetor()
{
  if (totalvetor == 0)
  {
    printf("\nMochila (vetor) vazia! Nada para remover.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a remover: ");
  scanf(" %29s", nome);

  int encontrado = -1;
  for (int i = 0; i < totalvetor; i++)
  {
    if (strcmp(mochilaVetor[i].nome, nome) == 0)
    {
      encontrado = i;
      break;
    }
  }
  if (encontrado == -1)
  {
    printf("Item não encontrado no vetor.\n");
    return;
  }
  // desloca para a esquerda
  for (int i = encontrado; i < totalvetor - 1; i++)
  {
    mochilaVetor[i] = mochilaVetor[i + 1];
  }
  totalvetor--;
  printf("Item removido do vetor com sucesso!\n");
}

// Lista todos os itens do vetor
void listaritensvetor()
{
  if (totalvetor == 0)
  {
    printf("\nMochila (vetor) vazia.\n");
    return;
  }
  printf("\n=== Itens na Mochila (Vetor) ===\n");
  for (int i = 0; i < totalvetor; i++)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i + 1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
  }
}


void buscarSequencialVetor()
{
  if (totalvetor == 0)
  {
    printf("\nMochila (vetor) vazia. Nada para buscar.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a buscar (sequencial no vetor): ");
  scanf(" %29s", nome);

  comparacaoseqvetor = 0;
  for (int i = 0; i < totalvetor; i++)
  {
    comparacaoseqvetor++;
    if (strcmp(mochilaVetor[i].nome, nome) == 0)
    {
      printf("Item encontrado no vetor! Nome: %s | Tipo: %s | Quantidade: %d\n",
             mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
      printf("Comparações (sequencial - vetor): %d\n", comparacaoseqvetor);
      return;
    }
  }
  printf("Item não encontrado no vetor.\n");
  printf("Comparações (sequencial - vetor): %d\n", comparacaoseqvetor);
}

void ordenarVetor()
{
  if (totalvetor <= 1)
  {
    printf("\nNada a ordenar (0 ou 1 item).\n");
    return;
  }
  for (int i = 0; i < totalvetor - 1; i++)
  {
    for (int j = 0; j < totalvetor - i - 1; j++)
    {
      if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0)
      {
        Item tmp = mochilaVetor[j];
        mochilaVetor[j] = mochilaVetor[j + 1];
        mochilaVetor[j + 1] = tmp;
      }
    }
  }
  printf("\nVetor ordenado por nome (Bubble Sort).\n");
}

void inserirItemLista()
{
  No *novo = (No *)malloc(sizeof(No));
  if (!novo)
  {
    printf("Erro de alocação de memória.\n");
    return;
  }
  printf("\n== Inserir na Lista ==\n");
  printf("Nome: ");
  scanf(" %29s", novo->dados.nome);
  printf("Tipo: ");
  scanf(" %19s", novo->dados.tipo);
  printf("Quantidade: ");
  scanf("%d", &novo->dados.quantidade);

  novo->proximo = mochilaLista;
  mochilaLista = novo;
  printf("Item adicionado à lista encadeada!\n");
}

void removerItemLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila vazia (lista)! Nada para remover.\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a remover da lista: ");
  scanf(" %29s", nome);

  No *atual = mochilaLista;
  No *anterior = NULL;

  while (atual != NULL && strcmp(atual->dados.nome, nome) != 0)
  {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    printf("Item não encontrado na lista.\n");
    return;
  }

  if (anterior == NULL)
  {
    // removendo o primeiro nó
    mochilaLista = atual->proximo;
  }
  else
  {
    anterior->proximo = atual->proximo;
  }
  free(atual);
  printf("Item removido da lista com sucesso!\n");
}

// Lista todos os itens na lista encadeada
void listarItensLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila vazia(lista).\n");
    return;
  }
  printf("\n=== Itens na Mochila (Lista Encadeada) ===\n");
  No *atual = mochilaLista;
  int i = 1;
  while (atual != NULL)
  {
    printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
           i, atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
    atual = atual->proximo;
    i++;
  }
}

// Busca sequencial na lista encadeada (conta comparações)
void buscarItemLista()
{
  if (mochilaLista == NULL)
  {
    printf("\nMochila vazia (lista).\n");
    return;
  }
  char nome[30];
  printf("\nNome do item a buscar (sequencial na lista): ");
  scanf(" %29s", nome);

  comparacaoseqlista = 0;
  No *atual = mochilaLista;
  while (atual != NULL)
  {
    comparacaoseqlista++;
    if (strcmp(atual->dados.nome, nome) == 0)
    {
      printf("Item encontrado na lista! Nome: %s | Tipo: %s | Quantidade: %d\n",
             atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
      printf("Comparações (sequencial - lista): %d\n", comparacaoseqlista);
      return;
    }
    atual = atual->proximo;
  }
  printf("Item não encontrado na lista.\n");
  printf("Comparações (sequencial - lista): %d\n", comparacaoseqlista);
}


void liberarLista()
{
  No *atual = mochilaLista;
  while (atual != NULL)
  {
    No *prox = atual->proximo;
    free(atual);
    atual = prox;
  }
  mochilaLista = NULL;
}
//FUNÇÃO MAIN

int main()
{
  int estrutura = -1;
  int opcao = -1;

  do
  {
    printf("\n------Sistema de Inventário--------\n");
    printf("Escolha a estrutura para operar:\n");
    printf("1 - Vetor (lista sequencial)\n");
    printf("2 - Lista encadeada\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &estrutura);

    if (estrutura == 1)
    {
      do
      {
        printf("\n--- Menu Vetor ---\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar (sequencial)\n");
        printf("5 - Ordenar vetor (por nome)\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
          inseriritemvetor();
          break;
        case 2:
          removeritemvetor();
          break;
        case 3:
          listaritensvetor();
          break;
        case 4:
          buscarSequencialVetor();
          break;
        case 5:
          ordenarVetor();
          break;
        case 0:
          break;
        default:
          printf("Opção inválida.\n");
        }
      } while (opcao != 0);
    }
    else if (estrutura == 2)
    {
      do
      {
        printf("\nMenu: Lista Encadeada\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar (sequencial)\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
          inserirItemLista();
          break;
        case 2:
          removerItemLista();
          break;
        case 3:
          listarItensLista();
          break;
        case 4:
          buscarItemLista();
          break;
        case 0:
          break;
        default:
          printf("Opção inválida.\n");
        }
      } while (opcao != 0);
    }
    else if (estrutura != 0)
    {
      printf("Escolha inválida. Digite 1, 2, 0.\n");
    }

  } while (estrutura != 0);

  // libera memória 
  liberarLista();
  printf("\nEncerrando.\n");
  return 0;
}
