#ifndef SERVICOS_H_INCLUDED
#define SERVICOS_H_INCLUDED
#include "pet.h"

struct NodeServico
{
    int servico_id;
    char descricao[50];
    float tempo;
    float valor;
    struct NodePet *pet;
    struct NodeServico *prox;
    struct NodeServico *ant;
};

typedef struct NodeServico nodeServico;
typedef nodeServico* LISTA_SERVICO;

LISTA_SERVICO* criarListaServicos();

void selectServico(LISTA_pet* lista, LISTA_SERVICO* listas);

void insereServicoNoPet(LISTA_SERVICO* listas, struct NodePet *pett);
void insereServico(LISTA_SERVICO* listas, LISTA_pet* lista);
void verHistorico(LISTA_SERVICO* listas);
void liberarServicos(LISTA_SERVICO* listas);

#endif
