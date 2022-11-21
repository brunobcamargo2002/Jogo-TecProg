#ifndef INIM_TIPOA_H
#define INIM_TIPOA_H

#include "Inimigo.h"

namespace Entidades {
    class Caveira : public Inimigo {
    public:
        Caveira(sf::Vector2f tamanho, sf::Vector2f posicao, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL,Jogador *player2=NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Caveira();

        void inicializa();
        void mover_se();
        void atacar();
        void atacaJogador(Jogador* jogador);
        void atualizarAnimacao();
        void executar();
    };

}

#endif // INIM_TIPOA_H
