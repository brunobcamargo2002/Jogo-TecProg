#include "../../../../include/Ente/Entidades/Obstaculos/Espinhos.h"

using namespace Entidades;

int Espinhos::dano = 2;

Espinhos::Espinhos(int Px,int Py):Obstaculo(80,50,Px,Py){
    danoso = true;
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Spikes.png");
}


Espinhos::~Espinhos(){}

const int Espinhos::getDano() {
    return dano;
}

void Espinhos::salvarPosicao() {
    std::ofstream arquivo("save/Espinhos.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();
}


