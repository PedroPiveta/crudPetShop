#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

struct NodeS;
typedef struct NodeS nodeS;
typedef nodeS* LISTA_SERVICO;

typedef struct NodePet
{
    int pet_id;
    char nome[50];
    char especie[50];
    int idade;
    char genero;
    char cor[20];
    int dono_id;
    struct NodePet* prox;
    struct NodePet* ant;
} nodePet;

typedef nodePet* LISTA_pet;

<<<<<<< HEAD
LISTA_pet* criarListaPets(); // esta ok
void cadastrarPet(LISTA_pet* lista); // esta ok
void buscarPet(LISTA_pet* lista); // esta ok
void editarPet(LISTA_pet* lista); //esta ok
void listarPets(LISTA_pet* lista);  // esta ok
void inserirServicosNoPet(LISTA_pet* lista, nodePet *pet);
void verHistoricoServicos(LISTA_pet* lista);
void excluirPet(LISTA_pet* lista);  // esta ok
void liberarPet(LISTA_pet* lista);
=======
void selectPet();
LISTA_pet* criarListaPets();
void cadastrarPet(LISTA_pet* lista);
void buscarPet(LISTA_pet* lista, LISTA_SERVICO* listas);
void editarPet(LISTA_pet* lista);
void listarPets(LISTA_pet* lista);
void excluirPet(LISTA_pet* lista);
void liberarPets(LISTA_pet* lista);
>>>>>>> alysson

#endif