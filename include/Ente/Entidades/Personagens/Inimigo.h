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
        Jogador *alvoAtaque;
        sf::Vector2f raio;

        bool tomouDano;

        bool deuPontos;


    public:
        Inimigo(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL, Jogador *player2 = NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Inimigo();

        virtual void executar()=0;
        virtual void atualizarAnimacao()=0;
        virtual void mover_se()=0;
        void atacar();
        virtual void atacaJogador(Jogador* jgdor)=0;
        virtual void mecanica()=0;

        void setRaio(sf::Vector2f range);
        bool detectaJogador();
        Jogador* jogadorMaisProximo(Jogador* jgdor1, Jogador* jgdor2);
        void inimigoTomaDano(Jogador* jgdor);
        void daDano(Jogador* jgdor);

        virtual void salvarPosicao()=0;








    protected:
    };

}

#endif // INIMIGO_H
