#include "../../../../include/Ente/Entidades/Personagens/Jogador.h"

using namespace Entidades;


Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f VelocidadeTerminal) : Personagem(posicao, tamanho, VelocidadeTerminal) {
    coolDown=1000;
    tempoAtaque=800;
    num_vidas=10;
    raioAtaque=sf::Vector2f(100,100);
}


Jogador::~Jogador()
{
    //dtor
}



void Jogador::atualizarAnimacao() {
    if(morrendo){
        animacao.atualizar(paraEsquerda, "MORRENDO");
    }
    else if(atacando){
        animacao.atualizar(paraEsquerda, "ATACANDO");
    }
    else if(!noChao && velocidade.y > 0.0f){
        animacao.atualizar(paraEsquerda, "CAINDO");
    }
    else if(!noChao){
        animacao.atualizar(paraEsquerda, "PULANDO");
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
        if((unsigned)velocidade.x<0.005)
          velocidade.x = 0.f;
     else if(velocidade.x>0) {
            velocidade.x -= 0.0009;
        }
        else if(velocidade.x<0){
            velocidade.x += 0.0009;
        }
    }
    else{
        if((unsigned)velocidade.x<0.005)
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
            velocidade.x+=0.05;
        else
            velocidade.x+=0.005;
    }
}

void Jogador::diminuiVelocidadeX() {
    if(velocidade.x>-velocidadeTerminal.x){
        if(velocidade.x>0)
            velocidade.x-=0.05;
        else
            velocidade.x-=0.005;
    }
}

void Jogador::pulo() {
    velocidade.y=-0.4;
}












