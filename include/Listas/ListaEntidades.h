#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H
#include "../Ente/Entidades/Entidade.h"

#include "Lista.h"

namespace Listas {

    class ListaEntidades {
    private:
        Lista<Entidades::Entidade> LEntidades;
    public:
        ListaEntidades();
        virtual ~ListaEntidades();


        void inserirEntidade(Entidades::Entidade* entidade);
        void executarEntidades();




    protected:


    };

}

#endif // LISTAENTIDADES_H
