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
    /*else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        pular();
    }*/
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        corpo.move(0, 0);
}

void Jogador::pular() {
    velocidade.y=-0.3;
    corpo.move(0, velocidade.y);
}



