#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/arquivarListas.h"

/*-------------------------  SAÍDA DE DADOS  ------------------------------*/

void salvarClientes(LISTA_cliente *listaClientes)
{
    FILE *arquivoClientes = fopen("clientes.txt", "a");
    if (!arquivoClientes)
    {
        printf("\nDeu ruim\n");
        system("pause");
    }

    nodeCliente *tmp = *listaClientes;
    printf("%s \n", tmp->nome);

    if (arquivoClientes)
    {
        while (tmp != NULL)
        {
            fprintf(arquivoClientes, "id: %d\n", tmp->cliente_id);
            fprintf(arquivoClientes, "nome: %s\n", tmp->nome);
            fprintf(arquivoClientes, "cpf: %s\n", tmp->cpf);
            fprintf(arquivoClientes, "endereco: %s\n", tmp->endereco);
            system("pause");

            tmp = tmp->prox;
        }
        fclose(arquivoClientes);
    }
    else
    {
        printf("Erro ao salvar clientes!\n");
    }
}

void salvarPets(LISTA_pet *listaPets)
{
    FILE *arquivoPets = fopen("pets.txt", "a");

    if (!arquivoPets)
    {
        printf("\nErro ao abrir arquivo de pets\n");
        return;
    }

    nodePet *tmp = *listaPets;
    if (tmp == NULL)
    {
        printf("Lista de pets vazia\n");
        fclose(arquivoPets);
        return;
    }

    while (tmp != NULL)
    {
        fprintf(arquivoPets, "id: %d\n", tmp->pet_id);
        fprintf(arquivoPets, "nome: %s\n", tmp->nome);
        fprintf(arquivoPets, "especie: %s\n", tmp->especie);
        fprintf(arquivoPets, "idade: %d\n", tmp->idade);
        fprintf(arquivoPets, "genero: %s\n", tmp->genero);
        fprintf(arquivoPets, "cor: %s\n", tmp->cor);
        tmp = tmp->prox;
    }
    fclose(arquivoPets);
}

void salvarProdutos(LISTA_produto *listaProdutos)
{
    FILE *arquivoProdutos = fopen("produtos.txt", "a");
    if (!arquivoProdutos)
    {
        printf("\nErro ao abrir arquivo de produtos\n");
        return;
    }

    nodeProduto *tmp = *listaProdutos;
    if (tmp == NULL)
    {
        printf("Lista de produtos vazia\n");
        fclose(arquivoProdutos);
        return;
    }

    while (tmp != NULL)
    {
        fprintf(arquivoProdutos, "id: %d\n", tmp->produto_id);
        fprintf(arquivoProdutos, "nome: %s\n", tmp->nome);
        fprintf(arquivoProdutos, "categoria: %s\n", tmp->categoria);
        fprintf(arquivoProdutos, "quantidade: %s\n", tmp->descricao);
        fprintf(arquivoProdutos, "preco: %.2f\n", tmp->preco_unitario);
        fprintf(arquivoProdutos, "quantidade: %d\n", tmp->quantidade_em_estoque);
        fprintf(arquivoProdutos, "fornecedor: %s\n", tmp->fornecedor);
        tmp = tmp->prox;
    }
    fclose(arquivoProdutos);
}

void salvarServicos(LISTA_SERVICO *listaServicos)
{
    FILE *arquivoServicos = fopen("servicos.txt", "a");
    if (!arquivoServicos)
    {
        printf("\nErro ao abrir arquivo de servicos\n");
        return;
    }

    nodeServico *tmp = *listaServicos;
    if (tmp == NULL)
    {
        printf("Lista de servicos vazia\n");
        fclose(arquivoServicos);
        return;
    }

    while (tmp != NULL)
    {
        fprintf(arquivoServicos, "id: %d\n", tmp->servico_id);
        fprintf(arquivoServicos, "descricao: %s\n", tmp->descricao);
        fprintf(arquivoServicos, "tempo: %.2f\n", tmp->tempo);
        fprintf(arquivoServicos, "valor: %.2f\n", tmp->valor);
        tmp = tmp->prox;
    }
    fclose(arquivoServicos);
}

/*-------------------------  Entrada de Dados  ------------------------------*/

