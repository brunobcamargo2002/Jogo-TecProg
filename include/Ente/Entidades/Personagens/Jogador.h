#ifndef JOGADOR_H
#define JOGADOR_H

#include "Personagem.h"

namespace Entidades {

    class Jogador : public Personagem {
    private:

        static int pontos;
        static int decrementoDePontosPorDano;


    public:

        static sf::Vector2f tamanho;
        static sf::Vector2f velocidadeTerminal;

        static void alteraPontuacao(int alteracao);
        Jogador(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f velocidadeTerminal);
        virtual ~Jogador();

        void executar();
        void atualizarAnimacao();
        virtual void mover_se()=0;
        virtual void atacar()=0;
        void mecanica();
        void pulo();
        void aumentaVelocidadeX();
        void diminuiVelocidadeX();
        void zeraVelocidade();

        sf::Vector2f getRangeAtaque();
        bool getAtacando();
        float getTempoAtaque();
        float getTempoEsperaAtaque();
        int getDano();
        void tomaDano(int dano);

        int getPontos();
        void setPontos(int pontos);

        virtual void salvarPosicao()=0;



    };

}

#endif // JOGADOR_H
