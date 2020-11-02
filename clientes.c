#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

void CadastrarCliente(Cliente *aluno, int *alunosCadastrados)
{
    int tempCod, sucesso = 0, tempIndex;
    int qntModalidades = 1;

    if (*alunosCadastrados % 5 == 0)
    {
        aluno = realloc(aluno, (*alunosCadastrados + 5) * sizeof(Cliente));
        for (int i = *alunosCadastrados; i < *alunosCadastrados + 5; i++)
        {
            aluno[i].codigo = 0;
        }
    }

    tempIndex = *alunosCadastrados;
    do
    {
        if (aluno[tempIndex].codigo == 0)
        {
            printf("---------------------------\n");
            printf("    Cadastro de Cliente");
            printf("\n---------------------------\n\n");
            printf("Codigo do Aluno: ");
            do
            {
                scanf("%d", &tempCod);
                getchar();

                if (tempCod != 0)
                {
                    aluno[tempIndex].codigo = tempCod;
                }
                else
                {
                    printf("\nCodigo inserido invalido!\nInsira um codigo valido: ");
                }
            } while (tempCod == 0);

                do
            {
                printf("\nEm quantas modalidades voce deseja se cadastrar?: ");
                scanf("%d", &qntModalidades);
                if (qntModalidades < 0)
                    printf("insira um valor valido\n");
            }
            while (qntModalidades < 0 || qntModalidades > 5)
                ;

            aluno[tempIndex].modalidade = (int *)malloc(qntModalidades * sizeof(int));
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
            printf("Idade: ");
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

            printf("\nVencimento do Boleto:");
            fgets(aluno[tempIndex].dataVencimentoBoleto, 11, stdin);
            if (aluno[tempIndex].idade < 18)
            {
                printf("---------------------------\n");
                printf("Dados do responsavel");
                printf("\n---------------------------\n");
                printf("Nome:\n");
                fgets(aluno[tempIndex].nomeResponsavel, 255, stdin);
                printf("RG:\n");
                fgets(aluno[tempIndex].RG, 16, stdin);
                printf("CPF:\n");
                fgets(aluno[tempIndex].CPF, 12, stdin);
                printf("---------------------------\n");
                system("cls");

                aluno[tempIndex].responsavel = 1;
            }

            else
            {
                printf("\nRG:\n");
                fgets(aluno[tempIndex].RG, 16, stdin);
                printf("\nCPF:\n");
                fgets(aluno[tempIndex].CPF, 12, stdin);
                printf("---------------------------\n");

                aluno[tempIndex].responsavel = 0;
            }
            system("cls");
            (*alunosCadastrados)++;
            LimparEspacoVazio(&aluno[tempIndex]);
            sucesso = 1;
        }
        else
        {
            tempIndex = PesquisarIndiceVazio(aluno);
            sucesso = 0;
        }

    } while (sucesso != 1);
}

void AlterarCliente(Cliente *aluno, int *codigo)
{
    int qntModalidades = 1;
    int indexAlterar = PesquisarCodigo(aluno,*codigo);
    free(aluno[indexAlterar].modalidade);

    printf("\n---------------------------\n");
    printf("Alteracao dos dados do Cliente");
    printf("\n---------------------------\n");
    printf("Voce esta alterando o aluno: %s", aluno[indexAlterar].nome);
    printf("\n---------------------------\n\n");
    printf("Nome: %s\t\t");
    fgets(aluno[indexAlterar].nome, 255, stdin);

    do
    {
        printf("\nEm quantas modalidades voce deseja se cadastrar?: ");
        scanf("%d", &qntModalidades);
        if (qntModalidades < 0)
            printf("insira um valor válido\n");
    } while (qntModalidades < 0 ||qntModalidades > 5);

    aluno[indexAlterar].modalidade = (int *)malloc(qntModalidades * sizeof(int));
	int modTemp;
    for (int i = 1; i <= qntModalidades; i++)
    {
        printf("\ncodigo da modalidade%d: ", i);
        modTemp = i - 1;
        scanf("%d", aluno[indexAlterar].modalidade[modTemp]);
        getchar();
    }
    printf("\nIdade: ");
    scanf("%d", &aluno[indexAlterar].idade);
    getchar();
    printf("Local de nascimento: ");
    fgets(aluno[indexAlterar].localDeNascimento, 255, stdin);
    printf("Valor da mensalidade:");
    scanf("%d", &aluno[indexAlterar].valorMensalidade);
    getchar();
    //CalcularMensalidade(aluno, indexAlterar, &qntModalidades);
    printf("\nVencimento do Boleto: ");
    fgets(aluno[indexAlterar].dataVencimentoBoleto, 10, stdin);
    printf("\n---------------------------\n");
    if (aluno[indexAlterar].responsavel == 1)
    {
        printf("Dados do responsavel");
        printf("\n---------------------------\n");
        printf("Nome: ");
        fgets(aluno[indexAlterar].nomeResponsavel, 255, stdin);
    }
    printf("\nRG: ");
    fgets(aluno[indexAlterar].RG, 15, stdin);
    printf("\nCPF: ");
    fgets(aluno[indexAlterar].CPF, 11, stdin);
    printf("\nEndereco: ");
    fgets(aluno[indexAlterar].endereco, 255, stdin);
    printf("\n---------------------------\n");
    LimparEspacoVazio(&aluno[indexAlterar]);
    system("cls");
}

