#include "../../../../include/Ente/Entidades/Personagens/Jogador.h"

using namespace Entidades;


 sf::Vector2f Jogador::tamanho=sf::Vector2f(70.f,70.f);
 sf::Vector2f Jogador::velocidadeTerminal=sf::Vector2f (0.5f, 0.6f);

int Jogador::pontos=0;
int Jogador::decrementoDePontosPorDano=-5;

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f VelocidadeTerminal) : Personagem(posicao, tamanho, VelocidadeTerminal) {
    coolDown=1000;
    tempoAtaque=800;
    num_vidas=10;
    danoAtaque = 2;
    tempoMorte= 1.2;
    raioAtaque=sf::Vector2f(180,100);
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

sf::Vector2f Jogador::getRangeAtaque() {
    return raioAtaque;
}

bool Jogador::getAtacando() {
    return atacando;
}

float Jogador::getTempoEsperaAtaque() {
    return tempoEsperaAtaque;
}

float Jogador::getTempoAtaque(){
    return tempoAtaque;
}

int Jogador::getDano() {
    return danoAtaque;
}

void Jogador::executar() {
    if(morrendo) {
        falecendo();
    }
    else {
        mecanica();
        atualizarAnimacao();
        imprimir_se();
    }
    gravidade();

}

void Jogador::mecanica() {
    mover_se();
    atacar();

}

void Jogador::alteraPontuacao(int alteracao) {
    pontos+=alteracao;
}

void Jogador::tomaDano(int dano) {
    num_vidas -=dano;
    Jogador::alteraPontuacao(dano*decrementoDePontosPorDano);
    if(num_vidas<=0) {
        relogio.restart();
        morrendo = true;
    }
}

int Jogador::getPontos() {
    return pontos;
}

void Jogador::setPontos(int pontos) {
    this->pontos = pontos;
}












