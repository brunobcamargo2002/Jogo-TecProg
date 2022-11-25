#ifndef __FLORESTA_H__
#define __FLORESTA_H__
#include "Fase.h"

namespace Fases{
    class Floresta: public Fase{
    private:
        const int tam=3000;
        int ninhos;
    public:
        Floresta();
        Floresta(Entidades::Jogador* jg,Entidades::Jogador* jg2,Gerenciadores::Gerenciador_Colisoes* gc);
        ~Floresta();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirInimigos();

        void inserirInimigos1(int n);

        void inserirInimigos2(int n);
    };
}


#endif // __FLORESTA_H__
