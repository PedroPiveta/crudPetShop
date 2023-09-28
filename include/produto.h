#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

struct NodeProduto
{
    int produto_id;
    char nome[50];
    char categoria[50];
    char descricao[100];
    float preco_unitario;
    int quantidade_em_estoque;
    char fornecedor[50];
    struct NodeProduto *prox;
    struct NodeProduto *ant;
};

typedef struct NodeProduto nodeProduto;
typedef nodeProduto *LISTA_produto;

LISTA_produto* criarListaProduto(); // esta ok
void cadastrarProduto(LISTA_produto* lista); // esta ok
void buscarProduto(LISTA_produto* lista); // esta ok
void editarProduto(LISTA_produto* lista); //esta ok
void listarProdutos(LISTA_produto* lista);  // esta ok
void excluirProduto(LISTA_produto* lista);  // esta ok
void liberarProduto(LISTA_produto* lista);  // esta ok

#endif
