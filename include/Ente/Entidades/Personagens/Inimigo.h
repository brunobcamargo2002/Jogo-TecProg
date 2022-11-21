#ifndef INIMIGO_H
#define INIMIGO_H

#include <cmath>

#include "Personagem.h"
#include "Jogador.h"


namespace Entidades {

    class Inimigo : public Personagem {
    protected:
        Jogador *jogador1;
        Jogador *jogador2;
        Jogador *alvo;
        sf::Vector2f raio;


    public:
        Inimigo(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL, Jogador *player2 = NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Inimigo();

        void setJogador(Jogador *player);
        void setRaio(sf::Vector2f range);
        bool detectaJogador();


        virtual void mover_se()=0;
        virtual void atacar()=0;
        virtual void atualizarAnimacao()=0;





    protected:
    };

}

#endif // INIMIGO_H
