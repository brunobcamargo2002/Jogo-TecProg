#ifndef __Piso_H__
#define __Piso_H__

#include "Obstaculo.h"

namespace Entidades {

    class Piso : public Obstaculo {
    public:
        Piso(){};
        Piso(int comprimento,int largura,int Px,int Py);
        virtual ~Piso(){};
    };
}

#endif // __Piso_H__