void lerClienteArquivo(LISTA_cliente *lista)
{

    FILE *arquivoClientes = fopen("clientes.txt", "r");
    if (!arquivoClientes)
    {
        printf("\nDeu ruim\n");
        system("pause");
    }
    while (!feof(arquivoClientes))
    {
        nodeCliente *novo = (nodeCliente *)malloc(sizeof(nodeCliente));
        if (novo == NULL)
        {
            printf("Erro de alocacao...\n");
            exit(0);
        }
        nodeCliente *tmp;
        tmp = (*lista);

        while (tmp != NULL)
        {
            if (tmp->cliente_id == novo->cliente_id)
            {
                printf("\nNao foi possivel cadastrar o cliente pois ja existe um cliente com este ID!!!\n");
                free(novo);
                system("pause");
                return 1;
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

        fgets(novo->cliente_id, sizeof(novo->cliente_id), arquivoClientes);
        fgets(novo->nome, sizeof(novo->nome), arquivoClientes);
        fgets(novo->cpf, sizeof(novo->cpf), arquivoClientes);
        fgets(novo->endereco, sizeof(novo->endereco), arquivoClientes);
    }

    system("pause");
}

void lerClienteArquivo(LISTA_pet *lista)
{

    FILE *arquivoPet = fopen("pets.txt", "r");
    if (!arquivoPet)
    {
        printf("\nDeu ruim\n");
        system("pause");
    }
    while (!feof(arquivoPet))
    {
        nodePet *novo = (nodePet *)malloc(sizeof(nodePet));
        if (novo == NULL)
        {
            printf("Erro de alocacao...\n");
            exit(0);
        }

        fgets(novo->pet_id, sizeof(novo->pet_id), arquivoPet);
        fgets(novo->nome, sizeof(novo->nome), arquivoPet);
        fgets(novo->especie, sizeof(novo->especie), arquivoPet);
        fgets(novo->idade, sizeof(novo->idade), arquivoPet);
        fgets(novo->genero, sizeof(novo->genero), arquivoPet);
        fgets(novo->cor, sizeof(novo->cor), arquivoPet);
        fgets(novo->dono_id, sizeof(novo->dono_id), arquivoPet);

        nodePet *tmp;
        tmp = (*lista);

        while (tmp != NULL)
        {
            if (tmp->pet_id == novo->pet_id)
            {
                printf("\nNao foi possivel cadastrar o pet pois ja existe um pet com este ID!!!\n");
                free(novo);
                system("pause");
                return 1;
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
    }
    system("pause");
}

void lerServicosArquivo(LISTA_SERVICO *lista)
{

    FILE *arquivoServicos = fopen("servicos.txt", "r");
    char auxConverter[10];
    if (!arquivoServicos)
    {
        printf("\nDeu ruim\n");
        system("pause");
    }
    while (!feof(arquivoServicos))
    {
        nodeServico *novo = (nodeServico *)malloc(sizeof(nodeServico));
        if (novo == NULL)
        {
            printf("Erro de alocacao para novo...\n");
            exit(0);
        }
        fgets(novo->servico_id, sizeof(novo->servico_id), arquivoServicos);
        fgets(novo->descricao, sizeof(novo->descricao), arquivoServicos);
        fgets(auxConverter, sizeof(auxConverter), arquivoServicos);
        novo->tempo = atof(auxConverter);
        fgets(auxConverter, sizeof(auxConverter), arquivoServicos);
        novo->valor = atof(auxConverter);

        novo->prox = NULL;
        nodeServico *tmp = *lista;

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
    }
    system("pause");
}

void lerProdutosArquivo(LISTA_produto *lista)
{

    FILE *arquivoProdutos = fopen("produtos.txt", "r");
    char auxConverter[10];
    if (!arquivoProdutos)
    {
        printf("\nDeu ruim\n");
        system("pause");
    }
    while (!feof(arquivoProdutos))
    {
        nodeProduto *novo = (nodeProduto *)malloc(sizeof(nodeProduto));
        if (novo == NULL)
        {
            printf("Erro de alocacao...\n");
            exit(0);
        }

        fgets(novo->produto_id, sizeof(novo->produto_id), arquivoProdutos);
        fgets(novo->nome, sizeof(novo->nome), arquivoProdutos);
        fgets(novo->categoria, sizeof(novo->categoria), arquivoProdutos);
        fgets(novo->descricao, sizeof(novo->descricao), arquivoProdutos);
        
        fgets(auxConverter, sizeof(auxConverter), arquivoProdutos);
        novo->preco_unitario = atof(auxConverter);

        fgets(novo->quantidade_em_estoque, sizeof(novo->quantidade_em_estoque), arquivoProdutos);
        fgets(novo->fornecedor, sizeof(novo->fornecedor), arquivoProdutos);

        nodeProduto *tmp;
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
    }
    system("pause");
}
