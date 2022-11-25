#ifndef __PANTANO_H__
#define __PANTANO_H__
#include "Fase.h"

namespace Fases{
    class Pantano: public Fase{
    private:
        bool passou;
    public:
        Pantano();
        Pantano(Entidades::Jogador* jg,Entidades::Jogador* jg2,Gerenciadores::Gerenciador_Colisoes* gc);
        ~Pantano();

        void inserirPisos();

        void inserirPlataformas(int n);

        void inserirEspinhos(int n);

        void inserirNinhos(int n);

        void inserirInimigos();

    };
}


#endif // __PANTANO_H__
