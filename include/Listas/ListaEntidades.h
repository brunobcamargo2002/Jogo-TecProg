#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H
#include "../Ente/Entidades/Entidade.h"

#include "Lista.h"

namespace Listas {

    class ListaEntidades {
    public:
        ListaEntidades();

        virtual ~ListaEntidades();

    protected:

    private:
        Lista<Entidades::Entidade> LEs;
    };

}

#endif // LISTAENTIDADES_H
