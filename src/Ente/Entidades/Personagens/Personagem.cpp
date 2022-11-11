#include "../../../../include/Ente/Entidades/Personagens/Personagem.h"

using namespace Entidades;

Personagem::Personagem(sf::Vector2f speed, sf::Vector2f body)
{
    corpo.setSize(body);
    corpo.setOrigin(body/2.f);
    velocidade = speed;

}

Personagem::~Personagem()
{
    //dtor
}

const sf::RectangleShape Personagem::getCorpo()
{
    return corpo;
}

void Personagem::setVelocidade(sf::Vector2f vel) {
    velocidade = vel;
}

void Personagem::colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade) {
    if(deslocamento.y>deslocamento.x)
    {
        if(entidade->getPosicao().x>getPosicao().x)
            corpo.move(-deslocamento.x, 0.f);
        else
            corpo.move(deslocamento.x, 0.f);
    }
    else
    {
        if(entidade->getPosicao().y>getPosicao().y)
            corpo.move(0.f, -deslocamento.y);
        else
            corpo.move(0.f, +deslocamento.y);
        velocidade.y = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocidade.y=-0.3;
            corpo.move(0, velocidade.y);
        }
    }
}


void Personagem::gravidade() {
    velocidade.y+=0.001;
    corpo.move(0.f, velocidade.y);
}

void Personagem::executar(){
    mover_se();
    gravidade();
    imprimir_se();
}











