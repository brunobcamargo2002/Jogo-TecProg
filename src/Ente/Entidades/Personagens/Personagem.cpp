#include "../../../../include/Ente/Entidades/Personagens/Personagem.h"

using namespace Entidades;


Personagem::Personagem(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidadeTerminal) :
animacao(&corpo),
Entidade(tamanho, posicao),
velocidadeTerminal(velocidadeTerminal),
velocidade(0.f, 0.f),
atacando(false),
podeAndar(true),
permiteAtacar(true),
morrendo(false),
tempoEsperaAtaque(0),
relogio(),
tempoMorte(1.8)
{
}


Personagem::~Personagem()
{
    //dtor
}


const sf::RectangleShape Personagem::getCorpo()
{
    return corpo;
}

void Personagem::setVelocidade(sf::Vector2f vel) {
    velocidade = vel;
}

void Personagem::colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade) {
    if(deslocamento.y>deslocamento.x)
    {
        if(entidade->getPosicao().x>getPosicao().x)
            corpo.move(-deslocamento.x, 0.f);
        else
            corpo.move(deslocamento.x, 0.f);
    }
    else
    {
        if(entidade->getPosicao().y>getPosicao().y) {
            corpo.move(0.f, -deslocamento.y);
            noChao = true;
            velocidade.y = 0;
        }
        else
            corpo.move(0.f, +deslocamento.y);

    }
}


void Personagem::gravidade() {
    if(velocidade.y!=0.f){
        noChao = false;
    }
    velocidade.y+=0.0004;
    corpo.move(0.f, velocidade.y);
}

void Personagem::mecanica() {
    mover_se();
    atacar();
}

void Personagem::executar(){
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

void Personagem::podeAtacar() {


}

void Personagem::setPodeAndar(bool valor) {
    podeAndar = valor;

}

void Personagem::tomaDano(int dano) {
    num_vidas -=dano;
    if(num_vidas<=0) {
        relogio.restart();
        morrendo = true;
    }
}

void Personagem::falecendo() {
    if(executa) {
        atualizarAnimacao();
        imprimir_se();
        if (relogio.getElapsedTime().asSeconds() > tempoMorte) {
            executa = false;
        }
    }

}





















