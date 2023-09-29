#include <stdio.h>
#include "../include/servicos.h"
#include "../include/pet.h"

void selectServico(LISTA_pet* lista, LISTA_SERVICO* listas)
{
    int op;
    do
    {
        system("cls");
        printf("=== SERVICOS ===\n\n");
        printf("1 - Inserir serico\n");
        printf("2 - Ver historico de servicos\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            insereServico(listas, lista);
            break;
        case 2:
            verHistorico(listas);
            break;
        }
    }
    while(op != 0);

    if(op == 0)
    {
        printf("voltando...");
        return 0;
    }

}


LISTA_SERVICO* criarListaServicos()
{
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

void insereServico(LISTA_SERVICO* listas, LISTA_pet* lista)
{
    int op, pet_id, teste;

    nodeServico *novo = (nodeServico*) malloc(sizeof(nodeServico));
    if (novo == NULL)
    {
        printf("Erro de alocacao para novo...\n");
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
    printf("Informe o ID do pet: ");
    scanf("%d", &pet_id);

    nodePet *tmp_pet = *lista;

    while (tmp_pet != NULL)
    {
        if (tmp_pet->pet_id == pet_id)
        {
            novo->pet->pet_id = tmp_pet->pet_id;
            strcpy(novo->pet->nome, tmp_pet->nome);
            strcpy(novo->pet->especie, tmp_pet->especie);
            novo->pet->idade = tmp_pet->idade;
            novo->pet->genero = tmp_pet->genero;
            strcpy(novo->pet->cor, tmp_pet->cor);
            teste++;
        }
        printf("\nPet encontado com sucesso!");

        printf("\n\nQue servico foi prestado: \n");
        printf("1 - Banho \n");
        printf("2 - Tosa \n");
        printf("3 - Consulta veterinaria \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            novo->servico_id = 1;
            strcpy(novo->descricao, "Banho");
            break;
        case 2:
            novo->servico_id = 2;
            strcpy(novo->descricao, "Tosa");
            break;
        case 3:
            novo->servico_id = 3;
            strcpy(novo->descricao, "Consulta veterinaria");
            break;
        default:
            printf("Opcao invalida\n");
            free(novo->pet);
            free(novo);
            return;
        }

        printf("\nInforme o tempo de execucao do servico em minutos: ");
        scanf("%f", &novo->tempo);
        printf("Informe o custo do servico em reais: ");
        scanf("%f", &novo->valor);

        novo->prox = NULL;
        nodeServico *tmp = *listas;

        if ((*listas) == NULL)
        {
            *listas = novo;
            novo->ant = NULL;
        }
        else
        {

            while (tmp->prox != NULL)
            {
                tmp = tmp->prox;
            }
            tmp->prox = novo;
            novo->ant = tmp;
        }

        printf("\n\nServico cadastrado com sucesso!\n\n");
        break;
    }
}

void verHistorico(LISTA_SERVICO* listas)
{
    nodeServico *tmp = (*listas);
    int op = 1;

    if(tmp == NULL)
    {
        printf("Nao ha nenhum cadastro!\n\n");
    }
    while(op) {
        while (tmp != NULL)
        {
            printf("\nSERVICO\n");
            printf("Servico id: %d\n", tmp->servico_id);
            printf("Descricao: %s\n", tmp->descricao);
            printf("Tempo: %.2f\n", tmp->tempo);
            printf("Valor: %.2f\n", tmp->valor);
            printf("\nPET\n");
            printf("Pet id: %d\n", tmp->pet->pet_id);
            printf("Pet nome: %s\n", tmp->pet->nome);
            printf("Pet especie: %s\n", tmp->pet->especie);
            printf("Pet idade: %d\n", tmp->pet->idade);
            printf("Pet genero: %c\n", tmp->pet->genero);
            printf("Pet cor: %s\n", tmp->pet->cor);

            printf("\n");
            tmp = tmp->prox;
        } printf("Pressione 0 para sair...\n");
        scanf("%d", &op);
    }
}

void liberarServicos(LISTA_SERVICO* listas)
{
    if((*listas) == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        nodeServico *tmp;

        while (tmp != NULL)
        {
            tmp = (*listas);
            *listas = tmp->prox;
            free(tmp);
        }
        *listas = NULL;
    }
}
void insereServicoNoPet(LISTA_SERVICO* listas, struct NodePet *pett)
{
    nodeServico *novo = (nodeServico*) malloc(sizeof(nodeServico));
    if (novo == NULL)
    {
        printf("Erro de alocacao para novo...\n");
        exit(0);
    }

    novo->pet = (nodePet*) malloc(sizeof(nodePet));
    if (novo->pet == NULL)
    {
        printf("Erro de alocacao para novo->pet...\n");
        free(novo);
        exit(0);
    }

    int op;

    printf("Que servico foi prestado: \n");
    printf("1 - Banho \n");
    printf("2 - Tosa \n");
    printf("3 - Consulta veterinaria \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        novo->servico_id = 1;
        strcpy(novo->descricao, "Banho");
        break;
    case 2:
        novo->servico_id = 2;
        strcpy(novo->descricao, "Tosa");
        break;
    case 3:
        novo->servico_id = 3;
        strcpy(novo->descricao, "Consulta veterinaria");
        break;
    default:
        printf("Opcao invalida\n");
        free(novo->pet);
        free(novo);
        return;
    }

    printf("\nInforme o tempo de execucao do servico em minutos: ");
    scanf("%f", &novo->tempo);
    printf("Informe o custo do servico em reais: ");
    scanf("%f", &novo->valor);

    novo->pet->pet_id = pett->pet_id;
    strcpy(novo->pet->nome, pett->nome);
    strcpy(novo->pet->especie, pett->especie);
    novo->pet->idade = pett->idade;
    novo->pet->genero = pett->genero;
    strcpy(novo->pet->cor, pett->cor);

    novo->prox = NULL;
    nodeServico *tmp = *listas;

    if ((*listas) == NULL)
    {
        *listas = novo;
        novo->ant = NULL;
    }
    else
    {

        while (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }

    printf("\n\nServico cadastrado com sucesso!\n\n");
}