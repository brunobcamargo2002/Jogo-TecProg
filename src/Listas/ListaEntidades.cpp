#include "../../include/Listas/ListaEntidades.h"

using namespace Listas;

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

void ListaEntidades::imprimirEntidades() {
    Lista<Entidades::Entidade>::Iterador iterador;
    iterador = LEntidades.getPrimeiro();
    while(!iterador.fim())
    {
        iterador.getConteudo()->imprimir_se();
    }
}


