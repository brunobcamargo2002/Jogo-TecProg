#ifndef __PLATAFORMA_H__
#define __PLATAFORMA_H__

#include "Obstaculo.h"

namespace Entidades {

    class Plataforma : public Obstaculo {
    public:
        Plataforma(){};
        Plataforma(int Px,int Py);
        virtual ~Plataforma();
    };

}

#endif // __PLATAFORMA_H__
