#include <stdio.h>
#include "servicos.h"
#include "pet.h"


LISTA_SERVICO* criarListaServicos(){
    LISTA_SERVICO *inicio = (LISTA_SERVICO *) malloc (sizeof(LISTA_SERVICO));
    if(inicio != NULL)
    {
        *inicio = NULL;
    }
    else
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }
    return inicio;
}

void insereBanho(LISTA_SERVICO* lista, nodePet *pett) {
    nodeS *novo = (nodeS*) malloc(sizeof(nodeS));
    if (novo == NULL) {
        printf("Erro de alocacao para novo...\n");
        exit(0);
    }

    novo->pet = (nodePet*) malloc(sizeof(nodePet));
    if (novo->pet == NULL) {
        printf("Erro de alocacao para novo->pet...\n");
        free(novo);
        exit(0);
    }

    system("cls");
    printf("1 - Banho");

    novo->servico_id = 1;
    strcpy(novo->descricao, "Banho");
    printf("\nInforme o tempo de execucao do servico em minutos: ");
    scanf("%f", &novo->tempo);
    printf("Informe o custo do servico em reais: ");
    scanf("%f", &novo->valor);

    if (pett == NULL) {
        printf("Erro: pet nao alocado...\n");
        free(novo->pet);
        free(novo);
        exit(0);
    }

    //importante
    novo->pet->pet_id = pett->pet_id;
    printf("%d", novo->pet->pet_id);

    novo->prox = NULL;

    if ((*lista) == NULL) {
        *lista = novo;
        novo->ant = NULL;
    } else {
        nodeS *tmp = *lista;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }
}

void insereTosa(LISTA_SERVICO* lista ){

    nodeS *novo = (nodeS*) malloc (sizeof(nodeS));
    if (novo == NULL)
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }

    novo->pet = (nodePet*) malloc(sizeof(nodePet));
    if (novo->pet == NULL)
    {
        printf("Erro de alocacao para novo->pet...\n");
        free(novo);
        exit(0);
    }
    system("cls");
    printf("2 - Tosa");

    novo->servico_id = 2;
    strcpy(novo->descricao, "Tosa");
    printf("\nInforme o tempo de execucao do servico em minutos: ");
    scanf("%f", &novo->tempo);
    printf("Informe o custo do servico em reais: ");
    scanf("%f", &novo->valor);

    novo->pet->pet_id = 1;

    nodeS *tmp;
    tmp = (*lista);
    novo->prox = NULL;

    if((*lista) == NULL)
    {
        *lista = novo;
        novo->ant = NULL;
    }
    else
    {
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }
    return 1;
}

void insereConsulta(LISTA_SERVICO* lista ){

    nodeS *novo = (nodeS*) malloc (sizeof(nodeS));
    if (novo == NULL)
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }

    novo->pet = (nodePet*) malloc(sizeof(nodePet));
    if (novo->pet == NULL)
    {
        printf("Erro de alocacao para novo->pet...\n");
        free(novo);
        exit(0);
    }
    system("cls");
    printf("3 - Consulta");

    novo->servico_id = 3;
    strcpy(novo->descricao, "Consulta");
    printf("\nInforme o tempo de execucao do servico em minutos: ");
    scanf("%f", &novo->tempo);
    printf("Informe o custo do servico em reais: ");
    scanf("%f", &novo->valor);

    novo->pet->pet_id = 1;

    nodeS *tmp;
    tmp = (*lista);
    novo->prox = NULL;

    if((*lista) == NULL)
    {
        *lista = novo;
        novo->ant = NULL;
    }
    else
    {
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }
    return 1;
}

void verHistorico(LISTA_SERVICO* lista){
    nodeS *tmp = *lista;

    if(tmp == NULL){
        printf("Nao ha nenhum cadastro!\n\n");
    }
    while (tmp != NULL)
    {
        printf("ID: %d\n", tmp->servico_id);
        printf("Nome: %s\n", tmp->descricao);
        printf("Especie: %f\n", tmp->tempo);
        printf("Idade: %f\n", tmp->valor);
    }
    system("pause");
}
