#ifndef _CLIENTES_H
#define _CLIENTES_H
#include "types.h"



void CadastrarCliente(Cliente *, int *);
void AlterarCliente(Cliente *, int *);
void ExcluirCliente(Cliente *, int *, int *);
void ConsultarCliente(Cliente *, int *);
void LimparEspacoVazio(Cliente *);
void CalcularMensalidade(Cliente *, int *);
int PesquisarCodigo(Cliente *, int);
int PesquisarIndiceVazio(Cliente *);

#endif
