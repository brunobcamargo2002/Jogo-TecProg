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



