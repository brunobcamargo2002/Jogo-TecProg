#ifndef JOGADOR_H
#define JOGADOR_H

#include "Personagem.h"


namespace Entidades {

    class Jogador : public Personagem {
    public:
        Jogador(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f speed = sf::Vector2f(0.1, 0.1));
        virtual ~Jogador();
        void inicializa();
        void mover_se();
        void atualizarAnimacao();


    };

}

#endif // JOGADOR_H
