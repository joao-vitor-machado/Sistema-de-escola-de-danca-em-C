#include <stdio.h>
#include <stdlib.h>
#include "salas.h"

void cadastrarSala(Sala *salas, int *qtdSalas)
{
    int i, j, k, id, codValido;
    id = *qtdSalas;

    if((id%5==0) && (id!=0)){
    	salas = (Sala *) realloc(salas,(id+5)*sizeof(Sala));
	}
    
	do{
		codValido=0;
		
		printf("Digite o numero da sala: \n");
    	scanf("%d", &salas[id].numero);
	    getchar();
	    
	    if(salas[id].numero == 0){ //confere se o numero digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(salas[id].numero == salas[k].numero){ //confere se o numero ja eh existente
					codValido=1;
				}
			}
		}
		
		if(codValido == 1){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1);

    printf("Digite o nome da sala: \n");
    fgets(salas[id].nome, 100, stdin);
    printf("Selecione o dia da semana que a sala sera utilizada: \n");
    printf("1- Domingo\n2- Segunda\n3- Terca\n4- Quarta\n5- Quinta\n6- Sexta\n7- Sabado\n");
    scanf("%d", &salas[id].diaSemana);
    printf("Selecione a opcao de horario que a sala sera utilizada: \n");
    printf("1- Periodo da Manha (9:00 - 12:00)\n2- Periodo da Tarde (14:00 - 17:00)\n3- Periodo da Noite (18:00 - 21:00)\n");
    scanf("%d", &salas[id].horario);

    for(i=0; i<3; i++){ //percorre as linhas (os horarios da sala)
        for(j=0; j<7; j++){ //percorre as colunas (os dias da semana)
            salas->matrizHorarios[i][j]=0;
            if(i==salas->horario-1 && j==salas->diaSemana-1)
                salas->matrizHorarios[i][j]=1;
        }
    }
}

void excluirSala(Sala *salas, int *qtdSalas)
{
    int salaExcluida, i, j, k, l, codValido=0, id;
    char op;
    
    id = *qtdSalas;
    
    printf("Estas são as salas cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", salas[j].numero, salas[j].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o numero da sala a ser excluida: \n");
    	scanf("%d", &salaExcluida);
	    getchar();
	    
	    if(salaExcluida == 0){ //confere se o codigo digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(salaExcluida != salas[k].numero){ //confere se o codigo eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);

    printf("Tem certeza que deseja excluir a sala %d? S/N\n", salaExcluida);
    scanf("%c", &op);
    getchar();
    
    for (i = 0; salas[i].numero != salaExcluida; i++); //procura a posicao de memoria onde o numero foi alocado
    
    if (op == 'S' || op == 's')
    {
        (*qtdSalas)--;
        
        for (l=0; l < id; l++){ 
            salas[l] = salas[l + 1];
        }
        
        if (*qtdSalas % 5 != 0 && *qtdSalas + 5 % 5 == 0)
        {
            salas = (Sala *) realloc(salas,(id)*sizeof(Sala));
        }
        
        printf("Modalidade excluida!\n");
    }
}

void alterarSala(Sala *salas, int *qtdSalas)
{
    int salaAlterada, op, i, j, k, id, codValido=0;
    id = *qtdSalas;
    
    printf("Estas sao as salas cadastradas no sistema: \n");
    for(j=0; j<id; j++){
        printf("%d: %s\n", salas[j].numero, salas[j].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o numero da sala a ser alterada: \n");
	    scanf("%d", &salaAlterada);
	    getchar();
	    
	    if(salaAlterada == 0){ //confere se o numero digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(salaAlterada != salas[k].numero){ //confere se o numero eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);

    
    printf("Selecione a opcao que deseja alterar?\n1- nome\n2- numero\n");
    scanf("%d", &op);
    getchar();
    
    for (i = 0; salas[i].numero != salaAlterada && i<id; i++); //procura a posicao de memoria onde o numero da sala foi alocado

    switch (op)
    {
    case 1:
        printf("Digite o novo nome da sala: \n");
        fgets(salas[i].nome, 100, stdin);
        break;
    case 2:
        printf("Digite o novo numero da sala: \n");
        scanf("%d", &salas[i].numero);
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void consultarSala(Sala *salas, int *qtdSalas)
{
    int i, j, k, salaConsultada, id, codValido=0;
    id = *qtdSalas;

    printf("Estas sao as salas cadastradas no sistema: \n");
    for(i=0; i<id; i++){
        printf("%d: %s\n", salas[i].numero, salas[i].nome);
    }
    
    do{
		codValido=0;
		
		printf("Digite o numero da sala que deseja consultar: \n");
    	scanf("%d", &salaConsultada);
	    getchar();
	    
	    if(salaConsultada == 0){ //confere se o numero digitado eh igual a 0
	    	codValido=1;
		} else {
			for(k=0; k<id; k++){
				if(salaConsultada != salas[k].numero){ //confere se o numero eh existente
					codValido+=2;
				}
			}
		}
		
		if(codValido == 1 || codValido == id*2){
			printf("Codigo invalido. Insira um codigo valido!\n");
		}
		
	} while (codValido == 1 || codValido == id*2);

    for(j=0; salas[j].numero != salaConsultada && j<id; j++); //procura a posicao de memoria onde o numero da sala foi alocado
    
    printf("Estas sao as informacoes cadastradas na sala %d\n", salaConsultada);
    printf("Nome: %s\n", salas[j].nome);
    
    switch(salas[j].diaSemana){
    	case 1:
    		printf("Dia da semana: Domingo\n");
    		break;
    	case 2:
    		printf("Dia da semana: Segunda\n");
    		break;
    	case 3:
    		printf("Dia da semana: Terca\n");
    		break;
    	case 4:
    		printf("Dia da semana: Quarta\n");
    		break;
    	case 5:
    		printf("Dia da semana: Quinta\n");
    		break;
    	case 6:
    		printf("Dia da semana: Sexta\n");
    		break;
    	case 7:
    		printf("Dia da semana: Sabado\n");
    		break;
	}
    
    if(salas[j].horario==1){
        printf("Horario: Periodo da Manha (9:00 - 12:00)\n");
    } else {
        if(salas[j].horario==2){
            printf("Horario: Periodo da Tarde (14:00 - 17:00)\n");
        } else {
            if(salas[j].horario==3){
                printf("Horario: Periodo da Noite (18:00 - 21:00)\n");
            }
        }
    }
    
}
