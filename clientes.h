#ifndef _CLIENTES_H
#define _CLIENTES_H
#include "types.h"


void CadastrarCliente(Cliente *, int *);
void AlterarCliente(Cliente *, int *,int *);
void ExcluirCliente(Cliente *, int *, int *, int *);
void TelaAlterar(Cliente *);
void ConsultarCliente(Cliente *, int *, int *);
void LimparEspacoVazio(Cliente *);
void CalcularMensalidade(Cliente *, int *);
int PesquisarCodigo(Cliente *, int, int);
int PesquisarIndiceVazio(Cliente *);
int ExisteCodigo(Cliente *, int, int);
int MenuAlterarCliente();

#endif
