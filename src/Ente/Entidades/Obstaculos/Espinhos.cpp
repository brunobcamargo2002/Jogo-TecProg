#include "../../../../include/Ente/Entidades/Obstaculos/Espinhos.h"

using namespace Entidades;

Espinhos::Espinhos(int Px,int Py):Obstaculo(80,50,Px,Py){
    danoso=1;
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Spikes.png");
}


Espinhos::~Espinhos(){}
