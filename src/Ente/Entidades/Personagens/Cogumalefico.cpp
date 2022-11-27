//
// Created by bruno on 22/11/2022.
//

#include "../../../../include/Ente/Entidades/Personagens/Cogumalefico.h"

//cogumalefico(sf::Vector2f(80,80),sf::Vector2f(800,100),sf::Vector2f(0.2,0), jg, jg2, sf::Vector2f(600,200)),

using namespace Entidades;

sf::Vector2f Cogumalefico::tamanho=sf::Vector2f(100, 100);
sf::Vector2f Cogumalefico::velocidadeTerminal=sf::Vector2f(0.2, 0);
sf::Vector2f Cogumalefico::range=sf::Vector2f(600, 100);

int Cogumalefico::pontosAbate=200;


Cogumalefico::Cogumalefico(int pX, int pY, Jogador* jgdor1, Jogador* jgdor2):
Inimigo(sf::Vector2f(pX, pY), tamanho, velocidadeTerminal, jgdor1, jgdor2){
    raioAtaque= sf::Vector2f(120.f, 120.f);
    coolDown=1000;
    tempoAtaque=500;
    num_vidas = 20;
    danoAtaque = 5;
    tempoMorte = 0.8f;
    setRaio(range);
    inicializa();
}

Cogumalefico::Cogumalefico(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed,Jogador *player,Jogador *player2, sf::Vector2f range) :
Inimigo(posicao, tamanho, speed, player, player2, range){
    raioAtaque= sf::Vector2f(120.f, 120.f);
    coolDown=1000;
    tempoAtaque=500;
    num_vidas = 20;
    danoAtaque = 5;
    tempoMorte = 0.8f;
    setRaio(range);
    inicializa();
}

Entidades::Cogumalefico::~Cogumalefico() {

}

void Entidades::Cogumalefico::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Cogumalefico/Anda.png", "ANDANDO", 8, 0.12f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Cogumalefico/Ataca.png", "ATACANDO", 8, 0.0625f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Cogumalefico/Parado.png", "PARADO", 4, 0.15f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Cogumalefico/Morre.png", "MORRENDO", 4, 0.2f, sf::Vector2f(8,6));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Cogumalefico/TomaDano.png", "TOMANDO_DANO", 4, 0.15f, sf::Vector2f(8,6));

}

void Entidades::Cogumalefico::atualizarAnimacao() {
    if(morrendo)
        animacao.atualizar(paraEsquerda, "MORRENDO");
    else if(atacando)
        animacao.atualizar(paraEsquerda, "ATACANDO");
    else if(noChao && velocidade.x!=0.f)
        animacao.atualizar(paraEsquerda, "ANDANDO");
    else
        animacao.atualizar(paraEsquerda, "PARADO");
}

void Entidades::Cogumalefico::executar() {
    if(morrendo) {
        Entidades::Jogador::alteraPontuacao(pontosAbate);
        falecendo();
    }
    else {
        mecanica();
        inimigoTomaDano(jogador1);
        if(jogador2!=NULL)
            inimigoTomaDano(jogador2);
        atualizarAnimacao();
        imprimir_se();
    }
    gravidade();

}



void Entidades::Cogumalefico::mover_se() {
    if(detectaJogador() && !atacando) {
        if(alvo!=NULL){
            sf::RectangleShape shapeJogador1 = alvo->getCorpo();
            if (shapeJogador1.getPosition().x - corpo.getPosition().x > 0) {
                corpo.move(velocidade.x, velocidade.y);
                paraEsquerda = false;
            } else {
                corpo.move(-velocidade.x, velocidade.y);
                paraEsquerda = true;
            }
        }
    }
}

void Entidades::Cogumalefico::atacaJogador(Entidades::Jogador *jogador) {
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
        if (std::abs(inimigo.x - jgdor.x) < raioAtaque.x && std::abs(inimigo.y - jgdor.y) < raioAtaque.y) {
            atacando = true;
            alvoAtaque = jogador;
        }
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

void Entidades::Cogumalefico::mecanica() {
    mover_se();
    atacar();
}

void Cogumalefico::salvarPosicao() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Cogumalefico.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<executa<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}


