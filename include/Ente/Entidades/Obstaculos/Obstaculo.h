#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "../Entidade.h"

namespace Entidades {

class Obstaculo : public Entidade
{
    protected:
        bool danoso;
    public:
        Obstaculo(int comprimento, int largura,int Px,int Py);
        virtual ~Obstaculo();
        virtual void executar();
        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade){};
        void SetPosicao(int Px,int Py);
        void SetDimensoes(int comprimento,int largura);
        const bool getDanoso();
        virtual const int getDano();

};
}

#endif // OBSTACULO_H
