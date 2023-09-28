#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "pet.c"
#include "servicos.c"
#include "cliente.c"

void arquivarListaClientes(LISTA_cliente* listaClientes) {
    // Abre o arquivo em modo de escrita
    FILE* arquivo = fopen("output/clientes.txt", "w");
    nodeCliente *tmp = (*listaClientes);

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve os elementos no arquivo
    while (tmp != NULL) {
        fprintf(arquivo, "|-------------------------------------------------|");
        fprintf(arquivo, "%d\n", tmp->cliente_id);
        fprintf(arquivo, "%d\n", tmp->nome);
        fprintf(arquivo, "%d\n", tmp->cpf);
        fprintf(arquivo, "%d\n", tmp->endereco);
        fprintf(arquivo, "%d\n", tmp->pet);
        tmp = tmp->prox;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

void arquivarListaPets(LISTA_pet* listaPets) {
    // Abre o arquivo em modo de escrita
    FILE* arquivo = fopen("output/pets.txt", "w");
    nodePet *tmp = (*listaPets);

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve os elementos no arquivo
    while (tmp != NULL) {
        fprintf(arquivo, "|-------------------------------------------------|");
        fprintf(arquivo, "%d\n", tmp->pet_id);
        fprintf(arquivo, "%d\n", tmp->nome);
        fprintf(arquivo, "%d\n", tmp->idade);
        fprintf(arquivo, "%d\n", tmp->cor);
        fprintf(arquivo, "%d\n", tmp->dono_id);
        fprintf(arquivo, "%d\n", tmp->especie);
        fprintf(arquivo, "%d\n", tmp->genero);
        tmp = tmp->prox;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

void arquivarListaServicos(LISTA_cliente* listaServicos) {
    // Abre o arquivo em modo de escrita
    FILE* arquivo = fopen("output/clientes.txt", "w");
    nodeS *tmp = (*listaServicos);

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve os elementos no arquivo
    while (tmp != NULL) {
        fprintf(arquivo, "|-------------------------------------------------|");
        fprintf(arquivo, "%d\n", tmp->servico_id);
        fprintf(arquivo, "%d\n", tmp->descricao);
        fprintf(arquivo, "%d\n", tmp->tempo);
        fprintf(arquivo, "%d\n", tmp->valor);
        fprintf(arquivo, "%d\n", tmp->pet->pet_id);
        tmp = tmp->prox;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

void selectRegistro(LISTA_pet* listaPets, LISTA_SERVICO* listaServicos, LISTA_cliente* listaClientes) {
    int op;

    do {
        printf("=== SERVICOS ===\n\n");
        printf("1 - Inserir serico\n");
        printf("2 - Ver historico de servicos\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            arquivarListaClientes(listaClientes);
            break;
        }
    }while(op);
}
