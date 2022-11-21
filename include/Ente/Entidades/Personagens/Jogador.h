#ifndef JOGADOR_H
#define JOGADOR_H

#include "Personagem.h"


namespace Entidades {

    class Jogador : public Personagem {
    public:
        Jogador(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f velocidadeTerminal);
        virtual ~Jogador();

        virtual void mover_se()=0;
        virtual void atacar()=0;

        void atualizarAnimacao();

        void aumentaVelocidadeX();
        void diminuiVelocidadeX();
        void zeraVelocidade();
        void pulo();



    };

}

#endif // JOGADOR_H
