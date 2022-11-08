#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "SFML/Graphics.hpp"


#include "../Entidade.h"


namespace Entidades {

    class Personagem : public Entidade {
    protected:
        sf::Vector2f velocidade;
        int num_vidas;


    public:
        Personagem(sf::Vector2f speed = sf::Vector2f(0.1, 0.1), sf::Vector2f body = sf::Vector2f(50, 50));
        virtual ~Personagem();
        virtual void mover_se() = 0;
        const sf::RectangleShape getCorpo();
        void setVelocidade(sf::Vector2f vel);
        void executar();


    private:
    };

}

#endif // PERSONAGEM_H
