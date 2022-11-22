#ifndef INIM_TIPOB_H
#define INIM_TIPOB_H

#include "Inimigo.h"
#include "../Projetil.h"
namespace Entidades {

    class Boitata : public Inimigo {
    private:
        Projetil projetil;

    public:
        Boitata(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed = sf::Vector2f(0.1, 0), Jogador *player = NULL, Jogador *player2 = NULL, sf::Vector2f range = sf::Vector2f(150.f, 150.f));
        virtual ~Boitata();

        void executar();
        void atualizarAnimacao();
        void mover_se();
        void atacaJogador(Jogador* jogador);
        void lancaProjetil(bool esquerda);
        void inicializa();
        void mecanica();

    };

}

#endif // INIM_TIPOB_H
