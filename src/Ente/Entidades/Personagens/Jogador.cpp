#include "../../../../include/Ente/Entidades/Personagens/Jogador.h"

using namespace Entidades;

Jogador::Jogador(sf::Vector2f speed, sf::Vector2f body): Personagem(speed, body)
{
    corpo.setFillColor(sf::Color::Blue);
}

Jogador::~Jogador()
{
    //dtor
}

void Jogador::mover_se()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        corpo.move(velocidade.x, 0);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        corpo.move(-velocidade.x, 0);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        corpo.move(0, -velocidade.y);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        corpo.move(0, velocidade.y);
}
