#ifndef OBST_TIPOA_H
#define OBST_TIPOA_H

#include "Obstaculo.h"

namespace Entidades {

    class Plataforma : public Obstaculo {
    private:

    public:
        Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const char* caminho);
        virtual ~Plataforma();

    protected:

    private:
    };

}

#endif // OBST_TIPOA_H
