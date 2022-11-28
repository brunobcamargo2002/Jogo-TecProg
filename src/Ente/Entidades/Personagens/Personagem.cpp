#include "../../../../include/Ente/Entidades/Personagens/Personagem.h"

using namespace Entidades;


Personagem::Personagem(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidadeTerminal) :
animacao(&corpo),
Entidade(posicao, tamanho),
velocidadeTerminal(velocidadeTerminal),
velocidade(0.f, 0.f),
atacando(false),
podeAndar(true),
permiteAtacar(true),
morrendo(false),
levandoDano(false),
tempoEsperaAtaque(0),
relogio(),
relogio2(),
tomouDanoDeObstaculo(false),
coolDownDanoDeObstaculo(0.5),
tempoDanoDeObstaculo(0.f)
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
            corpo.setPosition(0,9999);
        }
    }

}

void Personagem::tomaDanoDeObstaculo(const int dano) {
        if (!tomouDanoDeObstaculo) {
            tomaDano(dano);
            relogio2.restart();
            tomouDanoDeObstaculo = true;
        } else {
            float dt=relogio2.getElapsedTime().asSeconds()-tempoEsperaAtaque;
            tempoEsperaAtaque += dt;
            if (tempoEsperaAtaque > coolDownDanoDeObstaculo) {
                tomouDanoDeObstaculo = false;
                tempoEsperaAtaque = 0.f;
                relogio2.restart();
            }
        }
}

bool Personagem::getMorrendo() {
    return morrendo;
}






















