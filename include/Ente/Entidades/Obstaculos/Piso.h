#ifndef __Piso_H__
#define __Piso_H__

#include "Obstaculo.h"

namespace Entidades {

    class Piso : public Obstaculo {
    private:
        int tamanho;
    public:
        Piso(int comprimento,int largura,int Px,int Py);
        virtual ~Piso(){};

        void salvarPosicao();
    };
}

#endif // __Piso_H__
