#include <stdio.h>
#include "modalidades.h"

void cadastrarModalidade(Modalidade *modalidades, int *qtdModalidades){

    if(*qtdModalidades%5 == 0){
        modalidades = realloc(modalidades, (*qtdModalidades+5) * sizeof(Modalidade));
    }

    printf("Digite o nome da modalidade: \n");
    fgets(modalidades->nome, 100, stdin);
    do{
        printf("Digite o codigo da modalidade: \n");
        scanf("%d", &modalidades->codigo);
        printf("Codigo invalido. Digite um codigo valido!\n");
    } while (modalidades->codigo == 0);
    printf("Digite uma descricao para a modalidade: \n");
    fgets(modalidades->descModalidade, 200, stdin);
    printf("Digite uma descricao para os materiais necessarios: \n");
    fgets(modalidades->descMateriais, 200, stdin);
    printf("Digite o valor da mensalidade: \n");
    scanf("%f", &modalidades->valorMensalidade);
    printf("Digite a idade minima para fazer esta modalidade: \n");
    scanf("%d", &modalidades->idade);
    printf("Digite o nome do professor que lecionará a modalidade: \n");
    fgets(modalidades->nomeProfessor, 100, stdin);
    printf("Digite o numero da sala a ser utilizada: \n");
    scanf("%d", &modalidades->sala);

}

void excluirModalidade(Modalidade *modalidades, int *qtdModalidades){

    int modalidadeExcluida, i;
    char op;

    printf("Digite o numero da modalidade a ser excluida: \n");
    scanf("%d", &modalidadeExcluida);
    printf("Tem certeza que deseja excluir a modalidade %d? S/N\n", modalidadeExcluida);
    scanf("%c", &op);
    if (op == 'S')
    {
        for (i = 0; modalidades[i].codigo != modalidadeExcluida; i++);

        for (int j = i; j < *qtdModalidades; j++)
        {
            modalidades[j] = modalidades[j + 1];
        }
        *qtdModalidades -= 1;
        modalidades = realloc(modalidades, *qtdModalidades * sizeof(Modalidade));
    }

}

void alterarModalidade(Modalidade *modalidades){
    int modalidadeAlterada, op, i;

    printf("Digite o codigo da modalidade a ser alterada: \n");
    scanf("%d", &modalidadeAlterada);
    printf("Selecione a opcao que deseja alterar?\n1- nome\n2- descricao da modalidade\n3- descricao dos materiais\n4- valor da mensalidade\n5- idade minima\n6- professor\n7- sala\n");
    scanf("%d", &op);
    
    for (i = 0; modalidades[i].codigo != modalidadeAlterada; i++);

    switch (op)
    {
    case 1:
        printf("Digite o novo nome da modalidade: \n");
        fgets(modalidades[i].nome, 100, stdin);
        break;
    case 2:
        printf("Digite a nova descricao da modalidade: \n");
        fgets(modalidades[i].descModalidade, 200, stdin);
        break;
    case 3:
        printf("Digite a nova descricao dos materiais: \n");
        fgets(modalidades[i].descMateriais, 200, stdin);
        break;
    case 4:
        printf("Digite o novo valor da mensalidade: \n");
        scanf("%d", &modalidades[i].valorMensalidade);
        break;
    case 5:
        printf("Digite a nova idade minima: \n");
        scanf("%d", &modalidades[i].idade);
        break;
    case 6:
        printf("Digite o nome do novo professor: \n"); //prof
        scanf("%d", &modalidades[i].nomeProfessor);
        break;
    case 7:
        printf("Digite o numero da nova sala: \n"); //sala
        scanf("%d", &modalidades[i].sala);
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void consultarModalidade(Modalidade *modalidades, int *qtdModalidades){
    int i, modalidadeConsultada;

    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(i=0; i<*qtdModalidades; i++){
        printf("%d: %s\n", modalidades[i].codigo, modalidades[i].nome);
    }

    printf("Digite o codigo da modalidade que deseja consultar: \n");
    scanf("%d", &modalidadeConsultada);

    for(i=0; modalidades[i].codigo != modalidadeConsultada; i++);
    printf("Estas sao as informacoes cadastradas na modalidade %d\n", modalidadeConsultada);
    printf("Nome: %s\n", modalidades[i].nome);
    printf("Descricao da modalidade: %s\n", modalidades[i].descModalidade);
    printf("Descricao dos materiais: %s\n", modalidades[i].descMateriais);
    printf("Valor da mensalidade: %d\n", modalidades[i].valorMensalidade);
    printf("Idade minima: %d\n", modalidades[i].idade);
    printf("Nome do professor: %s\n", modalidades[i].nomeProfessor);
    printf("Sala: %d\n", modalidades[i].sala);
}
