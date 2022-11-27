#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <SFML/Graphics.hpp>
#include "../Ente.h"

#include <fstream>


namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::RectangleShape corpo;
        sf::Texture* textura;
        bool executa;
    public:
        Entidade(){};
        Entidade(sf::Vector2f posicao, sf::Vector2f tamanho);
        ~Entidade();
        void setPosicao(sf::Vector2f pos);
        void setTamanho(sf::Vector2f tam);
        sf::Vector2f getPosicao();
        sf::Vector2f getTamanho();
        void imprimir_se();
        virtual void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade)=0;
        virtual void executar()=0;
        bool getExecuta();
        void setTextura(const char* caminho);
        void setExecutar(const bool exec);

        virtual void salvarPosicao()=0;

    };

}

#endif // ENTIDADE_H
