#include <stdio.h>
#include <stdlib.h>
#include "servicos.h"
#include "pet.h"

LISTA_pet* criarListaPets()
{
    LISTA_pet *inicio = (LISTA_pet *) malloc (sizeof(LISTA_pet));
    if(inicio != NULL)
    {
        *inicio = NULL;
    }
    else
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }
    return inicio;
}

void cadastrarPet(LISTA_pet* lista)
{
    nodePet *novo = (nodePet*) malloc (sizeof(nodePet));
    if(novo == NULL)
    {
        printf("Erro de alocacao...\n");
        exit(0);
    }

    printf("Informe o ID do novo pet: ");
    scanf("%d", &novo->pet_id);
    printf("Informe o nome do novo pet: ");
    scanf("%s", &novo->nome);
    printf("Informe a especie do novo pet: ");
    scanf("%s", &novo->especie);
    printf("Informe a idade em anos do novo pet: ");
    scanf("%d", &novo->idade);
    printf("Informe o genero do novo pet: ");
    scanf("%s", &novo->genero);
    printf("Informe a cor do novo pet: ");
    scanf("%s", &novo->cor);
    printf("Informe o ID do dono do novo pet: ");
    scanf("%d", &novo->dono_id);

    nodePet *tmp;
    tmp = (*lista);

    while(tmp != NULL){
        if(tmp->pet_id == novo->pet_id){
            printf("\nNao foi possivel cadastrar o pet pois ja existe um pet com este ID!!!\n");
            free(novo);
            system("pause");
            return 1;
        }
        tmp= tmp->prox;
    }

    tmp = (*lista);
    novo->prox = NULL;


    if((*lista) == NULL)
    {
        *lista = novo;
        novo->ant = NULL;
    }
    else
    {
        while(tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        novo->ant = tmp;
    }

    printf("\nPet cadastrado com sucesso!!\n");
    system("pause");
}

void buscarPet(LISTA_pet* lista)
{
    int pet_id, op;
    printf("Informe o ID do pet que deseja visualizar: ");
    scanf("%d", &pet_id);

    nodePet *tmp = *lista;

    while (tmp != NULL) {
        if (tmp->pet_id == pet_id) {
            system("cls");
            printf("ID: %d\n", tmp->pet_id);
            printf("Nome: %s\n", tmp->nome);
            printf("Especie: %s\n", tmp->especie);
            printf("Idade: %d\n", tmp->idade);
            printf("Genero: %c\n", tmp->genero);
            printf("Cor: %s\n", tmp->cor);
            printf("Dono ID: %d\n\n", tmp->dono_id);

            printf("1 - Editar pet\n");
            printf("2 - Inserir Servico\n");
            printf("3 - Ver historico de servicos\n");
            printf("0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    system("cls");
                    printf("Editando pet...\n\n");
                    printf("Novo ID: ");
                    scanf("%d", &tmp->pet_id);
                    printf("Novo nome: ");
                    scanf("%s", tmp->nome);
                    printf("Nova especie: ");
                    scanf("%s", tmp->especie);
                    printf("Nova idade: ");
                    scanf("%d", &tmp->idade);
                    printf("Novo genero: ");
                    scanf(" %c", &tmp->genero); // Use espa�o para evitar quebras de linha anteriores
                    printf("Nova cor: ");
                    scanf("%s", tmp->cor);
                    printf("\n\n");
                    printf("Os dados foram atualizados!\n\n");
                    system("pause");
                    break;
                case 2:
                    inserirServicosNoPet(lista, tmp);
                    break;
                case 3:
                    //verHistorico(); // Chame verHistorico com o par�metro correto
                    break;
                case 0:
                    return; // Saia da fun��o sem retornar um valor
                default:
                    printf("Opcao invalida\n");
            }
        } else {
            printf("Pet nao encontrado!\n\n");
            system("pause");
            return; // Saia da fun��o sem retornar um valor
        }

        tmp = tmp->prox; // Mova o ponteiro para o pr�ximo n� dentro do loop
    }

    system("pause");
}

void editarPet(LISTA_pet* lista)
{
    int pet_id;
    printf("Informe o ID do pet que deseja editar: ");
    scanf("%d", &pet_id);

    nodePet *tmp = *lista;

    while (tmp != NULL)
    {
        if (tmp->pet_id == pet_id)
        {
            system("cls");
            printf("Editando pet...\n\n");
            printf("Novo ID: %d\n", tmp->pet_id);
            printf("Novo nome: %s\n", tmp->nome);
            printf("Nova especie: %s\n", tmp->especie);
            printf("Nova idade: %d\n", tmp->idade);
            printf("Novo genero: %c\n", tmp->genero);
            printf("Nova cor: %s\n", tmp->cor);
            printf("\n\n");
            printf("Os dados foram atualizados!");
        }
        tmp = tmp->prox;

    }
    system("pause");
}

void listarPets(LISTA_pet* lista)
{
    nodePet *tmp = *lista;

    if(tmp == NULL){
        printf("Nao ha nenhum cadastro!\n\n");
    }
    while (tmp != NULL)
    {
        printf("ID: %d\n", tmp->pet_id);
        printf("Nome: %s\n", tmp->nome);
        printf("Especie: %s\n", tmp->especie);
        printf("Idade: %d\n", tmp->idade);
        printf("Genero: %c\n", tmp->genero);
        printf("Cor: %s\n", tmp->cor);
        printf("Dono ID: %d\n", tmp->dono_id);
        printf("\n\n");
        tmp = tmp->prox;
    }
    system("pause");
}

void inserirServicosNoPet(LISTA_pet* lista, nodePet *pet)
{
    system("cls");

    int op;

    printf("Que tipo de servico foi prestado:\n");
    printf("1 - Banho\n");
    printf("2 - Tosa\n");
    printf("3 - Consulta Veterinaria\n");
    scanf("%d", &op);

    switch(op)
    {
    case 1:
        insereBanho(criarListaServicos(), pet);
        break;
    case 2:
        insereTosa(criarListaServicos());
        break;
    case 3:
        insereConsulta(criarListaServicos());
        break;
    default:
        printf("\nOpcao invalida");
    }
    printf("\nServico gravado com sucesso\n\n");

}

// void verHistoricoServicos(LISTA* lista) {
//     // Implementar a l�gica para ver o hist�rico de servi�os de um pet
// }

void excluirPet(LISTA_pet* lista)
{
    int pet_id;

    printf("Informe o ID do pet a ser excluido: ");
    scanf("%d", &pet_id);

    nodePet *tmp = *lista;

    while (tmp != NULL && pet_id != tmp->pet_id)
    {
        tmp = tmp->prox;
    }

    if (tmp == NULL)
    {
        printf("Pet com ID %d nao encontrado na lista.\n\n", pet_id);
        system("pause");
        return;
    }

    if (tmp->ant == NULL)
    {
        *lista = tmp->prox;
        if (tmp->prox != NULL)
        {
            tmp->prox->ant = NULL;
        }
    }
    else
    {
        tmp->ant->prox = tmp->prox;
        if (tmp->prox != NULL)
        {
            tmp->prox->ant = tmp->ant;
        }
    }
    free(tmp);

    printf("Elemento removido com sucesso.\n\n");
    system("pause");
}

void liberarPet(LISTA_pet* lista)
{
    if((*lista) == NULL)
    {
        printf("LISTA VAZIA");
    }
    else
    {
        nodePet *tmp;

        while (tmp != NULL)
        {
            tmp = (*lista);
            *lista = tmp->prox;
            free(tmp);
        }
        *lista = NULL;
    }
}
