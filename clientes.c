#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#define maximoModalidade 5

void CadastrarCliente(Cliente *aluno, int *alunosCadastrados)
{
   int tempCod, sucesso = 0, falha = 0, tempIndex;
   int maximoVetor;

   maximoVetor = *alunosCadastrados;

   printf("---------------------------\n");
   printf("    Cadastro de Cliente");
   printf("\n---------------------------\n\n");

   do
   {
      tempIndex = PesquisarIndiceVazio(aluno);
      if (aluno[tempIndex].codigo == 0)
      {
         printf("Codigo do Aluno: ");
         scanf("%d", &tempCod);
         getchar();
         if (tempCod == 0)
         {
            printf("codigo inserido invalido, insira outro codigo\n");
         }
         else
         {
            if (ExisteCodigo(aluno, tempCod, maximoVetor) == 1)
            {
               printf("codigo ja cadastrado!");
               falha = 1;
            }
            else
            {
               {
                  aluno[tempIndex].codigo = tempCod;
                  int qntModalidades = 1;

                  do
                  {
                     printf("\nEm quantas modalidades voce deseja se cadastrar?: ");
                     scanf("%d", &qntModalidades);
                     if (qntModalidades < 0)
                        printf("insira um valor valido\n");
                  } while (qntModalidades < 0 || qntModalidades > maximoModalidade);

                  aluno[tempIndex].modalidade = (int *)malloc(qntModalidades * sizeof(int));
                  aluno[tempIndex].qntModalidades = qntModalidades;

                  int modTemp;
                  for (int i = 1; i <= qntModalidades; i++)
                  {
                     printf("\ncodigo da modalidade %d: ", i);
                     modTemp = i - 1;
                     scanf("%d", &aluno[tempIndex].modalidade[modTemp]);
                     getchar();
                  }
                  printf("Nome:");
                  fgets(aluno[tempIndex].nome, 255, stdin);
                  printf("Idade:");
                  scanf("%d", &aluno[tempIndex].idade);
                  getchar();
                  printf("Endereco:");
                  fgets(aluno[tempIndex].endereco, 255, stdin);
                  printf("Local de nascimento:");
                  fgets(aluno[tempIndex].localDeNascimento, 255, stdin);

                  printf("Valor da mensalidade:");
                  scanf("%d", &aluno[tempIndex].valorMensalidade);
                  getchar();
                  CalcularMensalidade(&aluno[tempIndex], &qntModalidades);

                  printf("Vencimento do Boleto:\n");
                  fgets(aluno[tempIndex].dataVencimentoBoleto, 11, stdin);

                  if (aluno[tempIndex].idade < 18)
                  {
                     printf("---------------------------\n");
                     printf("Dados do responsavel");
                     printf("\n---------------------------\n");
                     printf("Nome:");
                     fgets(aluno[tempIndex].nomeResponsavel, 255, stdin);
                     printf("RG:");
                     fgets(aluno[tempIndex].RG, 16, stdin);
                     printf("CPF:");
                     fgets(aluno[tempIndex].CPF, 12, stdin);
                     printf("---------------------------\n");
                     system("cls");

                     aluno[tempIndex].responsavel = 1;
                  }

                  else
                  {
                     printf("RG:\n");
                     fgets(aluno[tempIndex].RG, 16, stdin);
                     printf("CPF:\n");
                     fgets(aluno[tempIndex].CPF, 12, stdin);
                     printf("---------------------------\n");

                     aluno[tempIndex].responsavel = 0;
                  }

                  system("cls");
                  (*alunosCadastrados)++;
                  LimparEspacoVazio(&aluno[tempIndex]);
                  sucesso = 1;
               }
            }
         }
      }
      else
      {
         sucesso = 0;
      }

      if (sucesso == 1 || falha == 1)
         break;
   } while (sucesso == 0 || falha == 0);
}

void TelaAlterar(Cliente *aluno)
{
   system("cls");
   printf("\n---------------------------\n");
   printf("Alteracao dos dados do Cliente");
   printf("\n---------------------------\n");
   printf("Voce esta alterando o aluno: %s", aluno->nome);
   printf("\n---------------------------\n\n");
}

int MenuAlterarCliente()
{
   int opcao;
   printf("Qual dado voce deseja alterar?\n");
   printf("1)Nome");
   printf("\n2)Modalidades");
   printf("\n3)Idade");
   printf("\n4)Local de nascimento");
   printf("\n5)Valor da mensalidade");
   printf("\n6)Vencimento do Boleto");
   printf("\n7)Nome do responsavel");
   printf("\n8)RG");
   printf("\n9)CPF");
   printf("\n10)Endereco\n");
   scanf("%d", &opcao);
   getchar();
   return opcao;
}

