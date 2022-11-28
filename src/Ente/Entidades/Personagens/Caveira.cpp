#include "../../../../include/Ente/Entidades/Personagens/Caveira.h"

using namespace Entidades;

sf::Vector2f Caveira::tamanho=sf::Vector2f(50, 60);
sf::Vector2f Caveira::velocidadeTerminal=sf::Vector2f(0.1, 0);
sf::Vector2f Caveira::range= sf::Vector2f(600, 50);

int Caveira::pontosAbate=30;

Caveira::Caveira(int pX, int pY, Jogador* jgdor1, Jogador* jgdor2):
Inimigo(sf::Vector2f(pX, pY), tamanho, velocidadeTerminal, jgdor1, jgdor2){
    raioAtaque= sf::Vector2f(120.f, 120.f);
    coolDown=1.5f;
    tempoAtaque=0.96f;
    num_vidas = 1;
    danoAtaque = 2;
    tempoMorte = 0.8f;
    setRaio(range);
    inicializa();
}

Caveira::Caveira(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed, Jogador *player1, Jogador *player2, sf::Vector2f range):
Inimigo(posicao, tamanho, speed, player1, player2, range)
{
    raioAtaque= sf::Vector2f(120.f, 120.f);
    coolDown=1.5f;
    tempoAtaque=0.96f;
    num_vidas = 1;
    danoAtaque = 2;
    tempoMorte = 0.8f;
    setRaio(range);
    inicializa();

}

Caveira::~Caveira() {

}

void Caveira::inicializa() {
    animacao.addAnimacao("imagens/Esqueleto/Anda.png", "ANDANDO", 4, 0.12f, sf::Vector2f(8,6));
    animacao.addAnimacao("imagens/Esqueleto/Ataca.png", "ATACANDO", 8, 0.12f, sf::Vector2f(8,6));
    animacao.addAnimacao("imagens/Esqueleto/Parado.png", "PARADO", 4, 0.15f, sf::Vector2f(8,6));
    animacao.addAnimacao("imagens/Esqueleto/Morre.png", "MORRENDO", 4, 0.2f, sf::Vector2f(8,6));
    animacao.addAnimacao("imagens/Esqueleto/TomaDano.png", "TOMANDO_DANO", 4, 0.15f, sf::Vector2f(8,6));
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


void Caveira::atacaJogador(Jogador* jogador) {
        if (!permiteAtacar) {
            float dt = relogio.getElapsedTime().asSeconds()-tempoEsperaAtaque;
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
                float dt = relogio.getElapsedTime().asSeconds()-tempoEsperaAtaque;
                tempoEsperaAtaque += dt;
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
        if(!deuPontos){
            Entidades::Jogador::alteraPontuacao(pontosAbate);
            deuPontos = true;
        }
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

void Caveira::mecanica() {
    mover_se();
    atacar();
}

void Caveira::salvarPosicao() {
    std::ofstream arquivo("save/Caveiras.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<executa<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}






