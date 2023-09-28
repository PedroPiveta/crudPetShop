#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "pet.c"
#include "servicos.c"
#include "cliente.c"
#include "registroEmArquivo.c"

int main()
{
    //declarem aqui a criação das listas que vcs implementaram
    LISTA_pet *lista = criarListaPets();
    LISTA_SERVICO *listas = criarListaServicos();
    LISTA_cliente *listaCliente = criarListaClientes();

    int escolha;

    while (1)
    {
        system("cls");
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Gerenciar Pets\n");
        printf("2. Gerenciar Clientes\n");
        printf("3. Gerenciar Produtos\n");
        printf("4. Gerenciar Servicos\n");
        printf("5 - Gerenciar Registros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            selectPet(lista, listas);
            break;
        case 2:
            selectCliente(listaCliente);
            break;

        case 3:
            //selectProduto();
            break;

        case 4:
            selectServico(lista, listas);
            break;

        case 5:
            selectRegistro(lista, listas, listaCliente);
            break;

        case 0:
            printf("Saindo do programa.\n");
            return 0;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;

    liberarPets(lista);
    free(lista);
    liberarServicos(listas);
    free(listas);
}
