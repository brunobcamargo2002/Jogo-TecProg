#include "../../../../include/Ente/Entidades/Personagens/Personagem.h"

using namespace Entidades;


Personagem::Personagem(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed) :
animacao(&corpo),
Entidade(tamanho, posicao),
velocidade(speed)
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
        if(entidade->getPosicao().y>getPosicao().y)
            corpo.move(0.f, -deslocamento.y);
        else
            corpo.move(0.f, +deslocamento.y);
        velocidade.y = 0;
        noChao = true;

    }
}


void Personagem::gravidade() {
    if(velocidade.y!=0.f){
        noChao = false;
        podeAndar = false;
    }
    velocidade.y+=0.0006;
    corpo.move(0.f, velocidade.y);
}

void Personagem::executar(){
    mover_se();
    atualizarAnimacao();
    gravidade();
    imprimir_se();
}














