#ifndef INIMIGO_H
#define INIMIGO_H

#include <cmath>

#include "Personagem.h"
#include "Jogador.h"


namespace Entidades {

    class Inimigo : public Personagem {
    private:
        Jogador *jogador1;
        sf::Vector2f raio;

    public:
        Inimigo(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Inimigo();

        void setJogador(Jogador *player);
        void setRaio(sf::Vector2f range);
        bool persegueJogador();
        void mover_se();


    protected:
    };

}

#endif // INIMIGO_H
