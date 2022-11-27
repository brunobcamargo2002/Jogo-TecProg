#ifndef __PLATAFORMA_H__
#define __PLATAFORMA_H__

#include "Obstaculo.h"

namespace Entidades {

    class Plataforma : public Obstaculo {
    private:
        int nivel;
    public:
        Plataforma(int Px,int Py,int nvl);
        virtual ~Plataforma();

        void salvarPosicao();
    };

}

#endif // __PLATAFORMA_H__
