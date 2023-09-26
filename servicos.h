#ifndef SERVICOS_H_INCLUDED
#define SERVICOS_H_INCLUDED
#include "pet.h"

struct NodeS {
    int servico_id;
    char descricao[50];
    float tempo;
    float valor;
    struct NodePet *pet;
    struct NodeS *prox;
    struct NodeS *ant;
};

typedef struct NodeS nodeS;
typedef nodeS *LISTA_SERVICO;

LISTA_SERVICO* criarListaServicos();
void insereBanho(LISTA_SERVICO* lista, nodePet *pett);
void inserTosa(LISTA_SERVICO* lista);
void insereConsulta(LISTA_SERVICO* lista);
void verHistorico(LISTA_SERVICO* lista);

#endif
