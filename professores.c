#include <stdio.h>
#include <stdlib.h>
#include "professores.h"
#include "salas.h"
#include "modalidades.h"
#include "types.h"

void TelaMenuProfessor()
{
		system("cls");
        printf("---------------------------\n");
        printf("    Menu Professores\n");
        printf("---------------------------\n");
        printf("1) *Cadastrar Professores\n");
        printf("2) *Consulta de Professores\n");
        printf("3) *Alteracao de Professores\n");
        printf("4) *Exclusao de Professores\n");
        printf("0) *Cancelar\n");
        printf("---------------------------\n");
	
}

void cadastrarProfessor(Professor *professores, int *professoresCadastrados, Sala *salas, int *qtdSalas, Modalidade *modalidades, int *qtdModalidades)
{
	
    int numHorarios, i, opcao, max;
    
    if (*professoresCadastrados % 5 == 0)
    {
    	max = *professoresCadastrados + 5;
        professores = realloc(professores, (max) * sizeof(Professor));
    }
    else {
    	max = *professoresCadastrados;
	}

    *professoresCadastrados += 1;

    professores[*professoresCadastrados].codigoProfessor = *professoresCadastrados;
    
	getchar();
    printf("Digite o nome do professor que ser� cadastrado\n");
    fgets(professores[*professoresCadastrados].nome, 255, stdin);

    printf("\nDigite o c�digo para a modalidade lecionada\n");
    scanf("%d", &professores[*professoresCadastrados].modalidadeLecionada);

	getchar();
    printf("\nDigite a data de nascimento. Exemplo: 00/00/0000\n");
    fgets(professores[*professoresCadastrados].dataDeNascimento, 10, stdin);
    
    getchar();
    getchar();
    printf("\nDigite o local de nascimento\n");
    fgets(professores[*professoresCadastrados].localDeNascimento, 255, stdin);

	printf("\nDigite o RG\n");
    scanf("%d", &professores[*professoresCadastrados].RG);

    printf("\nInserir:\n");
    printf("1) CPF\n");
    printf("2) CNPJ\n");
	
	scanf("%d", &opcao);
	
    switch (opcao)
    {
    case 1:
        printf("\nDigite o CPF\n");
        scanf("%d", &professores[*professoresCadastrados].CPF);
        professores[*professoresCadastrados].CNPJ = 0;
        break;
    case 2:
        printf("\nDigite o CNPJ\n");
        scanf("%d", &professores[*professoresCadastrados].CNPJ);
        professores[*professoresCadastrados].CPF = 0;
        break;

    default:
        printf("\nDigite o CPF\n");
        scanf("%d", &professores[*professoresCadastrados].CPF);
        professores[*professoresCadastrados].CNPJ = 0;
        break;
    }
	
	getchar();
    printf("\nDigite o endere�o da resid�ncia\n");
    fgets(professores[*professoresCadastrados].endereco, 255, stdin);

    printf("\nDigite o sal�rio por aluno\n");
    scanf("%f", &professores[*professoresCadastrados].salarioPorAluno);
    
	/*
    printf("Estas s�o as salas cadastradas no sistema: \n"); //Mostra todas as salas que existem
    for (i = 0; i < *qtdSalas; i++)
    {
        printf("%d: %s\n", salas[i].numero, salas[i].nome);
    } //end

    printf("\nDigite o n�mero da sala que ser� usada por ele(a)\n");
    scanf("%d", &professores[*professoresCadastrados].salaUsada);

    for (i = 0; salas[i].numero != professores[*professoresCadastrados].salaUsada; i++)
        ;
    printf("Estas sao as informacoes cadastradas na sala %d\n", professores[*professoresCadastrados].salaUsada);
    printf("Nome: %s\n", salas[i].nome);
    if (salas[i].horario == 1)
    {
        printf("Hor�rio: Per�odo da Manh� (9:00 - 12:00)\n");
    }
    else
    {
        if (salas[i].horario == 2)
        {
            printf("Hor�rio: Per�odo da Tarde (14:00 - 17:00)\n");
        }
        else
        {
            if (salas[i].horario == 3)
            {
                printf("Hor�rio: Per�odo da Noite (18:00 - 21:00)\n");
            }
        }
    }

    printf("Digite o n�mero de hor�rios que ser�o usados dessa sala\n");
    scanf("%d", &numHorarios);

    printf("\nDigite o(s) hor�rios de acordo com sua linha e coluna (linha = per�odo, coluna = dia) separados por espa�o (para linha e coluna) e enter (para outro dia)\n");

    for (i = 0; i < numHorarios; i++)
    {
        scanf("%d %d", &professores[*professoresCadastrados].periodoDia, &professores[*professoresCadastrados].diaSemana);
    }

    printf("\nCadastro encerrado\n\n");
*/

	int codigo = *professoresCadastrados;
	
	printf("\n\nO nome registrado �:");
	fputs(professores[codigo].nome, stdout);
	
	printf("\n\nA modalidade lecionada � a de c�digo %d", professores[codigo].modalidadeLecionada);
	
	printf("\n\nO local de nascimento est� registrado como:");
	fputs(professores[codigo].localDeNascimento, stdout);
	
	printf("\n\nA data de nascimento est� registrada como sendo ");
	fputs(professores[codigo].dataDeNascimento, stdout);
	
	printf("\n\nO RG registrado �: %d", professores[codigo].RG);
	
	if (professores[codigo].CPF == 0)
	    {
	    printf("\n\nNenhum CPF registrado\n");
	    }
	    else
	    {
	    printf("\n\nO CPF registrado �: %d", professores[codigo].CPF);
	    }
	
	    if (professores[codigo].CNPJ == 0)
	        {
	        printf("\n\nNenhum CNPJ registrado\n");
	        }
	    else
	        {
	        printf("\n\nO CNPJ registrado �: %d", professores[codigo].CNPJ);
	        }
	
		printf("\n\nO endere�o registrado �: ");
	    fputs(professores[codigo].endereco, stdout);
	
	    printf("\n\nO sal�rio por aluno desse professor � de: R$ %2.f", professores[codigo].salarioPorAluno);
	
	    printf("\n\nA sala utilizada atualmente � a sala de n�mero %d", professores[codigo].salaUsada);
	    printf("\n\n");
    }


