#include <stdio.h>
#include "clientes.h"

void CadastrarCliente(Cliente *aluno, int *index, int *alunosCadastrados)
{
    int tempCod, sucesso = 0, tempIndex;
    int qntModalidades = 1;

    if (*alunosCadastrados % 5 == 0)
    {
        alunos = realloc(alunos, (*alunosCadastrados + 5) * sizeof(Cliente));
        for (int i = *alunosCadastrados; i < *alunosCadastrados + 5; i++)
        {
            aluno[i].codigo = 0;
        }
    }

    tempIndex = *index;
    do
    {
        if (aluno[tempIndex].codigo == 0)
        {
            printf("---------------------------\n");
            printf("    Cadastro de Cliente");
            printf("\n---------------------------\n\n");
            printf("Nome:\t\t");
            fgets(aluno[tempIndex].nome, 255, stdin);
            printf("\t\tCodigo do Aluno: ");
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
                    printf("\nCódigo inserido inválido!\nInsira um código válido: ");
                }
            } while (tempCod == 0)

                do
            {
                printf("\nEm quantas modalidades você deseja se cadastrar?: ");
                scanf("%d", &qntModalidades);
                if (qntModalidades < 0)
                    printf("insira um valor válido\n");
            }
            while (qntModalidades < 0)
                ;

            aluno[tempIndex].modalidade = (int *)malloc(qntModalidades * sizeof(int));

            for (int i = 1; i <= qntModalidades; i++)
            {
                printf("\ncódigo da modalidade%d: ", i);
                scanf("%d", aluno[tempIndex].modalidade[i - 1]);
                getchar();
            }

            printf("\nIdade: \t\t");
            scanf("%d", aluno[tempIndex].idade);
            getchar();
            printf("Local de nascimento: ");
            fgets(aluno[tempIndex].localDeNascimento, 255, stdin);
            printf("\nEndereco: ");
            fgets(aluno[tempIndex].endereco, 255, stdin);
            printf("\nValor da mensalidade: R$");
            scanf("%d", aluno[tempIndex].valorMensalidade);
            getchar();
            CalcularMensalidade(aluno, tempIndex, &qntModalidades);

            printf("\nVencimento do Boleto: ");
            fgets(aluno[tempIndex].dataVencimentoBoleto, 10, stdin);
            if (aluno[tempIndex].idade < 18)
            {
                printf("\n---------------------------\n");
                printf("Dados do responsavel");
                printf("\n---------------------------\n");
                printf("Nome: ");
                fgets(aluno[tempIndex].nomeResponsavel, 255, stdin);
                printf("\nRG: ");
                fgets(aluno[tempIndex].RG, 15, stdin);
                printf("\nCPF: ");
                fgets(aluno[tempIndex].CPF, 11, stdin);
                printf("\n---------------------------\n");
                system("cls");

                aluno[tempIndex].responsavel = 1;
            }

            else
            {
                printf("\nRG: ");
                fgets(aluno[tempIndex].RG, 15, stdin);
                printf("\nCPF: ");
                fgets(aluno[tempIndex].CPF, 11, stdin);
                printf("\n---------------------------\n");

                aluno[tempIndex].responsavel = 0;
            }
            system("cls");
            (*alunosCadastrados)++;
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
    int indexAlterar = PesquisarCodigo(*codigo);
    printf("\n---------------------------\n");
    printf("Alteracao dos dados do Cliente");
    printf("\n---------------------------\n");
    printf("Voce esta alterando o aluno: %s", aluno[indexAlterar].nome);
    printf("\n---------------------------\n\n");
    printf("Nome: %s\t\t", aluno[indexAlterar].nome);
    printf("\nModalidade: ");
    printf("\nIdade: \t\t");
    printf("Local de nascimento: ");
    printf("\nValor da mensalidade: R$");
    printf("\nVencimento do Boleto: ");
    printf("\n---------------------------\n");
    printf("Dados do responsavel");
    printf("\n---------------------------\n");
    printf("Nome: ");
    printf("\nRG: ");
    printf("\nCPF: ");
    printf("\nEndereco: ");
    printf("\n---------------------------\n");
    system("cls");
}

void ExcluirCliente(Cliente *aluno, int *codigo, int *alunosCadastrados)
{
    char op;
    int index = PesquisarCodigo(*codigo);
    printf("Exclusao do Cliente");
    printf("\n---------------------------\n");
    printf("Você esta prestes a excluir o aluno: %s\t de código: %d", aluno[index].nome, aluno[index].codigo);
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
            alunos = realloc(alunos, (*alunosCadastrados) * sizeof(Cliente));
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
        for(int i=0; i < ((int)( sizeof(array) / sizeof(aluno[index].modalidade[0])); i++)
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
        printf("\nEndereco: %s", aluno[index].) endereco;
        printf("\n---------------------------\n");
        system("cls");
    }
}

void CalcularMensalidade(Cliente *aluno, int index, int *quantidadeDeModalidades)
{
    if (*quantidadeDeModalidades >= 2)
    {
        aluno[index].valorMensalidade -= (0.05 * aluno[index].valorMensalidade);
    }
}

void LimparEspacoVazio(Cliente *aluno, int index)
{
    int search;
    for (search = 0; aluno[index].nome != '\n'; search++)
        ;
    aluno[index].nome = '\0';

    for (search = 0; aluno[index].localDeNascimento != '\n'; search++)
        ;
    aluno[index].localDeNascimento = '\0';

    for (search = 0; aluno[index].RG != '\n'; search++)
        ;
    aluno[index].RG = '\0';

    for (search = 0; aluno[index].CPF != '\n'; search++)
        ;
    aluno[index].CPF = '\0';

    for (search = 0; aluno[index].endereco != '\n'; search++)
        ;
    aluno[index].endereco = '\0';

    for (search = 0; aluno[index].dataVencimentoBoleto != '\n'; search++)
        ;
    aluno[index].dataVencimentoBoleto = '\0';

    if (aluno[index].responsavel == 1)
    {
        for (search = 0; aluno[index].nomeResponsavel != '\n'; search++)
            ;
        aluno[index].nomeResponsavel = '\0';
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