#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "../Entidade.h"

namespace Entidades {

class Obstaculo : public Entidade
{
    public:
        Obstaculo();
        virtual ~Obstaculo();
        void executar();
        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade){};

};
}

#endif // OBSTACULO_H
