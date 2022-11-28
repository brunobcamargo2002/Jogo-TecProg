#ifndef __PANTANO_H__
#define __PANTANO_H__
#include "Fase.h"

namespace Fases{
    class Floresta: public Fase{
    private:
        bool passou;
    public:
        Floresta(unsigned int numJogadores=1);
        ~Floresta();

        bool fimDaFase();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirNinhos(int n);

        void inserirInimigos();

    };
}


#endif // __PANTANO_H__
