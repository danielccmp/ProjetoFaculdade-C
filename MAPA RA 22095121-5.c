/*Elaborado por Daniel Augusto Coração de Campos RA 22095121-5
Para a disciplina de Algoritmos e Lógica de Programação II,
graduação em Engenharia de Software, Unicesumar, 2022.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct vacina
{
   int cod;
   char nome[50];
   char CPF[15];
   char vacina[50];
   char data[11];
   int lote;
};

#define TAM 999

// Definindo variáveis globais para utilização em mais de uma função
struct vacina cadastro[TAM];
int cont;

// Função para cadastrar aplicações
void cadastrarVacina(int *i)
{
   cadastro[*i].cod = cont + 1; // Para registro mais amigável ao usuário, inicia-se a sequência em 1.
   printf("Informe o nome do paciente: ");
   fgets(cadastro[*i].nome, 50, stdin);
   fflush(stdin);
   printf("Informe o CPF do paciente, no formato XXX.XXX.XXX-XX: ");
   fgets(cadastro[*i].CPF, 15, stdin);
   fflush(stdin);
   printf("Informe o nome da vacina aplicada: ");
   fgets(cadastro[*i].vacina, 50, stdin);
   fflush(stdin);
   printf("Informe a data de aplicação da vacina, no formato XX/XX/XXXX: ");
   fgets(cadastro[*i].data, 11, stdin);
   fflush(stdin);
   printf("Informe o lote da vacina aplicada: ");
   scanf("%d", &cadastro[*i].lote);
   fflush(stdin);
   system("pause");
   system("cls");
   *i = *i + 1;
}

// Função para impressão dos registros
void imprimirRelatorio()
{
   int i;

   printf("======================================== \n");
   printf("    Relatório de Vacinas Aplicadas \n");
   printf("======================================== \n");
   printf("\n");
   for (i = 0; i < cont; i++)
   {
      printf("\nCódigo: %d \n", cadastro[i].cod);
      printf("\nNome: %s ", cadastro[i].nome);
      printf("\nCPF: %s ", cadastro[i].CPF);
      printf("\nVacina: %s ", cadastro[i].vacina);
      printf("\nData de aplicação: %s ", cadastro[i].data);
      printf("\nNúmero do Lote: %d\n", cadastro[i].lote);
      printf("\n======================================== \n");
   }
   system("pause");
   system("cls");
}

// Função para pesquisar CPF
void buscaCPF()
{
   char busca[15];
   int i, acha;
   i = 0;
   acha = 0;

   printf("Digite o CPF no formato 111.111.111-11 que deseja buscar: ");
   fgets(busca, 15, stdin);
   fflush(stdin);
   system("cls");

   while ((i < cont) && (acha == 0))
   {
      if (strcmp(cadastro[i].CPF, busca) == 0)
         acha = 1;
      else
         i++;
   }

   if (acha == 1)
   {
      printf("======================================== \n");
      printf("          Registro localizado: \n");
      printf("======================================== \n");
      printf("\nCódigo: %d \n", cadastro[i].cod);
      printf("\nNome: %s ", cadastro[i].nome);
      printf("\nCPF: %s ", cadastro[i].CPF);
      printf("\nVacina: %s ", cadastro[i].vacina);
      printf("\nData de aplicação: %s ", cadastro[i].data);
      printf("\nNúmero do Lote: %d\n", cadastro[i].lote);
      printf("\n======================================== \n");
   }
   else
   {
      printf("\nCPF não encontrado.\n\n");
   }
   system("pause");
   system("cls");
}

int main()
{
   setlocale(LC_ALL, "Portuguese");

   int op, i;
   op = 0;
   i = 0;
   cont = 0;

   // Cabeçalho do programa
   system("cls");
   printf("======================================== \n");
   printf("Bem-vindo ao programa Gestão de Vacinas! \n");
   printf("======================================== \n");
   printf("\n");

   while (op != 4)
   {
      printf("Digite a opção Desejada: \n");
      printf("\n 1 - Cadastrar aplicação de vacina; \n");
      printf("\n 2 - Apresentar o relatório geral de aplicações; \n");
      printf("\n 3 - Buscar aplicação por CPF; \n");
      printf("\n 4 - Sair do programa. \n\n");
      scanf("%d", &op);
      fflush(stdin);
      // Condição para garantir entrada válida de opção
      if ((op <= 0) || (op > 4))
      {
         do
         {
            printf("Opção inválida, digite novamente: ");
            scanf("%d", &op);
            fflush(stdin);
         } while ((op <= 0) || (op > 4));
      }
      system("cls");

      // Seleção de opções
      if (op == 1)
      {
         cadastrarVacina(&i);
         cont = cont + 1;
      }

      if (op == 2)
      {
         imprimirRelatorio();
      }

      if (op == 3)
      {
         buscaCPF();
      }
   }
   return 0;
}
