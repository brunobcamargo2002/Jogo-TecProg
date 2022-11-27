#ifndef __FLORESTA_H__
#define __FLORESTA_H__
#include "Fase.h"

namespace Fases{
    class Pantano: public Fase{
    private:
        const int tam=3000;
        int ninhos;
    public:
        Pantano(unsigned int numJogadores=1);
        ~Pantano();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirInimigos();

        void inserirInimigos1(int n);

        void inserirInimigos2(int n);
    };
}


#endif // __FLORESTA_H__
