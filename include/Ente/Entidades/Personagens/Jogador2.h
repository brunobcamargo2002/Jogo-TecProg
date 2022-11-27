//
// Created by bruno on 17/11/2022.
//

#ifndef JOGO_JOGADOR2_H
#define JOGO_JOGADOR2_H

#include "Jogador.h"
namespace Entidades {
    class Jogador2 : public Jogador {

    public:
        Jogador2(int pX, int pY);
        Jogador2(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f velocidadeTerminal = sf::Vector2f(0.5, 0.5));
        ~Jogador2();
        void inicializa();

        void mover_se();
        void atacar();

        void salvarPosicao();

    };
}
#endif //JOGO_JOGADOR2_H
