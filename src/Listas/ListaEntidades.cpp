#include "../../include/Listas/ListaEntidades.h"
#include "../../include/Ente/Entidades/Personagens/Personagem.h"

using namespace Listas;

#include <iostream>

ListaEntidades::ListaEntidades()
{

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
    while(!iterador.fim()) {
        if(iterador.getConteudo()!=NULL) {
            if (iterador.getConteudo()->getExecuta()) {
                iterador.getConteudo()->executar();
            }
        }
        ++iterador;
    }
}

Entidades::Entidade * ListaEntidades::operator[](int pos) {
    return LEntidades.operator[](pos);
}

unsigned int ListaEntidades::getTamanho() {
    return LEntidades.getTamanho();
}

void ListaEntidades::removerEntidade(Entidades::Entidade *entidade) {
    LEntidades.remover(entidade);

}





