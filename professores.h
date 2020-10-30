#ifndef _PROFESSORES_H
#define _PROFESSORES_H

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

void TelaMenuProfessor();
void cadastrarProfessor(Professor*, int*);
void alterarInfoProfessor(Professor*, int*);
void exclusirProfessor(Professor*, int*);
void consultarProfessor(Professor*, int*);

#endif