void alterarProfessor(Professor *professores, int *professoresCadastrados, Sala *salas, int *qtdSalas, Modalidade *modalidades, int *qtdModalidades)
{
    int opcao = 1, codigo, salaPretendida, Status, modalidadePretendida, i, diaPretendido, periodoPretendido, codigoSala;
    
    
    
    printf("\nQual o c�digo do professor que deseja alterar>\n");
    scanf("%d", &codigo);

    while (opcao != 0)
    {
        printf("---------------------------\n");
        printf("    O que deseja alterar?\n");
        printf("---------------------------\n");
        printf("1) *Nome\n");
        printf("2) *Modalidade Lecionada\n");
        printf("3) *Local de Nascimento\n");
        printf("4) *Data de nascimento\n");
        printf("5) *RG\n");
        printf("6) *CPF\n");
        printf("7) *CNPJ\n");
        printf("8) *Endere�o\n");
        printf("9) *Salario por aluno\n");
        printf("10) *Sala usada\n");
        printf("0) *Cancelar\n");
        printf("---------------------------\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\nO nome registrado �:");
            fputs(professores[codigo].nome, stdout);

            printf("\n\nQual o novo nome?\n");
            fgets(professores[codigo].nome, 255, stdin);
            break;

        case 2:
            printf("\n\nA modalidade lecionada � a de c�digo %d", professores[codigo].modalidadeLecionada);

            printf("\n\nQual o c�digo da modalidade que ser� lecionada a partir de hoje?\n");
            scanf("%d", &modalidadePretendida);

            for (i = 0; i < *qtdModalidades; i++)
            {
                if (modalidadePretendida == modalidades[i].codigo)
                {
                    professores[codigo].modalidadeLecionada = modalidadePretendida;
                }
            }
            break;

        case 3:
            printf("\n\nO local de nascimento est� registrado como:");
            fputs(professores[codigo].localDeNascimento, stdout);

            printf("\n\nDigite o local de nascimento\n");
            fgets(professores[codigo].localDeNascimento, 100, stdin);
            break;

        case 4:
            printf("\n\nA data de nascimento est� registrada como sendo");
            fputs(professores[codigo].dataDeNascimento, stdout);

            printf("\n\nDigite a data correta\n");
            fgets(professores[codigo].dataDeNascimento, 10, stdin);
            break;

        case 5:
            printf("\n\nO RG registrado �: %d", professores[codigo].RG);

            printf("\n\nDigite o RG correto\n");
            scanf("%d", professores[codigo].RG);
            break;

        case 6:

            if (professores[codigo].CPF == 0)
            {
                printf("\n\nNenhum CPF registrado\n");
            }
            else
            {
                printf("\n\nO CPF registrado �: %d");
            }

            printf("Digite o CPF correto\n");
            scanf("%d", professores[codigo].CPF);

            break;

        case 7:

            if (professores[codigo].CNPJ == 0)
            {
                printf("\n\nNenhum CNPJ registrado\n");
            }
            else
            {
                printf("\n\nO CNPJ registrado �: %d");
            }

            printf("Digite o CNPJ correto\n");
            scanf("%d", professores[codigo].CNPJ);

            break;

        case 8:

            printf("\n\nO endere�o registrado �:");
            fputs(professores[codigo].endereco, stdout);

            printf("\n\nDigite o novo endere�o\n");
            fgets(professores[codigo].endereco, 255, stdin);
            break;

        case 9:
            printf("\n\nO sal�rio por aluno desse professor � de: R$ %2.f", professores[codigo].salarioPorAluno);

            printf("\n\nDigite o sal�rio atualizado\n");
            scanf("%f", professores[codigo].salarioPorAluno);
            break;

        case 10:
            printf("\n\nA sala utilizada atualmente � a sala de n�mero %d", professores[codigo].salaUsada);

            printf("Estas s�o as salas cadastradas no sistema: \n");
            for (i = 0; i < *qtdSalas; i++)
            {
                printf("%d: %s\n", salas[i].numero, salas[i].nome);
            }

            do
            {
                printf("\n\nDigite o n�mero da sala que voc� deseja utilizar\n");
                scanf("%d", &salaPretendida);
                for (i = 0; i < *qtdSalas; i++)
                {
                    if (salas[i].numero == salaPretendida)
                    {
                        professores[codigo].salaUsada = salaPretendida;
                        Status = 1;
                        codigoSala = i;
                        break;
                    }
                }
                if (Status == 0)
                {
                    printf("\n\nNenhuma sala encontrada. por favor, digite outro n�mero de sala\n");
                }
            } while (Status != 1);

            do
            {
                printf("---------------------------\n");
                printf("    Qual o dia da semana que deseja usar a sala?\n");
                printf("---------------------------\n");
                printf("1) Domingo");
                printf("2) Segunda\n");
                printf("3) Ter�a\n");
                printf("4) Quarta\n");
                printf("5) Quinta\n");
                printf("6) Sexta\n");
                printf("7) S�bado\n");
                printf("---------------------------\n");

                scanf("%d", &diaPretendido);

                printf("\n\n---------------------------\n");
                printf("    Qual o per�odo do dia em que deseja usar a sala?\n");
                printf("---------------------------\n");
                printf("1) Manh�");
                printf("2) Tarde\n");
                printf("3) Noite\n");
                printf("---------------------------\n");

                scanf("%d", &periodoPretendido);

                if (salas[codigoSala].matrizHorarios[diaPretendido][periodoPretendido] == 1)
                {
                    professores[codigo].diaSemana = diaPretendido;
                    professores[codigo].periodoDia = periodoPretendido;
                    Status = 1;
                }
                else
                {
                    printf("\n\nN�o foi poss�vel selecionar esse hor�rio. Por favor, escolha outro");
                    Status = 0;
                }
            } while (Status != 1);

            break;

        case 0:
            break;
        default:
            printf("\nNenhuma das op��es selecionadas. Por favor, selecione uma op��o v�lida\n");
        }
    }
    
}

