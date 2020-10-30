#ifndef _MODALIDADES_H
#define _MODALIDADES_H

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

void cadastrarModalidade(Modalidade*, int*);
void excluirModalidade(Modalidade*, int*);
void alterarModalidade(Modalidade*);
void consultarModalidade(Modalidade*, int*);

#endif // _MODALIDADES_H