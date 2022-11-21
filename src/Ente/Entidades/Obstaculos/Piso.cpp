#include "../../../../include/Ente/Entidades/Obstaculos/Piso.h"
using namespace Entidades;

Piso::Piso(int comprimento,int largura,int Px,int Py):Obstaculo(comprimento,largura,Px,Py)
{
    corpo.setFillColor(sf::Color::White);
    //setTextura("imagens/Obstaculos/Piso.png");
}
