#include <stdio.h>
#include <stdlib.h>
#include "../include/cliente.h"

LISTA_cliente* criarListaClientes()
{
    LISTA_cliente *inicio = (LISTA_cliente *) malloc (sizeof(LISTA_cliente));
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

void cadastrarCliente(LISTA_cliente* lista)
{
    nodeCliente *novo = (nodeCliente*) malloc (sizeof(nodeCliente));
    if(novo == NULL)
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }

    nodeCliente *tmp;
    tmp = (*lista);

    while(tmp != NULL){
        if(tmp->cliente_id == novo->cliente_id){
            printf("\nNao foi possivel cadastrar o cliente pois ja existe um cliente com este ID!!!\n");
            free(novo);
            system("pause");
            return 1;
        }
        tmp= tmp->prox;
    }

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

    printf("Informe o ID do novo cliente: ");
    scanf("%d", &novo->cliente_id);
    printf("Informe o nome do novo cliente: ");
    scanf("%s", &novo->nome);
    printf("Informe o cpf do novo cliente: ");
    scanf("%s", &novo->cpf);
    printf("Informe o endereco do novo cliente: ");
    scanf("%s", &novo->endereco);

    printf("\ncliente cadastrado com sucesso!!\n");
    system("pause");
}

void buscarCliente(LISTA_cliente* lista)
{
    int cliente_id, op;
    printf("Informe o ID do cliente que deseja visualizar: ");
    scanf("%d", &cliente_id);

    nodeCliente *tmp = *lista;

    while (tmp != NULL) {
        if (tmp->cliente_id == cliente_id) {
            // system("cls");
            // printf("ID: %d\n", tmp->cliente_id);
            // printf("Nome: %s\n", tmp->nome);
            // printf("Especie: %s\n", tmp->especie);
            // printf("Idade: %d\n", tmp->idade);
            // printf("Genero: %c\n", tmp->genero);
            // printf("Cor: %s\n", tmp->cor);
            // printf("Dono ID: %d\n\n", tmp->dono_id);

            printf("1 - Editar cliente\n");
            printf("2 - Inserir Servico\n");
            printf("3 - Ver historico de servicos\n");
            printf("0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    // system("cls");
                    // printf("Editando cliente...\n\n");
                    // printf("Novo ID: ");
                    // scanf("%d", &tmp->cliente_id);
                    // printf("Novo nome: ");
                    // scanf("%s", tmp->nome);
                    // printf("Nova especie: ");
                    // scanf("%s", tmp->especie);
                    // printf("Nova idade: ");
                    // scanf("%d", &tmp->idade);
                    // printf("Novo genero: ");
                    // scanf(" %c", &tmp->genero); // Use espa�o para evitar quebras de linha anteriores
                    // printf("Nova cor: ");
                    // scanf("%s", tmp->cor);
                    // printf("\n\n");
                    // printf("Os dados foram atualizados!\n\n");
                    // system("pause");
                    break;
                case 2:
                    break;
                case 3:
                    //verHistorico(); // Chame verHistorico com o par�metro correto
                    break;
                case 0:
                    return; // Saia da fun��o sem retornar um valor
                default:
                    printf("Opcao invalida\n");
            }
        } else {
            printf("cliente nao encontrado!\n\n");
            system("pause");
            return; // Saia da fun��o sem retornar um valor
        }

        tmp = tmp->prox; // Mova o ponteiro para o pr�ximo n� dentro do loop
    }

    system("pause");
}

void editarCliente(LISTA_cliente* lista)
{
    int cliente_id;
    printf("Informe o ID do cliente que deseja editar: ");
    scanf("%d", &cliente_id);

    nodeCliente *tmp = *lista;

    while (tmp != NULL)
    {
        if (tmp->cliente_id == cliente_id)
        {
            system("cls");
            printf("Editando cliente...\n\n");
            // printf("Novo ID: %d\n", tmp->cliente_id);
            // printf("Novo nome: %s\n", tmp->nome);
            // printf("Nova especie: %s\n", tmp->especie);
            // printf("Nova idade: %d\n", tmp->idade);
            // printf("Novo genero: %c\n", tmp->genero);
            // printf("Nova cor: %s\n", tmp->cor);
            printf("\n\n");
            printf("Os dados foram atualizados!");
        }
        tmp = tmp->prox;

    }
    system("pause");
}

void listarCliente(LISTA_cliente* lista)
{
    nodeCliente *tmp = *lista;

    if(tmp == NULL){
        printf("Nao ha nenhum cadastro!\n\n");
    }
    while (tmp != NULL)
    {
        printf("ID: %d\n", tmp->cliente_id);
        printf("Nome: %s\n", tmp->nome);
        // printf("Especie: %s\n", tmp->especie);
        // printf("Idade: %d\n", tmp->idade);
        // printf("Genero: %c\n", tmp->genero);
        // printf("Cor: %s\n", tmp->cor);
        // printf("Dono ID: %d\n", tmp->dono_id);
        printf("\n\n");
        tmp = tmp->prox;
    }
    system("pause");
}

// void verHistoricoServicos(LISTA* lista) {
//     // Implementar a l�gica para ver o hist�rico de servi�os de um cliente
// }

void excluirCliente(LISTA_cliente* lista)
{
    int cliente_id;

    printf("Informe o ID do cliente a ser excluido: ");
    scanf("%d", &cliente_id);

    nodeCliente *tmp = *lista;

    while (tmp != NULL && cliente_id != tmp->cliente_id)
    {
        tmp = tmp->prox;
    }

    if (tmp == NULL)
    {
        printf("cliente com ID %d nao encontrado na lista.\n\n", cliente_id);
        system("pause");
        return;
    }

    if (tmp->ant == NULL)
    {
        *lista = tmp->prox;
        if (tmp->prox != NULL)
        {
            tmp->prox->ant = NULL;
        }
    }
    else
    {
        tmp->ant->prox = tmp->prox;
        if (tmp->prox != NULL)
        {
            tmp->prox->ant = tmp->ant;
        }
    }
    free(tmp);

    printf("Elemento removido com sucesso.\n\n");
    system("pause");
}

void liberarCliente(LISTA_cliente* lista)
{
    if((*lista) == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        nodeCliente *tmp;

        while (tmp != NULL)
        {
            tmp = (*lista);
            *lista = tmp->prox;
            free(tmp);
        }
        *lista = NULL;
    }
}

void selectCliente() {
    LISTA_cliente lista = criarListaClientes();
    int op;
    do
    {
        system("cls");
        printf("O que deseja: \n");
        printf("1 - Cadastrar um novo cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - buscar cliente\n");
        printf("4 - Excluir um cliente\n");
        printf("5 - Listar servicos\n");
        printf("0 - Voltar\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            system("cls");
            cadastrarCliente(lista);
            break;
        case 2:
            system("cls");
            listarCliente(lista);
            break;
        case 3:
            system("cls");
            buscarCliente(lista);
            break;
        case 4:
            system("cls");
            excluirCliente(lista);
            break;
        case 5:
            system("cls");
            editarCliente(lista);
            break;
        case 6:
            system("cls");
            liberarCliente(lista);
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    while(op != 0);
}
