#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct NodeCliente {
    int cliente_id;
    char nome[50];
    char cpf[11];
    char endereco[200];
    struct NodePet *pet;
    struct NodeCliente *prox;
    struct NodeCliente *ant;
} nodeCliente;

typedef nodeCliente *LISTA_cliente;

LISTA_cliente* criarListaClientes();
void cadastrarCliente(LISTA_cliente* lista);
void buscarCliente(LISTA_cliente* lista);
void editarCliente(LISTA_cliente* lista);
void listarCliente(LISTA_cliente* lista);
void excluirCliente(LISTA_cliente* lista);
void liberarCliente(LISTA_cliente* lista);
void selectCliente(LISTA_cliente* lista);

#endif