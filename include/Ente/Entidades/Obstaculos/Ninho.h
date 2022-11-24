#ifndef __NINHO_H__
#define __NINHO_H__

#include "Obstaculo.h"

#include "../Personagens/Jogador.h"

namespace Entidades {

    class Ninho : public Obstaculo {
    private:
        Jogador* jogador1;
        Jogador* jogador2;
        static int pontosAbate;
    public:
        Ninho(int Px,int Py, Jogador* jgdor1, Jogador* jgdor2 = NULL);
        void executar();
        void destruirNinho(Jogador* jgdor);
        virtual ~Ninho();
    };

}

#endif // __NINHO_H__

