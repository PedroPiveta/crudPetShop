#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "clientes.txt"

void salvarProdutos(LISTA_cliente *listaClientes) {
    FILE *arquivo = fopen("clientes.txt", "a");
    // arquivo = fopen("clientes.txt", "a");
    if(!arquivo){
        printf("\nDeu o caraio aqui\n");
        system("pause");
    } 

    nodeCliente *tmp = *listaClientes;
    printf("%s \n", tmp->nome);

    if (arquivo) {
        while(tmp != NULL) {
            // fwrite(&tmp->cliente_id, sizeof(int), 1, arquivo);
            // printf("%d \n", tmp->cliente_id);
            // fwrite(&tmp->nome, sizeof(char), sizeof(tmp->nome), arquivo); // conferir
            // fwrite(&tmp->cpf, sizeof(char), 11, arquivo);
            // fwrite(&tmp->endereco, sizeof(char), sizeof(tmp->endereco), arquivo);
            // fwrite(&tmp->pet->pet_id, sizeof(int), 1, arquivo);
            fprintf(arquivo, "id: %d\n", tmp->cliente_id);
            fprintf(arquivo, "nome: %s\n", tmp->nome);
            fprintf(arquivo, "cpf: %s\n", tmp->cpf);
            fprintf(arquivo, "enderco: %s\n", tmp->endereco);
            
            tmp = tmp->prox;
        }
        fclose(arquivo);
    } else {
        printf("Erro ao salvar clientes!\n");
    }
}