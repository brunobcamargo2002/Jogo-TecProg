#ifndef FASE_H
#define FASE_H

#include "../Ente.h"

namespace Fases {

    class Fase : public Ente {
    public:
        Fase();

        virtual ~Fase();

        void gerenciar_colisoes();

        virtual void executar();

    protected:

    private:
    };

}

#endif // FASE_H