void AlterarCliente(Cliente *aluno, int *codigo, int *alunosCadastrados)
{
   int qntModalidades = 1, search = 0;
   int indexAlterar = PesquisarCodigo(aluno, *codigo, *alunosCadastrados);

   if (indexAlterar >= 0)
   {
      TelaAlterar(&aluno[indexAlterar]);
      switch (MenuAlterarCliente())
      {
      case 1:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("Nome:");
         fgets(aluno[indexAlterar].nome, 255, stdin);
         for (search = 0; aluno[indexAlterar].nome[search] != '\n'; search++)
            ;
         aluno[indexAlterar].nome[search] = '\0';
         break;
      }

      case 2:
      {
         TelaAlterar(&aluno[indexAlterar]);
         free(aluno[indexAlterar].modalidade);
         do
         {
            printf("\nEm quantas modalidades voce deseja se cadastrar?: ");
            scanf("%d", &qntModalidades);
            getchar();
            if (qntModalidades < 0 || qntModalidades > maximoModalidade)
               printf("insira um valor valido\n");
         } while (qntModalidades < 0 || qntModalidades > maximoModalidade);

         aluno[indexAlterar].modalidade = (int *)malloc(qntModalidades * sizeof(int));
         aluno[indexAlterar].qntModalidades = qntModalidades;
         int modTemp;
         for (int i = 1; i <= qntModalidades; i++)
         {
            printf("\ncodigo da modalidade%d: ", i);
            modTemp = i - 1;
            scanf("%d", aluno[indexAlterar].modalidade[modTemp]);
            getchar();
         }

         CalcularMensalidade(&aluno[indexAlterar], &qntModalidades);
         break;
      }

      case 3:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("\nIdade: ");
         scanf("%d", &aluno[indexAlterar].idade);
         getchar();
         if (aluno[indexAlterar].idade < 18)
            aluno[indexAlterar].responsavel = 1;
         else
            aluno[indexAlterar].responsavel = 0;
         break;
      }

      case 4:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("Local de nascimento: ");
         fgets(aluno[indexAlterar].localDeNascimento, 255, stdin);
         for (search = 0; aluno[indexAlterar].localDeNascimento[search] != '\n'; search++)
            ;
         aluno[indexAlterar].localDeNascimento[search] = '\0';
         break;
      }

      case 5:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("Valor da mensalidade:");
         scanf("%d", &aluno[indexAlterar].valorMensalidade);
         getchar();
         CalcularMensalidade(&aluno[indexAlterar], &aluno[indexAlterar].qntModalidades);
         break;
      }

      case 6:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("\nVencimento do Boleto: ");
         fgets(aluno[indexAlterar].dataVencimentoBoleto, 11, stdin);
         for (search = 0; aluno[indexAlterar].dataVencimentoBoleto[search] != '\n'; search++)
            ;
         aluno[indexAlterar].dataVencimentoBoleto[search] = '\0';
         break;
      }

      case 7:
      {
         TelaAlterar(&aluno[indexAlterar]);
         if (aluno[indexAlterar].responsavel == 1)
         {
            printf("Nome do responsavel: ");
            fgets(aluno[indexAlterar].nomeResponsavel, 255, stdin);
            for (search = 0; aluno[indexAlterar].nomeResponsavel[search] != '\n'; search++)
               ;
            aluno[indexAlterar].nomeResponsavel[search] = '\0';
         }
         else
         {
            printf("O aluno precisa ter um responsavel para alterar o nome!\n");
         }
         break;
      }

      case 8:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("\nRG: ");
         fgets(aluno[indexAlterar].RG, 16, stdin);
         for (search = 0; aluno[indexAlterar].RG[search] != '\n'; search++)
            ;
         aluno[indexAlterar].RG[search] = '\0';
         break;
      }
      case 9:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("\nCPF: ");
         fgets(aluno[indexAlterar].CPF, 12, stdin);
         for (search = 0; aluno[indexAlterar].CPF[search] != '\n'; search++)
            ;
         aluno[indexAlterar].CPF[search] = '\0';
         break;
      }

      case 10:
      {
         TelaAlterar(&aluno[indexAlterar]);
         printf("\nEndereco: ");
         fgets(aluno[indexAlterar].endereco, 255, stdin);
         for (search = 0; aluno[indexAlterar].endereco[search] != '\n'; search++)
            ;
         aluno[indexAlterar].endereco[search] = '\0';
         break;
      }

      default:
      {
         printf("Opcao invalida");
         break;
      }
      }
      printf("\nAlteracao feita com sucesso\n");
      system("pause");
      system("cls");
   }
   else
   {
      system("pause");
   }
}

