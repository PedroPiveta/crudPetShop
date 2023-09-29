#include <stdlib.h>
#include <stdio.h>
#include "../include/pet.h"
#include "../include/servicos.h"
#include "../include/cliente.h"
#include "../include/produto.h"
#include "cliente.c"
#include "pet.c"
#include "produto.c"
#include "servicos.c"
#include "arquivarListas.c"

int main()
{
    LISTA_pet *lista_pet = criarListaPets();
    LISTA_SERVICO *lista_servico = criarListaServicos();
    LISTA_cliente *lista_cliente = criarListaClientes();
    LISTA_produto *lista_produto = criarListaProduto();

    FILE *arquivo;
    arquivo = fopen("cliente.txt", "w");
    int r;

    int op;
    do
    {
        system("cls");
        printf(" _._     _,-'\"\"`-._\n");
        printf("(,-.`._,'(       |\\`-/|\n");
        printf("    `-.-' \\ )-`( , o o)\n");
        printf("          `-    \\\\`_`\"'-\n");
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
        
        case 5:
            // salvarProdutos(lista_cliente);
            r = fputs("funciona filho da puta", arquivo);
            if (r == EOF)
            {
                printf("\nError\n");
            } else printf("\nGravado com sucesso!\n");
            system("pause");
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
