#ifndef __Piso_H__
#define __Piso_H__

#include "Obstaculo.h"

namespace Entidades {

    class Piso : public Obstaculo {
    private:
        int tamanho;
    public:
        Piso(int pX, int pY);
        Piso(int comprimento,int largura,int Px,int Py);
        virtual ~Piso(){};
    };
}

#endif // __Piso_H__
