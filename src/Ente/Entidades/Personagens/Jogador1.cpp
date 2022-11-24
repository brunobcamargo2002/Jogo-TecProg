//
// Created by bruno on 17/11/2022.
//

#include "../../../../include/Ente/Entidades/Personagens/Jogador1.h"
using namespace Entidades;


Jogador1::Jogador1(int pX, int pY) : Jogador(sf::Vector2f(pX, pY), Jogador::tamanho, Jogador::velocidadeTerminal) {
    inicializa();
}

Entidades::Jogador1::Jogador1(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidadeTerminal) : Jogador(posicao, tamanho, velocidadeTerminal) {
    inicializa();
}

Entidades::Jogador1::~Jogador1() {

}



void Entidades::Jogador1::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Anda.png", "ANDANDO", 8, 0.12f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Ataca.png", "ATACANDO", 5, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Parado.png", "PARADO", 8, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Pula.png", "PULANDO", 2, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Cai.png", "CAINDO", 2, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/Morre.png", "MORRENDO", 8, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Jogador/TomaDano.png", "TOMANDO_DANO", 3, 0.15f, sf::Vector2f(8,7));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));
}

void Entidades::Jogador1::mover_se() {
        if (noChao) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                paraEsquerda = false;
                aumentaVelocidadeX();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                paraEsquerda = true;
                diminuiVelocidadeX();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                pulo();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                corpo.move(0, 0);
            else
                zeraVelocidade();
            corpo.move(velocidade.x, velocidade.y);
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                paraEsquerda = false;
                corpo.move(0.1, velocidade.y);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                paraEsquerda = true;
                corpo.move(-0.1, velocidade.y);
            } else
                zeraVelocidade();
        }
}

void Jogador1::atacar() {
    if(!permiteAtacar){
        tempoEsperaAtaque += relogio.getElapsedTime().asSeconds();
        if(tempoEsperaAtaque>coolDown){
            permiteAtacar = true;
            tempoEsperaAtaque=0;
            relogio.restart();
        }
    }
    else {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
            atacando= true;
        if(atacando==true){
            tempoEsperaAtaque+= relogio.getElapsedTime().asSeconds();
            if(tempoEsperaAtaque>tempoAtaque) {
                atacando = false;
                permiteAtacar = false;
                tempoEsperaAtaque = 0;
                relogio.restart();
            }
        }
        else{
            relogio.restart();
        }
    }
}




