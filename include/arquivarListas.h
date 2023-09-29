#ifndef ARQUIVARLISTAS_H_INCLUDED
#define ARQUIVARLISTAS_H_INCLUDED

#include "cliente.h"
#include "pet.h"
#include "servicos.h"
#include "produto.h"

void salvarClientes(LISTA_cliente *listaClientes);
void salvarPets(LISTA_pet *listaPets);
void salvarProdutos(LISTA_produto *listaProdutos);
void salvarServicos(LISTA_SERVICO *listaServicos);

#endif