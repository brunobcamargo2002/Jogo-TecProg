#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "SFML/Graphics.hpp"


#include "../Entidade.h"
#include "../../../Animacao/Animacao.h"

/*Todos os créditos ao monitor Giovani de técnicas de programação na parte de animações
 github : https://github.com/Giovanenero
youtube: https://www.youtube.com/channel/UCUa8BOx2F3hlxgPcpZmnBnQ
 */

namespace Entidades {
    class Personagem : public Entidade {
    protected:
        sf::Vector2f velocidade;
        int num_vidas;
        Animacao animacao;
        bool paraEsquerda;
        bool noChao;
        bool atacando;
        bool podeAndar;




    public:
        Personagem(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f speed = sf::Vector2f(0.1, 0.1));
        virtual ~Personagem();
        virtual void mover_se() = 0;
        virtual void atualizarAnimacao()=0;
        void gravidade();
        const sf::RectangleShape getCorpo();
        void setVelocidade(sf::Vector2f vel);
        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade);
        void executar();




    private:
    };

}

#endif // PERSONAGEM_H
