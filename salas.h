#ifndef _SALAS_H
#define _SALAS_H

typedef struct salas{
    char nome[100]; //nome de identificação da sala (baby, kid, teen, etc)
    int numero; //número de identificação da sala (1, 2, 3, etc)
    int diaSemana; //1- domingo; 2- segunda; 3- terça; assim por diante
    int horario; //0: manhã (9:00 - 12:00); 1: tarde (14:00 - 17:00); 2: noite (18:00 - 21:00)
}Sala;

void cadastrarSala(Sala*);
void excluirSala(Sala*);
void alterarSala(Sala*);
void consultarSala(Sala*);

#endif // _SALAS_H