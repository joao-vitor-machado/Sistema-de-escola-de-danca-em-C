#ifndef _CLIENTES_H
#define _CLIENTES_H

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

void CadastrarCliente(Cliente *, int *);
void AlterarCliente(Cliente *, int *);
void ExcluirCliente(Cliente *, int *, int *);
void ConsultarCliente(Cliente *, int *);
void LimparEspacoVazio(Cliente *, int);
void CalcularMensalidade(Cliente *, int, int *);
int PesquisarCodigo(Cliente *, int);
int PesquisarIndiceVazio(Cliente *);

#endif