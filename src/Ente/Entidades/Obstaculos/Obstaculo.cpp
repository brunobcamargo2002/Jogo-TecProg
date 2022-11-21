#include "../../../../include/Ente/Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades;

Obstaculo::Obstaculo()
{
    danoso=0;
}

Obstaculo::Obstaculo(int comprimento, int largura,int Px,int Py):
Entidade(sf::Vector2f(Px,Py),sf::Vector2f(comprimento, largura))
{
    danoso=0;
}

Obstaculo::~Obstaculo()
{
    //dtor
}

void Obstaculo::executar() {
    Entidade::imprimir_se();
}

void Obstaculo::SetDimensoes(int comprimento,int largura){
    corpo.setSize(sf::Vector2f(comprimento, largura));
    corpo.setOrigin(sf::Vector2f(comprimento, largura)/2.f);
}

void Obstaculo::SetPosicao(int Px,int Py){
    corpo.setPosition(Px,Py);
}
