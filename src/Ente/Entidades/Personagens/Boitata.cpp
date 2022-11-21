#include "../../../../include/Ente/Entidades/Personagens/Boitata.h"

using namespace Entidades;

Boitata::Boitata(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed, Jogador *player, Jogador *player2, sf::Vector2f range):
Inimigo(posicao, tamanho, speed, player, player2, range),
projetil(posicao, tamanho, velocidade){

}

Boitata::~Boitata() {

}

void Boitata::inicializa() {
    animacao.addAnimacao("imagens/Boitata/Anda.png", "ANDANDO", 9, 0.12f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Boitata/Ataca.png", "ATACANDO", 16, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Boitata/Parado.png", "PARADO", 9, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Boitata/Morre.png", "MORRENDO", 8, 0.3f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Boitata/TomaDano.png", "TOMANDO_DANO", 3, 0.15f, sf::Vector2f(8,7));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));

}




void Boitata::mover_se() {
    if(detectaJogador() && !atacando) {
        sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
        {

            if (shapeJogador1.getPosition().x - corpo.getPosition().x > 0) {
                corpo.move(-velocidade.x, velocidade.y);
                paraEsquerda = true;
            } else {
                corpo.move(velocidade.x, velocidade.y);
                paraEsquerda = false;
            }
        }
    }
}

void Boitata::atacar() {

}

void Boitata::atualizarAnimacao() {
    if(atacando)
        animacao.atualizar(paraEsquerda, "ATACANDO");
    else if(noChao && velocidade.x!=0.f){
        animacao.atualizar(paraEsquerda, "ANDANDO");
    }
    else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }

}
