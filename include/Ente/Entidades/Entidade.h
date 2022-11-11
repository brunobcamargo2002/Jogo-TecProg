#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../Ente.h"


namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::RectangleShape corpo;
    public:
        Entidade();
        ~Entidade();
        sf::Vector2f getPosicao();
        sf::Vector2f getTamanho();
        void imprimir_se();
        virtual void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade)=0;
        virtual void executar()=0;


    };

}

#endif // ENTIDADE_H
