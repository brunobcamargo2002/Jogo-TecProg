#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../Ente.h"


namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::Vector2f posicao;
        sf::RectangleShape corpo;
    public:
        Entidade();
        ~Entidade();
        void imprimir_se();
        virtual void executar()=0;

    };

}

#endif // ENTIDADE_H
