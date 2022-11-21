#ifndef __NINHO_H__
#define __NINHO_H__

#include "Obstaculo.h"

namespace Entidades {

    class Ninho : public Obstaculo {
    public:
        Ninho(){};
        Ninho(int Px,int Py);
        virtual ~Ninho();
    };

}

#endif // __NINHO_H__

