#ifndef _PROFESSORES_H
#define _PROFESSORES_H
#include "types.h"


void TelaMenuProfessor();
void cadastrarProfessor(Professor *, int *, Sala *, int *, Modalidade *, int *);
void alterarInfoProfessor(Professor *, int *, Sala *, int *, int *, Modalidade *, int *);
void exclusirProfessor(Professor *, int *);
void consultarProfessor(Professor *, int *);

#endif

