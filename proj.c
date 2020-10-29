#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "clientes.h"
#include "professores.h"
#include "salas.h"
#include "modalidades.h"
#include "horarios.h"
#include "mensalidade.h"

#define valorAcrescimoMemoria 5

void TelaPrincipal();
int TelaMenuCliente();
void TelaMenuProfessor();
void TelaMenuSala();
void TelaMenuModalidade();
void TelaMenuHorario();

int ValidarCodigo();

int main()
{
    setlocale(LC_ALL, "");
    int opcaoMenu, opcaoSubMenu, alunosCadastrados = 0, professoresCadastrados = 0, codigo = 0;
    Cliente *aluno;
    Professor *professores;
    Sala *salas;
    Modalidade *modalidades;

    aluno = (Cliente *)malloc(valorAcrescimoMemoria * sizeof(Cliente));
    for (int i = 0; i < valorAcrescimoMemoria; i++)
    {
        aluno[i].codigo = 0;
    }
    salas = (Sala *)malloc(5 * sizeof(Sala));
    modalidades = (Modalidade *)malloc(5 * sizeof(Modalidade));

    TelaMenuPrincipal();
    scanf("%d", &opcaoMenu);
    switch (opcaoMenu)
    {
    case 1:
    {
        opcaoSubMenu = TelaMenuCliente();
        switch (opcaoSubMenu)
        {
        case 1:
            CadastrarCliente(&aluno, &alunosCadastrados);
            break;

        case 2:
            codigo = ValidarCodigo();
            ConsultarCliente(&aluno, &codigo);
            break;

        case 3:
            codigo = ValidarCodigo();
            AlterarCliente(&aluno, &codigo);
            break;

        case 4:
            codigo = ValidarCodigo();
            ExcluirCliente(&aluno, &codigo, &alunosCadastrados);
            break;
        }
        break;
    }
    case 2:
    {
        TelaMenuProfessor();
        scanf("%d", &opcaoSubMenu);
        break;
    }
    case 3:
    {
        int qtdSalas = 0;
        TelaMenuSala();
        scanf("%d", &opcaoSubMenu);
        switch (opcaoSubMenu)
        {
        case 1:
            cadastrarSala(&salas, &qtdSalas);
            qtdSalas += 1;
            break;
        case 2:
            consultarSala(&salas, &qtdSalas);
            break;
        case 3:
            alterarSala(&salas);
            break;
        case 4:
            excluirSala(&salas, &qtdSalas);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }

        break;
    }
    case 4:
    {
        int qtdModalidades = 0;
        TelaMenuModalidade();
        scanf("%d", &opcaoSubMenu);
        switch (opcaoSubMenu)
        {
        case 1:
            cadastrarModalidade(&modalidades, &qtdModalidades);
            qtdModalidades += 1;
            break;
        case 2:
            consultarModalidade(&modalidades, &qtdModalidades);
            break;
        case 3:
            alterarModalidade(&modalidades);
            break;
        case 4:
            excluirModalidade(&modalidades, &qtdModalidades);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }

        break;
    }
    case 5:
    {
        TelaMenuHorario();
        scanf("%d", &opcaoSubMenu);
        break;
    }
    default:
    {
        printf("%Opção inválida!");
        break;
    }
    }
}

void TelaMenuPrincipal()
{

    printf("---------------------------\n");
    printf("    Menu principal\n");
    printf("---------------------------\n");
    printf("1) *Menu Clientes\n");
    printf("2) *Menu Professores\n");
    printf("3) *Menu Salas\n");
    printf("4) *Menu Modalidades\n");
    printf("5) *Menu Horario\n");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("---------------------------\n");
}

int TelaMenuCliente()
{
    int opcao;
    system("cls");

    printf("---------------------------\n");
    printf("    Menu Clientes\n");
    printf("---------------------------\n");
    printf("1) *Cadastrar Clientes\n");
    printf("2) *Consulta de Clientes\n");
    printf("3) *Alteracao de Clientes\n");
    printf("4) *Exclusao de Clientes\n");
    printf("0) *Cancelar\n");
    printf("---------------------------\n");
    scanf("%d", &opcao);
    system("cls");

    return opcao;
}

void TelaMenuSala()
{

    system("cls");

    printf("---------------------------\n");
    printf("    Menu Sala\n");
    printf("---------------------------\n");
    printf("1) *Cadastrar Sala\n");
    printf("2) *Consulta de Sala\n");
    printf("3) *Alteracao de Sala\n");
    printf("4) *Exclusao de Sala\n");
    printf("0) *Cancelar\n");
    printf("---------------------------\n");
}

void TelaMenuModalidade()
{

    system("cls");

    printf("---------------------------\n");
    printf("    Menu Modalidade\n");
    printf("---------------------------\n");
    printf("1) *Cadastrar Modalidade\n");
    printf("2) *Consulta de Modalidade\n");
    printf("3) *Alteracao de Modalidade\n");
    printf("4) *Exclusao de Modalidade\n");
    printf("0) *Cancelar\n");
    printf("---------------------------\n");
}

void TelaMenuHorario()
{

    system("cls");

    printf("---------------------------\n");
    printf("    Menu Horario\n");
    printf("---------------------------\n");
    printf("1) *Cadastrar Horario\n");
    printf("2) *Consulta de Horario\n");
    printf("3) *Alteracao de Horario\n");
    printf("4) *Exclusao de Horario\n");
    printf("0) *Cancelar\n");
    printf("---------------------------\n");

    system("cls");
}

int ValidarCodigo()
{
    system("cls");
    printf("Insira o codigo do aluno: ");
    printf("\n---------------------------\n");
    int codigo;

    do
    {
        scanf("%d", &codigo);

        if (codigo == 0)
            pritnf("Código digitado Inválido\nInsira um código válido: ");

    } while (codigo == 0)

        return codigo;
}