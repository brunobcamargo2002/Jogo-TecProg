#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidade.h"
#include "../../Animacao/Animacao.h"

namespace Entidades {

    class Projetil : public Entidade {
    private:
        Animacao animacao;
        sf::Vector2f velocidade;
    public:
        Projetil(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidade);
        virtual ~Projetil();

        void inicializa();

        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade);
        void executar();
    };

}

#endif // PROJETIL_H
