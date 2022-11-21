#include "../../../include/Ente/Entidades/Projetil.h"

using namespace Entidades;

Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidade) {

}

Projetil::~Projetil() {

}

void Projetil::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Projetil/Projetil.png", "ANDANDO", 6, 0.12f, sf::Vector2f(8,7));
}

void Projetil::colisao(sf::Vector2f deslocamento, Entidades::Entidade *entidade) {

}

void Projetil::executar() {

}
