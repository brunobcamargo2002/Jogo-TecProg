#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H
#include "../Ente/Entidades/Entidade.h"

#include "Lista.h"
#include "../Ente/Entidades/Personagens/Personagem.h"

namespace Listas {

    class ListaEntidades {
    private:
        Lista<Entidades::Entidade> LEntidades;
    public:
        ListaEntidades();
        virtual ~ListaEntidades();


        void inserirEntidade(Entidades::Entidade* entidade);
        void removerEntidade(Entidades::Entidade* entidade);
        Entidades::Entidade* removerPrimeiro();
        void limparLista();
        void executarEntidades();
        unsigned int getTamanho();
        Entidades::Entidade * operator[] (int pos);




    protected:


    };

}

#endif // LISTAENTIDADES_H