void ExcluirCliente(Cliente *aluno, int *codigo, int *alunosCadastrados, int *excluidos)
{
   char op;
   int index = PesquisarCodigo(aluno, *codigo, *alunosCadastrados);
   if (index >= 0)
   {
      printf("Exclusao do Cliente");
      printf("\n---------------------------\n");
      printf("Voce esta prestes a excluir o aluno: %s\t de codigo: %d", aluno[index].nome, aluno[index].codigo);
      printf("\n---------------------------\n\n");
      printf("Voce tem certeza que deseja excluir?s/n:");
      printf("\n---------------------------\n");
      getchar();
		scanf("%c", &op);
		getchar();
		
      if (op == 'S' || op == 's')
      {
         aluno[index].codigo = 0;
         free(aluno[index].modalidade);
         (*alunosCadastrados)--;
         (*excluidos)++;
         printf("\nExclusao feita com sucesso\n");
         system("pause");
         system("cls");

         if (*excluidos % 5 == 0 && *excluidos != 0)
         {
            aluno = (Cliente *)realloc(aluno, (*alunosCadastrados) * sizeof(Cliente));
         }
      }
   }
}

void ConsultarCliente(Cliente *aluno, int *codigo, int *alunosCadastrados)
{
   int index = PesquisarCodigo(aluno, *codigo, *alunosCadastrados);
   printf("%d\n", index);
   if (index >= 0)
   {

      system("cls");
      printf("\n---------------------------\n");
      printf("Consulta de Cliente");
      printf("\n---------------------------\n\n");
      printf("Nome: %s\t\t", aluno[index].nome);
      printf("\t\tCodigo do Aluno: %d", *codigo);
      printf("\nModalidades: \n");
      for (int i = 0; i < aluno[index].qntModalidades; i++)
      {
         printf("Modalidade %d)%d\n", i + 1, aluno[index].modalidade[i]);
      }
      printf("\nIdade: %d\t\t", aluno[index].idade);
      printf("Local de nascimento: %s", aluno[index].localDeNascimento);
      printf("\nValor da mensalidade: R$%d", aluno[index].valorMensalidade);
      printf("\nVencimento do Boleto: %s", aluno[index].dataVencimentoBoleto);
      printf("\n---------------------------\n");

      if (aluno[index].responsavel == 1)
      {
         printf("Dados do responsavel");
         printf("\n---------------------------\n");
         printf("Nome: %s", aluno[index].nomeResponsavel);
      }

      printf("\nRG: %s", aluno[index].RG);
      printf("\nCPF: %s", aluno[index].CPF);
      printf("\nEndereco: %s", aluno[index].endereco);
      printf("\n---------------------------\n");
      system("pause");
      system("cls");
   }
}

void CalcularMensalidade(Cliente *aluno, int *quantidadeDeModalidades)
{
   if (*quantidadeDeModalidades >= 2)
   {
      aluno->valorMensalidade -= (0.05 * aluno->valorMensalidade);
   }
}

void LimparEspacoVazio(Cliente *aluno)
{
   int search;
   for (search = 0; aluno->nome[search] != '\n'; search++)
      ;
   aluno->nome[search] = '\0';

   for (search = 0; aluno->localDeNascimento[search] != '\n'; search++)
      ;
   aluno->localDeNascimento[search] = '\0';

   for (search = 0; aluno->RG[search] != '\n'; search++)
      ;
   aluno->RG[search] = '\0';

   for (search = 0; aluno->CPF[search] != '\n'; search++)
      ;
   aluno->CPF[search] = '\0';

   for (search = 0; aluno->endereco[search] != '\n'; search++)
      ;
   aluno->endereco[search] = '\0';

   for (search = 0; aluno->dataVencimentoBoleto[search] != '\n'; search++)
      ;
   aluno->dataVencimentoBoleto[search] = '\0';

   if (aluno->responsavel == 1)
   {
      for (search = 0; aluno->nomeResponsavel[search] != '\n'; search++)
         ;
      aluno->nomeResponsavel[search] = '\0';
   }
}

int PesquisarCodigo(Cliente *aluno, int codigo, int MAX)
{

   int i, busca = 0;
   for (i = 0; i < MAX && !busca; i++)
      if (aluno[i].codigo == codigo)
      {
         busca = 1;
         return i;
      }
   printf("Cliente nao encontrado\n");
   system("pause");
   return -1;
}

int PesquisarIndiceVazio(Cliente *aluno)
{
   int i;
   for (i = 0; aluno[i].codigo != 0; i++)
      ;
   return i;
}

int ExisteCodigo(Cliente *aluno, int codigo, int MAX)
{

   int i, busca = 0;
   for (i = 0; i < MAX && !busca; i++)
      if (aluno[i].codigo == codigo)
      {
         printf("\nAluno ja cadastrado\n");
         busca = 1;
      }

   return busca;
}
