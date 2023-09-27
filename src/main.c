#include <stdlib.h>
#include <stdio.h>
#include "pet.h"
#include "servicos.h"
#include "cliente.h"

int main(){
    LISTA_pet *lista = criarListaPets();
    LISTA_SERVICO *listas = criarListaServicos();

    int op = 0;
        do {
            printf("Escolha a opcao desejada:\n");
            printf("1 - Opcoes Cliente\n");
            printf("0 - Sair\n");
            scanf("%d", &op);

            switch(op) {
                case 1:
                selectCliente();
                break;
            }
        } while (op != 0);

    free(lista);
}
