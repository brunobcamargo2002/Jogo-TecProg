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
        void executar();

        void aumentaVelocidadeX();
        void diminuiVelocidadeX();
        void zeraVelocidade();
        void pulo();


        sf::Vector2f getRangeAtaque();
        bool getAtacando();
        float getTempoAtaque();
        float getTempoEsperaAtaque();
        int getDano();



    };

}

#endif // JOGADOR_H
