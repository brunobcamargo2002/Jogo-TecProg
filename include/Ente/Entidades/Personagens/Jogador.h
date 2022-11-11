#ifndef JOGADOR_H
#define JOGADOR_H

#include "Personagem.h"


namespace Entidades {

    class Jogador : public Personagem {
    public:
        Jogador(sf::Vector2f speed = sf::Vector2f(0.1, 0.1), sf::Vector2f body = sf::Vector2f(50, 50));
        virtual ~Jogador();
        void mover_se();
        void pular();

    };

}

#endif // JOGADOR_H
