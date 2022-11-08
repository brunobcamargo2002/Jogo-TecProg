#include "../../include/Listas/ListaEntidades.h"

using namespace Listas;

#include <iostream>

ListaEntidades::ListaEntidades()
{
    //ctor
}

ListaEntidades::~ListaEntidades()
{
    //dtor
}

void ListaEntidades::inserirEntidade(Entidades::Entidade *entidade) {
    LEntidades.push_front(entidade);
}

void ListaEntidades::executarEntidades() {
    Lista<Entidades::Entidade>::Iterador iterador;
    iterador = LEntidades.getPrimeiro();
    while(!iterador.fim())
    {
        iterador.getConteudo()->executar();
        ++iterador;
    }
}


