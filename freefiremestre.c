#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// STRUCTS
typedef struct
{
  char nome[30];
  char tipo[20];
  int prioridade;
} Componentes;

//VARIÁVEIS GLOBAIS 
#define MAX_COMP 20
Componentes torre[MAX_COMP];
int totalComp = 0;

// CONTADORES GLOBAIS
int comparacoes = 0;

//FUNÇÕES AUXILIARES

void mostrarcomponentes(Componentes arr[], int n)
{
  printf("\n=== Componentes ===\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d) Nome: %s | Tipo: %s | Prioridade: %d\n",
           i + 1, arr[i].nome, arr[i].tipo, arr[i].prioridade);
  }
}

// ORDENAÇÕES


void insertionsorttipo(Componentes arr[], int n)
{
  comparacoes = 0;
  for (int i = 1; i < n; i++)
  {
    Componentes chave = arr[i];
    int j = i - 1;
    while (j >= 0 && strcmp(arr[j].tipo, chave.tipo) > 0)
    {
      arr[j + 1] = arr[j];
      j--;
      comparacoes++;
    }
    arr[j + 1] = chave;
    comparacoes++;
  }
  printf("\nOrdenado por Tipo (Insertion Sort). Comparações: %d\n", comparacoes);
}

void bubblesortnome(Componentes arr[], int n)
{
  comparacoes = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      comparacoes++;
      if (strcmp(arr[j].nome, arr[j + 1].nome) > 0)
      {
        Componentes temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  printf("\nOrdenado por Nome (Bubble Sort). Comparações: %d\n", comparacoes);
}


void selectionsortprioridade(Componentes arr[], int n)
{
  comparacoes = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      comparacoes++;
      if (arr[j].prioridade < arr[min].prioridade)
      {
        min = j;
      }
    }
    if (min != i)
    {
      Componentes temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  printf("\nOrdenado por Prioridade (Selection Sort). Comparações: %d\n", comparacoes);
}

//BUSCA BINÁRIA 
void buscabinariapornome(Componentes arr[], int n, char chave[])
{
  int inicio = 0, fim = n - 1, meio;
  comparacoes = 0;

  while (inicio <= fim)
  {
    meio = (inicio + fim) / 2;
    comparacoes++;
    int cmp = strcmp(chave, arr[meio].nome);
    if (cmp == 0)
    {
      printf("Componente encontrado! Nome: %s | Tipo: %s | Prioridade: %d\n",
             arr[meio].nome, arr[meio].tipo, arr[meio].prioridade);
      printf("Comparações (busca binária): %d\n", comparacoes);
      return;
    }
    else if (cmp < 0)
    {
      fim = meio - 1;
    }
    else
    {
      inicio = meio + 1;
    }
  }

  printf("Componente não encontrado. Comparações: %d\n", comparacoes);
}

//FUNÇÕES DE CADASTRO 

void adicionarcomponente()
{
  if (totalComp >= MAX_COMP)
  {
    printf("\nLimite de componentes atingido!\n");
    return;
  }

  printf("\nNome: ");
  getchar(); // limpar buffer
  fgets(torre[totalComp].nome, 30, stdin);
  torre[totalComp].nome[strcspn(torre[totalComp].nome, "\n")] = 0;

  printf("Tipo: ");
  fgets(torre[totalComp].tipo, 20, stdin);
  torre[totalComp].tipo[strcspn(torre[totalComp].tipo, "\n")] = 0;

  printf("Prioridade (1 a 10): ");
  scanf("%d", &torre[totalComp].prioridade);

  totalComp++;
  printf("Componente adicionado!!!!!!!!\n");
}

// MENU PRINCIPAL/FUNÇÃO MAIN
int main()
{
  int opcao;
  char chave[30];
  clock_t inicio, fim;

  do
  {
    printf("\nTorre de Fuga\n");
    printf("1. Adicionar componente\n");
    printf("2. Mostrar componentes\n");
    printf("3. Ordenar por Nome(Bubble Sort)\n");
    printf("4. Ordenar por Tipo(Insertion Sort)\n");
    printf("5. Ordenar por Prioridade(Selection Sort)\n");
    printf("6. Buscar Componente(Binaria por Nome)\n");
    printf("0. Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      adicionarcomponente();
      break;
    case 2:
      mostrarcomponentes(torre, totalComp);
      break;
    case 3:
      inicio = clock();
      bubblesortnome(torre, totalComp);
      fim = clock();
      printf("Tempo: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
      mostrarcomponentes(torre, totalComp);
      break;
    case 4:
      inicio = clock();
      insertionsortTipo(torre, totalComp);
      fim = clock();
      printf("Tempo: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
      mostrarcomponentes(torre, totalComp);
      break;
    case 5:
      inicio = clock();
      selectionsortprioridade(torre, totalComp);
      fim = clock();
      printf("Tempo: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
      mostrarcomponentes(torre, totalComp);
      break;
    case 6:
      printf("\nDigite o nome do componente-chave: ");
      getchar(); // limpar buffer
      fgets(chave, 30, stdin);
      chave[strcspn(chave, "\n")] = 0;
      buscabinariapornome(torre, totalComp, chave);
      break;
    }
  } while (opcao != 0);

  printf("\nSaindo... Torre montada ou missão falhou!\n");
  return 0;
}
