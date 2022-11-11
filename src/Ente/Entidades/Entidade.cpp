#include "../../../include/Ente/Entidades/Entidade.h"

using namespace Entidades;

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
    //dtor
}

void Entidade::imprimir_se() {
    gerenciador_grafico->desenhaElemento(corpo);
}

sf::Vector2f Entidade::getPosicao() {
    return corpo.getPosition();
}

sf::Vector2f Entidade::getTamanho() {
    return corpo.getSize();
}

