#ifndef TYPES_H
#define TYPES_H

typedef struct
{
    char nome[255];
	char nomeResponsavel[255];
    int codigo;
    int *modalidade;
    int idade;
    char localDeNascimento[255];
    char RG[16];
    char CPF[12];
    char endereco[255];
    int valorMensalidade;
    char dataVencimentoBoleto[11];
    int responsavel;
    int qntModalidades;
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
    int codigo; //codigo da modalidade para consultas 
    char descModalidade[200]; //descricao da modalidade (classico, contemporaneo, feito em grupos, etc)
    char descMateriais[200]; //descricao dos materiais necessários (roupas, sapatos, objetos como barra, etc)
    float valorMensalidade; //valor da mensalidade da modalidade
    int idade; //idade mínima para fazer a modalidade 
} Modalidade;

typedef struct salas{
    char nome[100]; //nome de identificacao da sala (baby, kid, teen, etc)
    int numero; //numero de identificacao da sala (1, 2, 3, etc)
    int diaSemana; //1- domingo; 2- segunda; 3- terca; assim por diante
    int horario; //0: manha (9:00 - 12:00); 1: tarde (14:00 - 17:00); 2: noite (18:00 - 21:00)
    int matrizHorarios[3][7]; //0: disponivel; 1: indisponivel;
}Sala;


#endif
