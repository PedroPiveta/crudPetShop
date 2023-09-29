#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "../include/arquivarListas.h"

void salvarClientes(LISTA_cliente *listaClientes) {
    FILE *arquivoClientes = fopen("clientes.txt", "a");
    // arquivo = fopen("clientes.txt", "a");
    if(!arquivoClientes){
        printf("\nDeu ruim\n");
        system("pause");
    } 

    nodeCliente *tmp = *listaClientes;
    printf("%s \n", tmp->nome);

    if (arquivoClientes) {
        while(tmp != NULL) {
            fprintf(arquivoClientes, "id: %d\n", tmp->cliente_id);
            fprintf(arquivoClientes, "nome: %s\n", tmp->nome);
            fprintf(arquivoClientes, "cpf: %s\n", tmp->cpf);
            fprintf(arquivoClientes, "endereco: %s\n", tmp->endereco);
            
            tmp = tmp->prox;
        }
        fclose(arquivoClientes);
    } else {
        printf("Erro ao salvar clientes!\n");
    }
}

void salvarPets(LISTA_pet *listaPets) {
    FILE *arquivoPets = fopen("pets.txt", "a");
    if(!arquivoPets){
        printf("\nErro ao abrir arquivo de pets\n");
        return;
    } 

    nodePet *tmp = *listaPets;
    if (tmp == NULL) {
        printf("Lista de pets vazia\n");
        fclose(arquivoPets);
        return;
    }

    while(tmp != NULL) {
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

void salvarProdutos(LISTA_produto *listaProdutos) {
    FILE *arquivoProdutos = fopen("produtos.txt", "a");
    if(!arquivoProdutos){
        printf("\nErro ao abrir arquivo de produtos\n");
        return;
    } 

    nodeProduto *tmp = *listaProdutos;
    if (tmp == NULL) {
        printf("Lista de produtos vazia\n");
        fclose(arquivoProdutos);
        return;
    }

    while(tmp != NULL) {
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

void salvarServicos(LISTA_SERVICO *listaServicos) {
    FILE *arquivoServicos = fopen("servicos.txt", "a");
    if(!arquivoServicos){
        printf("\nErro ao abrir arquivo de servicos\n");
        return;
    } 

    nodeServico *tmp = *listaServicos;
    if (tmp == NULL) {
        printf("Lista de servicos vazia\n");
        fclose(arquivoServicos);
        return;
    }

    while(tmp != NULL) {
        fprintf(arquivoServicos, "id: %d\n", tmp->servico_id);
        fprintf(arquivoServicos, "descricao: %s\n", tmp->descricao);
        fprintf(arquivoServicos, "tempo: %.2f\n", tmp->tempo);
        fprintf(arquivoServicos, "valor: %.2f\n", tmp->valor);
        tmp = tmp->prox;
    }
    fclose(arquivoServicos);
}