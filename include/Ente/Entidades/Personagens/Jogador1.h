//
// Created by bruno on 17/11/2022.
//

#ifndef JOGO_JOGADOR1_H
#define JOGO_JOGADOR1_H

#include "Jogador.h"
namespace Entidades {
    class Jogador1 : public Jogador{


    public:
        Jogador1(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f velocidadeTerminal = sf::Vector2f(0.5, 0.5));
        ~Jogador1();
        void inicializa();

        void mover_se();
        void atacar();

    };
}

#endif //JOGO_JOGADOR1_H
