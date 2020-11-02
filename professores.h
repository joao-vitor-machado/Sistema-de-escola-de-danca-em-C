#ifndef _PROFESSORES_H
#define _PROFESSORES_H
#include "types.h"


void TelaMenuProfessor(Professor *, int *, Sala *, int *, Modalidade *);
void cadastrarProfessor(Professor *, int *, Sala *, int *, int *, Modalidade *);
void alterarInfoProfessor(Professor *, int *, Sala *, int *, int *, Modalidade *);
void exclusirProfessor(Professor *, int *);
void consultarProfessor(Professor *, int *);

#endif

