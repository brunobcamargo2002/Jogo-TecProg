#include "../../../../include/Ente/Entidades/Obstaculos/Ninho.h"

using namespace Entidades;

Ninho::Ninho(int Px,int Py):Obstaculo(90,90,Px,Py)
{
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Ninho.png");
}


Ninho::~Ninho()
{}
