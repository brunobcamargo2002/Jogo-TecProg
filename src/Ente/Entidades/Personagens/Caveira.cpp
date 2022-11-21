#include "../../../../include/Ente/Entidades/Personagens/Caveira.h"

using namespace Entidades;

Caveira::Caveira(sf::Vector2f tamanho, sf::Vector2f posicao, sf::Vector2f speed, Jogador *player1, Jogador *player2, sf::Vector2f range):
Inimigo(tamanho, posicao, speed, player1, player2, range)
{
    raioAtaque= sf::Vector2f(120.f, 120.f);
    coolDown=10000;
    tempoAtaque=1500;
    num_vidas = 1;
    danoAtaque = 2;
    tempoMorte = 0.8f;
    setRaio(range);
    inicializa();

}

Caveira::~Caveira() {

}

void Caveira::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Esqueleto/Anda.png", "ANDANDO", 4, 0.12f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Esqueleto/Ataca.png", "ATACANDO", 8, 0.12f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Esqueleto/Parado.png", "PARADO", 4, 0.15f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Esqueleto/Morre.png", "MORRENDO", 4, 0.2f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Esqueleto/TomaDano.png", "TOMANDO_DANO", 4, 0.15f, sf::Vector2f(8,6));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));

}

void Caveira::atualizarAnimacao() {
    if(morrendo)
        animacao.atualizar(paraEsquerda, "MORRENDO");
    else if(atacando)
        animacao.atualizar(paraEsquerda, "ATACANDO");
    else if(noChao && velocidade.x!=0.f)
        animacao.atualizar(paraEsquerda, "ANDANDO");
    else
        animacao.atualizar(paraEsquerda, "PARADO");

}


void Caveira::mover_se() {
    inimigoTomaDano(jogador1);
    if(detectaJogador() && !atacando) {
        sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
        {

            if (shapeJogador1.getPosition().x - corpo.getPosition().x > 0) {
                corpo.move(velocidade.x, velocidade.y);
                paraEsquerda = false;
            } else {
                corpo.move(-velocidade.x, velocidade.y);
                paraEsquerda = true;
            }
/*
        if(shapeJogador1.getPosition().y-corpo.getPosition().y>0)
            corpo.move(0, velocidade.y);
        else
            corpo.move(0, 0);*/
        }
    }
}

void Caveira::atacar() {
    if(jogador1!=NULL)
        atacaJogador(jogador1);
    //if(jogador2!=NULL)
       // atacaJogador(jogador2);

}

void Caveira::atacaJogador(Jogador* jogador) {
        if (!permiteAtacar) {
            float dt = relogio.getElapsedTime().asSeconds();
            tempoEsperaAtaque += dt;
            if (tempoEsperaAtaque >= coolDown) {
                permiteAtacar = true;
                tempoEsperaAtaque = 0;
                relogio.restart();
            }
        } else {
            sf::Vector2f inimigo = corpo.getPosition();
            sf::Vector2f jgdor = jogador->getCorpo().getPosition();
            if (std::abs(inimigo.x - jgdor.x) < raioAtaque.x && std::abs(inimigo.y - jgdor.y) < raioAtaque.y)
                atacando = true;
            if(atacando){
                tempoEsperaAtaque += relogio.getElapsedTime().asSeconds();
                if (tempoEsperaAtaque > tempoAtaque) {
                    if (std::abs(inimigo.x - jgdor.x) < raioAtaque.x && std::abs(inimigo.y - jgdor.y) < raioAtaque.y)
                        daDano(jogador);
                    atacando = false;
                    permiteAtacar = false;
                    tempoEsperaAtaque = 0;
                    relogio.restart();
                }
            } else {
                atacando = false;
                podeAndar = true;
                relogio.restart();
            }
        }
}

void Caveira::executar() {
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




