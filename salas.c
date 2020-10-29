#include <stdio.h>
#include "salas.h"

void cadastrarSala(Sala *salas, int *qtdSalas)
{
    int i, j;

    if(*qtdSalas%5 == 0){
        salas = realloc(salas, (*qtdSalas+5) * sizeof(Sala));
    }

    printf("Digite o nome da sala: \n");
    fgets(salas.nome, 100, stdin);
    printf("Digite o numero da sala: \n");
    scanf("%d", &salas.numero); 
    printf("Selecione o dia da semana que a sala sera utilizada: \n");
    printf("1- Domingo\n2- Segunda\n3- Terca\n4- Quarta\n5- Quinta\n6- Sexta\n7- Sabado\n");
    scanf("%d", &salas.diaSemana);
    printf("Selecione a opcao de horario que a sala sera utilizada: \n");
    printf("1- Período da Manhã (9:00 - 12:00)\n2- Período da Tarde (14:00 - 17:00)\n3- Período da Noite (18:00 - 21:00)\n");
    scanf("%d", &salas.horario);

    for(i=0; i<3; i++){ //percorre as linhas (os horários da sala)
        for(j=0; j<7; j++){ //percorre as colunas (os dias da semana)
            if(i==salas.horario-1 && j==salas.diaSemana-1)
                salas.matrizHorarios[i][j]=1;
        }
    }
}

void excluirSala(Sala *salas, int *qtdSalas)
{
    int salaExcluida, i;
    char op;

    printf("Digite o numero da sala a ser excluida: \n");
    scanf("%d", &salaExcluida);
    printf("Tem certeza que deseja excluir a sala %d? S/N\n", salaExcluida);
    scanf("%c", &op);
    if (op == 'S')
    {
        for (i = 0; salas[i].numero != salaExcluida; i++);

        for (int j = i; j < *qtdSalas; j++)
        {
            salas[j] = salas[j + 1];
        }
        *qtdSalas -= 1;
        salas = realloc(salas, *qtdSalas * sizeof(Sala));
    }
}

void alterarSala(Sala *salas)
{
    int salaAlterada, op, i;

    printf("Digite o numero da sala a ser alterada: \n");
    scanf("%d", &salaAlterada);
    printf("Selecione a opcao que deseja alterar?\n1- nome\n2- numero\n");
    scanf("%d", &op);
    
    for (i = 0; salas[i].numero != salaAlterada; i++);

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
        printf("Opcao invalida!"\n);
        break;
    }
}

void consultarSala(Sala *salas, int *qtdSalas)
{
    int i, salaConsultada;

    printf("Estas são as salas cadastradas no sistema: \n");
    for(i=0; i<*qtdSalas; i++){
        printf("%d: %s\n", salas[i].numero, salas[i].nome);
    }

    printf("Digite o numero da sala que deseja consultar: \n");
    scanf("%d", &salaConsultada);

    for(i=0; salas[i].numero != salaConsultada; i++);
    printf("Estas sao as informacoes cadastradas na sala %d\n", salaConsultada);
    printf("Nome: %s\n", salas[i].nome);
    if(salas[i].horario==1){
        printf("Horário: Período da Manhã (9:00 - 12:00)\n");
    } else {
        if(salas[i].horario==2){
            printf("Horário: Período da Tarde (14:00 - 17:00)\n");
        } else {
            if(salas[i].horario==3){
                printf("Horário: Período da Noite (18:00 - 21:00)\n");
            }
        }
    }
    
}