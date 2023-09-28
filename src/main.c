#include <stdlib.h>
#include <stdio.h>
#include "pet.h"
#include "servicos.h"
#include "cliente.h"
#include "produto.h"

int main()
{
    LISTA_pet *lista_pet = criarListaPets();
    LISTA_SERVICO *lista_servico = criarListaServicos();
    LISTA_cliente *lista_cliente = criarListaClientes();
    LISTA_produto *lista_produto = criarListaProduto();

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
        scanf("%d", &op);

        switch (op)
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
    } while(op != 0);


    liberarPets(lista_pet);
    liberarServicos(lista_servico);
    liberarCliente(lista_cliente);
    liberarProduto(lista_produto);
    return 0;
}
