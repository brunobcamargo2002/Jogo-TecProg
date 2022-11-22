//
// Created by bruno on 22/11/2022.
//

#ifndef JOGO_COGUMALEFICO_H
#define JOGO_COGUMALEFICO_H

#include "Inimigo.h"
namespace Entidades {
    class Cogumalefico : public Inimigo {
    private:

    public:
        Cogumalefico(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL,Jogador *player2=NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Cogumalefico();

        void executar();
        void atualizarAnimacao();
        void inicializa();
        void mover_se();
        void atacaJogador(Jogador* jogador);
        void mecanica();


    };
}


#endif //JOGO_COGUMALEFICO_H
