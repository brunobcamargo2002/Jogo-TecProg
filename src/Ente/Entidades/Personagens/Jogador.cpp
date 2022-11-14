#include "../../../../include/Ente/Entidades/Personagens/Jogador.h"

using namespace Entidades;


Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed) : Personagem(posicao, tamanho, speed) {

}

void Jogador::inicializa() {
    animacao.addAnimacao("Jungle++/imagens/Jogador/Anda.png", "ANDANDO", 10, 0.12f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Ataca.png", "ATACANDO", 10, 0.1f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Pula.png", "PULANDO", 3, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Cai.png", "CAINDO", 3, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Morre.png", "MORRENDO", 10, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/TomaDano.png", "TOMANDO_DANO", 1, 0.15f, sf::Vector2f(6,2));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));
}


Jogador::~Jogador()
{
    //dtor
}

void Jogador::mover_se()
{
    if(noChao) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
            corpo.move(velocidade.x, 0);
            paraEsquerda = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            corpo.move(-velocidade.x, 0);
            paraEsquerda = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocidade.y=-0.6;
            corpo.move(0, velocidade.y);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            corpo.move(0, 0);
    }
}


void Jogador::atualizarAnimacao() {
    if(!noChao && velocidade.y > 0.0f){
        animacao.atualizar(paraEsquerda, "CAINDO");
    }
    else if(!noChao){
        animacao.atualizar(paraEsquerda, "PULANDO");
    }
    else if(atacando){
        animacao.atualizar(paraEsquerda, "ATACANDO");
    }
    else if(podeAndar){
        animacao.atualizar(paraEsquerda, "ANDANDO");
    }
    else {
       animacao.atualizar(paraEsquerda, "PARADO");
    }

}







