#include "../../../../include/Ente/Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const char *caminhoTextura):
Obstaculo(posicao, tamanho, caminhoTextura) {

}

Plataforma::~Plataforma()
{
    //dtorf
}


