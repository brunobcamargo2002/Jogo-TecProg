#include "../../../include/Ente/Entidades/Entidade.h"

using namespace Entidades;



Entidade::Entidade(sf::Vector2f posicao, sf::Vector2f tamanho) {
    corpo.setPosition(posicao);
    corpo.setSize(tamanho);
    corpo.setOrigin(tamanho/2.f);

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