void ExcluirCliente(Cliente *aluno, int *codigo, int *alunosCadastrados)
{
    char op;
    int index = PesquisarCodigo(aluno, *codigo);
    printf("Exclusao do Cliente");
    printf("\n---------------------------\n");
    printf("Voce esta prestes a excluir o aluno: %s\t de codigo: %d", aluno[index].nome, aluno[index].codigo);
    printf("\n---------------------------\n\n");
    printf("Voce tem certeza que deseja excluir?s/n\n");
    scanf("%c", &op);
    printf("\n---------------------------\n");

    if (op == 'S' || op == 's')
    {
        aluno[index].codigo = 0;
        (*alunosCadastrados)--;
        if (*alunosCadastrados % 5 != 0 && *alunosCadastrados + 5 % 5 == 0)
        {
            aluno = realloc(aluno, (*alunosCadastrados) * sizeof(Cliente));
        }
    }
}

void ConsultarCliente(Cliente *aluno, int *codigo)
{
    int index = PesquisarCodigo(aluno, *codigo);
    if (index != 0)
    {

        system("cls");
        printf("\n---------------------------\n");
        printf("Consulta de Cliente");
        printf("\n---------------------------\n\n");
        printf("Nome: %s\t\t", aluno[index].nome);
        printf("\t\tCodigo do Aluno: %d", *codigo);
        printf("\nModalidades: ");
        for(int i=0; i < ((int)( sizeof(aluno[index].modalidade)) / sizeof(aluno[index].modalidade[0])); i++)
        {
            printf("%s\n", aluno[index].modalidade[i]);
        }
        printf("\nIdade: %d\t\t",aluno[index].idade);
        printf("Local de nascimento: %s",aluno[index].localDeNascimento);
        printf("\nValor da mensalidade: R$%d",aluno[index].valorMensalidade);
        printf("\nVencimento do Boleto: %s",aluno[index].dataVencimentoBoleto);
        printf("\n---------------------------\n");

        if (aluno[index].responsavel == 1){
            printf("Dados do responsavel");
            printf("\n---------------------------\n");
            printf("Nome: %s", aluno[index].nomeResponsavel);
        }

        printf("\nRG: %s", aluno[index].RG);
        printf("\nCPF: %s", aluno[index].CPF);
        printf("\nEndereco: %s", aluno[index].endereco);
        printf("\n---------------------------\n");
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
	aluno->nome[search]='\0';

    for (search = 0; aluno->localDeNascimento[search] != '\n'; search++)
        ;
            aluno->localDeNascimento[search]='\0';
    

    for (search = 0; aluno->RG[search] != '\n'; search++)
        ;
        aluno->RG[search]='\0';
    

    for (search = 0; aluno->CPF[search] != '\n'; search++)
        ;
        aluno->CPF[search]='\0';
    

    for (search = 0; aluno->endereco[search] != '\n'; search++)
        ;
    aluno->endereco[search]='\0' ;
    

    for (search = 0; aluno->dataVencimentoBoleto[search] != '\n'; search++)
        ;
        aluno->dataVencimentoBoleto[search]='\0';
    

    if (aluno->responsavel == 1)
    {
        for (search = 0; aluno->nomeResponsavel[search] != '\n'; search++)
            ;
            aluno->nomeResponsavel[search]='\0';
        
    }
}

int PesquisarCodigo(Cliente *aluno, int codigo)
{
    if (codigo != 0)
    {
        for (int i = 0; codigo != aluno[i].codigo; i++)
            ;
        return codigo;
    }
    else
    {
        printf("Código não encontrado\n");
        return 0;
    }
}

int PesquisarIndiceVazio(Cliente *aluno)
{
    int i;
    for (i = 0; aluno[i].codigo != 0; i++)
        ;
    return i;
}
