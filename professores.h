#ifndef _PROFESSORES_H
#define _PROFESSORES_H

typedef struct professores{
    int codigoProfessor;
    char nome[100];
    int modalidadeLecionada;
    char localNascimento[100], dataDeNascimento[10];
    int RG;
    int CPF = 0;
    int CNPJ = 0;
    char endereco[100];
    float salarioPorAluno;
    int salaUsada;
    int diaSemana;
    int periodoDia;    
}Professor;

void TelaMenuProfessor();
void cadastrarProfessor(Professor*, int*);
void alterarInfoProfessor(Professor*, int*);
void exclusirProfessor(Professor*, int*);
void consultarProfessor(Professor*, int*);

#endif