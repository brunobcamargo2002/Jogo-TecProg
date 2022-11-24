#ifndef __ESPINHOS_H__
#define __ESPINHOS_H__
#include "Obstaculo.h"

#include "../Personagens/Jogador.h"

namespace Entidades{

class Espinhos:public Obstaculo{
    private:
        static int dano;

    public:
        Espinhos(int Px,int Py);
        ~Espinhos();

       const int getDano();
};
}

#endif // __ESPINHOS_H__
