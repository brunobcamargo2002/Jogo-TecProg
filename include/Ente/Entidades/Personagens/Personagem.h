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
        const sf::Vector2f velocidadeTerminal;
        sf::Vector2f velocidade;
        int num_vidas;
        Animacao animacao;
        bool paraEsquerda;
        bool noChao;
        bool atacando;
        bool podeAndar;
        bool morrendo;
        bool levandoDano;
        int danoAtaque;
        sf::Clock relogio;
        sf::Vector2f raioAtaque;
        float tempoMorte;
        float tempoAtaque;
        bool permiteAtacar;
        float coolDown;
        float tempoEsperaAtaque;

        sf::Clock relogio2;
        bool tomouDanoDeObstaculo;
        float coolDownDanoDeObstaculo;
        float tempoDanoDeObstaculo;


    public:
        Personagem(sf::Vector2f posicao, sf::Vector2f tamanho,sf::Vector2f velocidadeTerminal = sf::Vector2f(0.1, 0.1));
        virtual ~Personagem();

        void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade);
        void gravidade();

        virtual void executar()=0;
        virtual void atualizarAnimacao()=0;
        virtual void mover_se() = 0;
        virtual void atacar()=0;
        virtual void mecanica()=0;
        virtual void tomaDano(int dano);
        void tomaDanoDeObstaculo(const int dano);
        virtual void falecendo();
        bool getMorrendo();


        void setPodeAndar(bool valor);
        const sf::RectangleShape getCorpo();


    private:
    };

}

#endif // PERSONAGEM_H
