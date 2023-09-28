#include <stdlib.h>
#include <stdio.h>
#include "pet.h"
#include "servicos.h"

int main()
{
    //declarem aqui a criação das listas que vcs implementaram
    LISTA_pet *lista = criarListaPets();
    LISTA_SERVICO *listas = criarListaServicos();

    int op;
    do
    {
        system("cls");
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Gerenciar Pets\n");
        printf("2. Gerenciar Clientes\n");
        printf("3. Gerenciar Produtos\n");
        printf("4. Gerenciar Servicos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            selectPet(lista_pet, lista_servico);
            break;
        case 2:
            selectCliente(lista_cliente);
            break;

        case 3:
            selectProduto(lista_produto);
            break;

        case 4:
            selectServico(lista_pet, lista_servico);
            break;

        case 0:
            printf("Saindo do programa.\n");
            return 0;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;

    liberarPets(lista_pet);
    liberarServicos(lista_servico);
    liberarClientes(lista_cliente);
    liberarProdutos(lista_produto);
}
