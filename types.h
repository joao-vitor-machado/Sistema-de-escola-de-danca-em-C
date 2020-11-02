#ifndef TYPES_H
#define TYPES_H

typedef struct
{
    char nome[255], nomeResponsavel[255];
    int codigo;
    int *modalidade;
    int idade;
    char localDeNascimento[255];
    char RG[15];
    char CPF[11];
    char endereco[255];
    int valorMensalidade;
    int dataVencimentoBoleto[10];
    int responsavel;
} Cliente;

typedef struct professores{
    int codigoProfessor;
    char nome[255];
    int modalidadeLecionada;
    char localDeNascimento[255], dataDeNascimento[10];
    int RG;
    int CPF;
    int CNPJ;
    char endereco[255];
    float salarioPorAluno;
    int salaUsada;
    int diaSemana;
    int periodoDia;    
}Professor;

typedef struct modalidades{
    char nome[100]; //nome da modalidade (ballet, jazz, sapateado, etc)
    int codigo; //código da modalidade para consultas 
    char descModalidade[200]; //descrição da modalidade (clássico, contemporâneo, feito em grupos, etc)
    char descMateriais[200]; //descrição dos materiais necessários (roupas, sapatos, objetos como barra, etc)
    float valorMensalidade; //valor da mensalidade da modalidade
    int idade; //idade mínima para fazer a modalidade 
    char nomeProfessor[100]; //professor que lecionará a aula
    int sala; //sala onde será lecionada a aula
} Modalidade;

typedef struct salas{
    char nome[100]; //nome de identificação da sala (baby, kid, teen, etc)
    int numero; //número de identificação da sala (1, 2, 3, etc)
    int diaSemana; //1- domingo; 2- segunda; 3- terça; assim por diante
    int horario; //0: manhã (9:00 - 12:00); 1: tarde (14:00 - 17:00); 2: noite (18:00 - 21:00)
    int matrizHorarios[3][7]; //0: disponível; 1: indisponível;
}Sala;


#endif
