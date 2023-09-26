#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

struct NodePet
{
    int pet_id;
    char nome[50];
    char especie[50];
    int idade;
    char genero;
    char cor[20];
    int dono_id;
    int exemplo;
    struct NodePet *prox;
    struct NodePet *ant;
};

typedef struct NodePet nodePet;
typedef nodePet *LISTA_pet;

LISTA_pet* criarListaPets(); // esta ok
void cadastrarPet(LISTA_pet* lista); // esta ok
void buscarPet(LISTA_pet* lista); // esta ok
void editarPet(LISTA_pet* lista); //esta ok
void listarPets(LISTA_pet* lista);  // esta ok
void inserirServicosNoPet(LISTA_pet* lista, nodePet *pet);
void verHistoricoServicos(LISTA_pet* lista);
void excluirPet(LISTA_pet* lista);  // esta ok

#endif
