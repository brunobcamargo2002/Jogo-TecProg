#include "../../../../include/Ente/Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades;

Obstaculo::Obstaculo()
{
    corpo.setSize(sf::Vector2f(800, 30));
    corpo.setOrigin(sf::Vector2f(800, 30)/2.f);
    corpo.setPosition(400, 400);
    corpo.setFillColor(sf::Color::Green);
}

Obstaculo::~Obstaculo()
{
    //dtor
}

void Obstaculo::executar() {
    Entidade::imprimir_se();
}
