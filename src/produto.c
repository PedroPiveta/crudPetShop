#include <stdio.h>
#include <stdlib.h>
#include "../include/produto.h"

LISTA_produto *criarListaProduto()
{
    LISTA_produto *inicio = (LISTA_produto *)malloc(sizeof(LISTA_produto));
    if (inicio != NULL)
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

void cadastrarProduto(LISTA_produto *lista)
{
    nodeProduto *novo = (nodeProduto *)malloc(sizeof(nodeProduto));
    if (novo == NULL)
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }

    printf("Informe o ID do novo produto: ");
    scanf("%d", &novo->produto_id);
    printf("Informe o nome do produto: ");
    scanf("%s", novo->nome);

    printf("Informe a categoria do novo produto: ");
    scanf("%s", novo->categoria);
    printf("Informe a descricao do novo produto: ");
    scanf("%s", novo->descricao);
    printf("Informe o preco do novo produto: ");
    scanf("%f", &novo->preco_unitario);
    printf("Informe quantdescricao do estoque do novo produto: ");
    scanf("%d", &novo->quantidade_em_estoque);
    printf("Informe o fornecedor do novo produto: ");
    scanf("%s", novo->fornecedor);

    nodeProduto *tmp;
    tmp = (*lista);

    while (tmp != NULL)
    {
        if (tmp->produto_id == novo->produto_id)
        {
            printf("\nNao foi possivel cadastrar o produto pois ja existe um produto com este ID!!!\n");
            free(novo);
            system("pause");
            return;
        }
        tmp = tmp->prox;
    }

    tmp = (*lista);
    novo->prox = NULL;

    if ((*lista) == NULL)
    {
        *lista = novo;
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

    printf("\nProduto cadastrado com sucesso!!\n");
    system("pause");
}

void buscarProduto(LISTA_produto *lista)
{
    int produto_id;
    printf("Informe o ID do produto que deseja buscar: ");
    scanf("%d", &produto_id);

    nodeProduto *tmp = *lista;

    while (tmp != NULL)
    {
        if (tmp->produto_id == produto_id)
        {
            system("cls");
            printf("Produto encontrado!\n\n");
            printf("ID: %d\n", tmp->produto_id);
            printf("Nome: %s\n", tmp->nome);
            printf("categoria: %s\n", tmp->categoria);
            printf("descricao: %s\n", tmp->descricao);
            printf("preco: %f\n", tmp->preco_unitario);
            printf("quantidade em estoque: %d\n", tmp->quantidade_em_estoque);
            printf("fornecedor: %s\n", tmp->fornecedor);
            printf("\n\n");
            system("pause");
            return;
        }
        tmp = tmp->prox;
    }
    printf("Produto com ID %d nao encontrado na lista.\n\n", produto_id);
    system("pause");
}

void editarProduto(LISTA_produto *lista)
{
    int produto_id;
    printf("Informe o ID do produto que deseja editar: ");
    scanf("%d", &produto_id);

    nodeProduto *tmp = *lista;

    while (tmp != NULL)
    {
        if (tmp->produto_id == produto_id)
        {
            system("cls");
            printf("ID: %d\n", tmp->produto_id);
            printf("Nome: %s\n", tmp->nome);
            printf("Categoria: %s\n", tmp->categoria);
            printf("Descricao: %s\n", tmp->descricao);
            printf("Preco unitario: %f\n", tmp->preco_unitario);
            printf("Quantidade em estoque: %d\n", tmp->quantidade_em_estoque);
            printf("Fornecedor: %s\n", tmp->fornecedor);
            printf("\n\n");
            printf("Qual informação deseja alterar?\n");
            printf("1 - Nome\n");
            printf("2 - Categoria\n");
            printf("3 - Descricao\n");
            printf("4 - Preco unitario\n");
            printf("5 - Quantidade em estoque\n");
            printf("6 - Fornecedor\n");
            printf("7 - Todas\n");
            printf("8 - Sair\n");
            printf("Digite a opcao desejada: ");
            int opcao;
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Informe o novo nome: ");
                scanf("%s", tmp->nome);
                break;
            case 2:
                printf("Informe a nova categoria: ");
                scanf("%s", tmp->categoria);
                break;
            case 3:
                printf("Informe a nova descricao: ");
                scanf("%s", tmp->descricao);
                break;
            case 4:
                printf("Informe o novo preco unitario: ");
                scanf("%f", &tmp->preco_unitario);
                break;
            case 5:
                printf("Informe a nova quantidade em estoque: ");
                scanf("%d", &tmp->quantidade_em_estoque);
                break;
            case 6:
                printf("Informe o novo fornecedor: ");
                scanf("%s", tmp->fornecedor);
                break;
            case 7:
                printf("Informe o novo nome: ");
                scanf("%s", tmp->nome);
                printf("Informe a nova categoria: ");
                scanf("%s", tmp->categoria);
                printf("Informe a nova descricao: ");
                scanf("%s", tmp->descricao);
                printf("Informe o novo preco unitario: ");
                scanf("%f", &tmp->preco_unitario);
                printf("Informe a nova quantidade em estoque: ");
                scanf("%d", &tmp->quantidade_em_estoque);
                printf("Informe o novo fornecedor: ");
                scanf("%s", tmp->fornecedor);
                break;
            case 8:
                return;
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
            printf("\nProduto editado com sucesso!!\n");
        }
        tmp = tmp->prox;
    }
    system("pause");
}

void listarProdutos(LISTA_produto *lista)
{
    nodeProduto *tmp = *lista;

    if (tmp == NULL)
    {
        printf("Nao ha nenhum cadastro!\n\n");
    }
    while (tmp != NULL)
    {
        printf("ID: %d\n", tmp->produto_id);
        printf("Nome: %s\n", tmp->nome);
        printf("categoria: %s\n", tmp->categoria);
        printf("descricao: %s\n", tmp->descricao);
        printf("preco: %f\n", tmp->preco_unitario);
        printf("quantidade em estoque: %d\n", tmp->quantidade_em_estoque);
        printf("fornecedor: %s\n", tmp->fornecedor);
        printf("\n\n");
        tmp = tmp->prox;
    }
    system("pause");
}

void excluirProduto(LISTA_produto *lista)
{
    int produto_id;

    printf("Informe o ID do produto a ser excluido: ");
    scanf("%d", &produto_id);

    nodeProduto *tmp = *lista;

    while (tmp != NULL && produto_id != tmp->produto_id)
    {
        tmp = tmp->prox;
    }

    if (tmp == NULL)
    {
        printf("produto com ID %d nao encontrado na lista.\n\n", produto_id);
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

void liberarProduto(LISTA_produto *lista)
{
    if ((*lista) == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        nodeProduto *tmp;

        while (tmp != NULL)
        {
            tmp = (*lista);
            *lista = tmp->prox;
            free(tmp);
        }
        *lista = NULL;
    }
}

void selectProduto(LISTA_produto *lista)
{
    int op;
    do
    {
        system("cls");
        printf("O que deseja: \n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar produto\n");
        printf("4. Editar produto\n");
        printf("5. Excluir produto\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            system("cls");
            cadastrarProduto(lista);
            break;
        case 2:
            system("cls");
            listarProdutos(lista);
            break;
        case 3:
            system("cls");
            buscarProduto(lista);
            break;
        case 4:
            system("cls");
            editarProduto(lista);
            break;
        case 5:
            system("cls");
            excluirProduto(lista);
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    while(op != 0);
}
