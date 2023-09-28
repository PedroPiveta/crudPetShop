#include <stdlib.h>
#include <stdio.h>
#include "pet.h"
#include "servicos.h"
#include "produto.h"

int main(){
    LISTA_pet *lista = criarListaPets();
    LISTA_produto *lista = criarListaPets();
    LISTA_SERVICO *listas = criarListaServicos();

    int op;
    do
    {
        system("cls");
        printf("O que deseja: \n");
        printf("1 - Cadastrar um novo pet\n");
        printf("2 - Listar pets\n");
        printf("3 - buscar pet\n");
        printf("4 - Excluir um pet\n");
        printf("5 - Listar servicos\n");
        printf("0 - Voltar\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            system("cls");
            cadastrarPet(lista);
            break;
        case 2:
            system("cls");
            listarPets(lista);
            break;
        case 3:
            system("cls");
            buscarPet(lista);
            break;
        case 4:
            system("cls");
            excluirPet(lista);
            break;
        case 5:
            system("cls");
            verHistorico(listas);
            break;
        }
    }
    while(op != 0);

    liberar(lista);
    free(lista);
}
