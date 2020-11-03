#include <stdio.h>
#include <stdlib.h>
#include "modalidades.h"

void cadastrarModalidade(Modalidade *modalidades, int *qtdModalidades){

	int codValido, id, i;
	id = *qtdModalidades;

    /*if(*qtdModalidades%5 == 0){
        modalidades = realloc(modalidades, (*qtdModalidades+5) * sizeof(Modalidade));
    } */
	
	do{
	codValido=0;
		
	printf("Digite o codigo da modalidade: \n");
    scanf("%d", &modalidades[id].codigo);
    getchar();
    
    if(modalidades[id].codigo == 0){
    	printf("Codigo invalido. Insira um codigo valido!\n");
    	codValido=1;
	}
    
	} while (codValido==1);
	
    printf("Digite o nome da modalidade: \n");
    fgets(modalidades[id].nome, 100, stdin);

    printf("Digite uma descricao para a modalidade: \n");
    fgets(modalidades[id].descModalidade, 200, stdin);
    
    printf("Digite uma descricao para os materiais necessarios: \n");
    fgets(modalidades[id].descMateriais, 200, stdin);
    
    printf("Digite o valor da mensalidade: \n");
    scanf("%f", &modalidades[id].valorMensalidade);
    
    printf("Digite a idade minima para fazer esta modalidade: \n");
    scanf("%d", &modalidades[id].idade);
    getchar();
    
    printf("Digite o nome do professor que lecionará a modalidade: \n");
    fgets(modalidades[id].nomeProfessor, 100, stdin);
    
    printf("Digite o numero da sala a ser utilizada: \n");
    scanf("%d", &modalidades[id].sala);
    
    //printf("Codigo: %d\nNome: %s\nDescricao modalidade: %s\nDescricao materiais: %s\nValor mensalidade: %.2f\nIdade minima: %d\nNome professor: %s\nSala: %d\n", modalidades[id].codigo, modalidades[id].nome, modalidades[id].descModalidade, modalidades[id].descMateriais, modalidades[id].valorMensalidade, modalidades[id].idade, modalidades[id].nomeProfessor, modalidades[id].sala);
}

void excluirModalidade(Modalidade *modalidades, int *qtdModalidades){

    int modalidadeExcluida, i, j;
    char op;

    printf("Digite o numero da modalidade a ser excluida: \n");
    scanf("%d", &modalidadeExcluida);
    printf("Tem certeza que deseja excluir a modalidade %d? S/N\n", modalidadeExcluida);
    scanf("%c", &op);
    if (op == 'S')
    {
        for (i = 0; modalidades[i].codigo != modalidadeExcluida; i++);

        for (j = i; j < *qtdModalidades; j++)
        {
            modalidades[j] = modalidades[j + 1];
        }
        *qtdModalidades -= 1;
        modalidades = realloc(modalidades, *qtdModalidades * sizeof(Modalidade));
    }

}

void alterarModalidade(Modalidade *modalidades, int *qtdModalidades){
    int modalidadeAlterada, op, i, j, id;
    id = *qtdModalidades;
    
    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", modalidades[j].codigo, modalidades[j].nome);
    }

    printf("Digite o codigo da modalidade a ser alterada: \n");
    scanf("%d", &modalidadeAlterada);
    printf("Selecione a opcao que deseja alterar?\n1- nome\n2- descricao da modalidade\n3- descricao dos materiais\n4- valor da mensalidade\n5- idade minima\n6- professor\n7- sala\n");
    scanf("%d", &op);
    
    for (i = 0; modalidades[i].codigo != modalidadeAlterada; i++);

    switch (op)
    {
    case 1:
        printf("Digite o novo nome da modalidade: \n"); //alteracao nome
        fgets(modalidades[i].nome, 100, stdin);
        break;
    case 2:
        printf("Digite a nova descricao da modalidade: \n"); //alteracao descricao
        fgets(modalidades[i].descModalidade, 200, stdin);
        break;
    case 3:
        printf("Digite a nova descricao dos materiais: \n"); //alteracao materiais
        fgets(modalidades[i].descMateriais, 200, stdin);
        break;
    case 4:
        printf("Digite o novo valor da mensalidade: \n"); //alteracao mensalidade
        scanf("%f", &modalidades[i].valorMensalidade);
        break;
    case 5:
        printf("Digite a nova idade minima: \n"); //alteracao idade minima
        scanf("%d", &modalidades[i].idade);
        break;
    case 6:
        printf("Digite o nome do novo professor: \n"); //alteracao prof
        scanf("%d", &modalidades[i].nomeProfessor);
        break;
    case 7:
        printf("Digite o numero da nova sala: \n"); //alteracao sala
        scanf("%d", &modalidades[i].sala);
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void consultarModalidade(Modalidade *modalidades, int *qtdModalidades){
    int modalidadeConsultada, id, i, j;
    id = *qtdModalidades;

    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", modalidades[j].codigo, modalidades[j].nome);
    }

    printf("Digite o codigo da modalidade que deseja consultar: \n");
    scanf("%d", &modalidadeConsultada);

    for(i=0; modalidades[i].codigo != modalidadeConsultada && i<id; i++);
    printf("Estas sao as informacoes cadastradas na modalidade %d\n", modalidadeConsultada);
    printf("Nome: %s\n", modalidades[i].nome);
    printf("Descricao da modalidade: %s\n", modalidades[i].descModalidade);
    printf("Descricao dos materiais: %s\n", modalidades[i].descMateriais);
    printf("Valor da mensalidade: %.2f\n", modalidades[i].valorMensalidade);
    printf("Idade minima: %d\n", modalidades[i].idade);
    printf("Nome do professor: %s\n", modalidades[i].nomeProfessor);
    printf("Sala: %d\n", modalidades[i].sala);
}

