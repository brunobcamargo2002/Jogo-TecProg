#include "../../../../include/Ente/Entidades/Personagens/Jogador.h"

using namespace Entidades;


Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f VelocidadeTerminal) : Personagem(posicao, tamanho, VelocidadeTerminal) {
    inicializa();
}

void Jogador::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Anda.png", "ANDANDO", 8, 0.12f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Ataca.png", "ATACANDO", 6, 0.1f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Parado.png", "PARADO", 8, 0.15f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Pula.png", "PULANDO", 2, 0.15f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Cai.png", "CAINDO", 2, 0.15f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/Morre.png", "MORRENDO", 6, 0.15f, sf::Vector2f(6,8));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/Jogo/imagens/Jogador/TomaDano.png", "TOMANDO_DANO", 4, 0.15f, sf::Vector2f(6,8));
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
            paraEsquerda = false;
            aumentaVelocidadeX();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            paraEsquerda = true;
            diminuiVelocidadeX();
            //corpo.move(-velocidade.x, 0);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocidade.y=-0.15;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            corpo.move(0, 0);
        else
            zeraVelocidade();
        corpo.move(velocidade.x, velocidade.y);
        std::cout<<velocidade.x<<std::endl<<velocidade.y<<std::endl;
    }
    else{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
            paraEsquerda = false;
            corpo.move(0.1, velocidade.y);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            paraEsquerda = true;
            corpo.move(-0.1, velocidade.y);

        }
        //corpo.move(velocidade.x, velocidade.y);
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
    else if(noChao && velocidade.x!=0.f){
        animacao.atualizar(paraEsquerda, "ANDANDO");
    }
    else {
       animacao.atualizar(paraEsquerda, "PARADO");
    }

}

void Jogador::zeraVelocidade() {
    if(noChao){
        if(std::abs(velocidade.x)<0.005)
          velocidade.x = 0.f;
     else if(velocidade.x>0) {
            velocidade.x -= 0.0009;
        }
        else if(velocidade.x<0){
            velocidade.x += 0.0009;
        }
    }
    else{
        if(std::abs(velocidade.x)<0.005)
            velocidade.x = 0.f;
        else if(velocidade.x>0) {
            velocidade.x -= 0.0009;
        }
        else if(velocidade.x<0){
            velocidade.x += 0.0009;
        }
    }

}

void Jogador::aumentaVelocidadeX() {
    if(velocidade.x<velocidadeTerminal.x){
        if(velocidade.x<0)
            velocidade.x+=0.005;
        else
            velocidade.x+=0.0005;
    }
}

void Jogador::diminuiVelocidadeX() {
    if(velocidade.x>-velocidadeTerminal.x){
        if(velocidade.x>0)
            velocidade.x-=0.005;
        else
            velocidade.x-=0.0005;
    }
}