void excluirProfessor(Professor *professores, int *professoresCadastrados)
{
    int codigo;

    printf("\n\nDigite o c�digo do professor\n");
    scanf("%d", &codigo);

    if (codigo < *professoresCadastrados || codigo > *professoresCadastrados)
    {
        printf("\n\nNenhum professor cadastrado com esse c�digo. Imposs�vel de excluir\n");
    }
    else
    {
        professores[codigo].codigoProfessor = 0;
        (*professoresCadastrados)--;
        if (*professoresCadastrados % 5 != 0 && *professoresCadastrados + 5 % 5 == 0)
        {
            professores = realloc(professores, (*professoresCadastrados) * sizeof(Professor));
        }
    }

  
}

void consultarProfessor(Professor *professores, int *professoresCadastrados)
{
    int codigo;

    printf("\n\nInsira o c�digo do professor que deseja\n");
    scanf("%d", &codigo);

    if (codigo < *professoresCadastrados || codigo > *professoresCadastrados)
    {
        printf("\n\nNenhum professor cadastrado com esse c�digo. Imposs�vel de consultar\n");
    }
    else
    {

        	printf("\n\nO nome registrado �:");
	fputs(professores[codigo].nome, stdout);
	
	printf("\n\nA modalidade lecionada � a de c�digo %d", professores[codigo].modalidadeLecionada);
	
	printf("\n\nO local de nascimento est� registrado como:");
	fputs(professores[codigo].localDeNascimento, stdout);
	
	printf("\n\nA data de nascimento est� registrada como sendo ");
	fputs(professores[codigo].dataDeNascimento, stdout);
	
	printf("\n\nO RG registrado �: %d", professores[codigo].RG);
	
	if (professores[codigo].CPF == 0)
	    {
	    printf("\n\nNenhum CPF registrado\n");
	    }
	    else
	    {
	    printf("\n\nO CPF registrado �: %d", professores[codigo].CPF);
	    }
	
	    if (professores[codigo].CNPJ == 0)
	        {
	        printf("\n\nNenhum CNPJ registrado\n");
	        }
	    else
	        {
	        printf("\n\nO CNPJ registrado �: %d", professores[codigo].CNPJ);
	        }
	
		printf("\n\nO endere�o registrado �: ");
	    fputs(professores[codigo].endereco, stdout);
	
	    printf("\n\nO sal�rio por aluno desse professor � de: R$ %2.f", professores[codigo].salarioPorAluno);
	
	    printf("\n\nA sala utilizada atualmente � a sala de n�mero %d", professores[codigo].salaUsada);
	    printf("\n\n");
    }

  
}
