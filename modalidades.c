#include <stdio.h>
#include <stdlib.h>
#include "modalidades.h"

void cadastrarModalidade(Modalidade *modalidades, int *qtdModalidades){

	int codValido=0, id, i, k;
	id = *qtdModalidades;

    if((id%5==0) && (id!=0)){
    	modalidades = (Modalidade *) realloc(modalidades,(id+5)*sizeof(Modalidade)); //realocacao de memoria
	}
	
	do{
		codValido=0;
		
		printf("Digite o codigo da modalidade: \n");
    	scanf("%d", &modalidades[id].codigo);
	    getchar();
	    
	    if(modalidades[id].codigo == 0){ //confere se o codigo digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(modalidades[id].codigo == modalidades[k].codigo){ //confere se o codigo ja eh existente
					codValido=1;
				}
			}
		}
		
		if(codValido == 1){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1);
	
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
}

void excluirModalidade(Modalidade *modalidades, int *qtdModalidades){

    int modalidadeExcluida, i, j, k, l, id, codValido=0;
    char op;
    id = *qtdModalidades;
    
    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", modalidades[j].codigo, modalidades[j].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o numero da modalidade a ser excluida: \n");
    	scanf("%d", &modalidadeExcluida);
	    getchar();
	    
	    if(modalidadeExcluida == 0){ //confere se o codigo digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(modalidadeExcluida != modalidades[k].codigo){ //confere se o codigo eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);

    printf("Tem certeza que deseja excluir a modalidade %d? S/N\n", modalidadeExcluida);
    scanf("%c", &op);
    getchar();
    
    for (i = 0; modalidades[i].codigo != modalidadeExcluida; i++); //procura a posicao de memoria onde o codigo foi alocado
    
    if (op == 'S' || op == 's')
    {
        (*qtdModalidades)--;
        
        for (l=0; l < id; l++){ 
            modalidades[l] = modalidades[l + 1];
        }
        
        if (*qtdModalidades % 5 != 0 && *qtdModalidades + 5 % 5 == 0)
        {
            modalidades = (Modalidade *) realloc(modalidades,(id)*sizeof(Modalidade));
        }
        
        printf("Modalidade excluida!\n");
    }
}

void alterarModalidade(Modalidade *modalidades, int *qtdModalidades){
    int modalidadeAlterada, op, i, j, k, id, codValido=0;
    id = *qtdModalidades;
    
    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", modalidades[j].codigo, modalidades[j].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o codigo da modalidade a ser alterada: \n");
	    scanf("%d", &modalidadeAlterada);
	    getchar();
	    
	    if(modalidadeAlterada == 0){ //confere se o codigo digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(modalidadeAlterada != modalidades[k].codigo){ //confere se o codigo eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);
    
    printf("Selecione a opcao que deseja alterar?\n1- nome\n2- descricao da modalidade\n3- descricao dos materiais\n4- valor da mensalidade\n5- idade minima\n");
    scanf("%d", &op);
    getchar();
    
    for (i = 0; modalidades[i].codigo != modalidadeAlterada; i++); //procura a posicao de memoria onde o codigo foi alocado

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
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void consultarModalidade(Modalidade *modalidades, int *qtdModalidades){
    int modalidadeConsultada, id, i, j, k, codValido=0;
    id = *qtdModalidades;

    printf("Estas são as modalidades cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", modalidades[j].codigo, modalidades[j].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o codigo da modalidade que deseja consultar: \n");
    	scanf("%d", &modalidadeConsultada);
	    getchar();
	    
	    if(modalidadeConsultada == 0){ //confere se o codigo digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(modalidadeConsultada != modalidades[k].codigo){ //confere se o codigo eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);

    

    for(i=0; modalidades[i].codigo != modalidadeConsultada && i<id; i++); //procura a posicao de memoria onde o codigo foi alocado
    
    printf("Estas sao as informacoes cadastradas na modalidade %d\n", modalidadeConsultada);
    printf("Nome: %s\n", modalidades[i].nome);
    printf("Descricao da modalidade: %s\n", modalidades[i].descModalidade);
    printf("Descricao dos materiais: %s\n", modalidades[i].descMateriais);
    printf("Valor da mensalidade: %.2f\n", modalidades[i].valorMensalidade);
    printf("Idade minima: %d\n", modalidades[i].idade);
}

