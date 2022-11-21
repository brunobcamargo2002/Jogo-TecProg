//
// Created by bruno on 17/11/2022.
//

#include "../../../../include/Ente/Entidades/Personagens/Jogador2.h"

using namespace Entidades;

Entidades::Jogador2::Jogador2(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidadeTerminal) : Jogador(posicao, tamanho, velocidadeTerminal) {
    inicializa();
}

Entidades::Jogador2::~Jogador2() {

}

void Entidades::Jogador2::inicializa() {
    animacao.addAnimacao("imagens/Jogador/Anda.png", "ANDANDO", 8, 0.12f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/Ataca.png", "ATACANDO", 5, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/Parado.png", "PARADO", 8, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/Pula.png", "PULANDO", 2, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/Cai.png", "CAINDO", 2, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/Morre.png", "MORRENDO", 8, 0.15f, sf::Vector2f(8,7));
    animacao.addAnimacao("imagens/Jogador/TomaDano.png", "TOMANDO_DANO", 3, 0.15f, sf::Vector2f(8,7));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));

}

void Entidades::Jogador2::mover_se() {
    if(noChao) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            paraEsquerda = false;
            aumentaVelocidadeX();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            paraEsquerda = true;
            diminuiVelocidadeX();
            //corpo.move(-velocidade.x, 0);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            pulo();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            corpo.move(0, 0);
        else
            zeraVelocidade();
        corpo.move(velocidade.x, velocidade.y);
    }
    else{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            paraEsquerda = false;
            corpo.move(0.1, velocidade.y);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            paraEsquerda = true;
            corpo.move(-0.1, velocidade.y);
        }
        else
            zeraVelocidade();
        //corpo.move(velocidade.x, velocidade.y);
    }

}

void Jogador2::atacar() {
    if(!permiteAtacar){
        tempoEsperaAtaque += relogio.getElapsedTime().asSeconds();
        if(tempoEsperaAtaque>coolDown){
            permiteAtacar = true;
            tempoEsperaAtaque=0;
            relogio.restart();
        }
    }
    if(permiteAtacar) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
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
    }

}


