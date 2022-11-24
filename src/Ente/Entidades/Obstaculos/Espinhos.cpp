#include "../../../../include/Ente/Entidades/Obstaculos/Espinhos.h"

using namespace Entidades;

int Espinhos::dano = 2;

Espinhos::Espinhos(int Px,int Py):Obstaculo(80,50,Px,Py){
    danoso = true;
    corpo.setFillColor(sf::Color::White);
    setTextura("C:\\Users\\bruno\\CLionProjects\\jogo-joao\\imagens\\Obstaculos\\Spikes.png");
}


Espinhos::~Espinhos(){}

const int Espinhos::getDano() {
    return dano;
}


