#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidade.h"
#include "../../Animacao/Animacao.h"
#include "Personagens/Jogador.h"

namespace Entidades {

    class Projetil : public Entidade {
    private:
        Jogador* jogador1;
        Jogador* jogador2;
        int dano;
        Animacao animacao;
        sf::Vector2f velocidade;
        bool paraEsquerda;
        bool lancar;
    public:
        Projetil(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidade, int dano, Jogador* jgdor1, Jogador* jgdor2=NULL);
        virtual ~Projetil();

        void inicializa();


        void daDano(Jogador* jgdor);
        void mover_se();
        void setDirecao(bool esquerda);
        void atualizarAnimacao();

        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade);
        void executar();
    };

}

#endif // PROJETIL_H
