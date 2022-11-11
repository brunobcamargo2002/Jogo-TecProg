#include "../../../../include/Ente/Entidades/Personagens/Inimigo.h"

using namespace Entidades;

Inimigo::Inimigo(sf::Vector2f speed, Jogador* player, sf::Vector2f range, sf::Vector2f body):
Personagem(speed, body)
{
    setJogador(player);
    setRaio(range);
    corpo.setFillColor(sf::Color::Red);
}

Inimigo::~Inimigo()
{
    //dtor
}

void Inimigo::setRaio(sf::Vector2f range)
{
    raio = range;
}

void Inimigo::setJogador(Jogador* player)
{
    jogador1 = player;
}

bool Inimigo::persegueJogador()
{
    if(jogador1!=NULL)
    {
        sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
        if(std::fabs(shapeJogador1.getPosition().x-corpo.getPosition().x)<=raio.x && std::fabs(shapeJogador1.getPosition().y-corpo.getPosition().y)<=raio.y)
            return true;
        else
            return false;

    }


}

void Inimigo::mover_se()
{
    if(persegueJogador())
    {
    sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
        if(shapeJogador1.getPosition().x-corpo.getPosition().x>0)
            corpo.move(velocidade.x, 0);
        else
            corpo.move(-velocidade.x, 0);

        /*
        if(shapeJogador1.getPosition().y-corpo.getPosition().y>0)
            corpo.move(0, velocidade.y);
        else
            corpo.move(0, 0);*/
    }


}


