#include "../../../../include/Ente/Entidades/Personagens/Boitata.h"

using namespace Entidades;



sf::Vector2f Boitata::tamanho=sf::Vector2f(30.f,30.f);
sf::Vector2f Boitata::velocidadeTerminal=sf::Vector2f(0.f, 0.f);
sf::Vector2f Boitata::range=sf::Vector2f(600.f, 80.f);

 int Boitata::pontosAbate=50;

Boitata::Boitata(int pX, int pY, Jogador* jgdor1, Jogador* jgdor2) :
Inimigo(sf::Vector2f((float)pX, (float)pY), tamanho, velocidadeTerminal, jgdor1, jgdor2, range),
projetil(jgdor1, jgdor2){
    raioAtaque= range;
    coolDown=1.f;
    tempoAtaque=1.5f;
    num_vidas = 1;
    danoAtaque = 2;
    tempoMorte = 1.2f;
    inicializa();
}


Boitata::Boitata(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed, Jogador *player, Jogador *player2, sf::Vector2f range):
Inimigo(posicao, tamanho, speed, player, player2, range),
projetil( jogador1, jogador2){
    raioAtaque= range;
    coolDown=1.f;
    tempoAtaque=1.5f;
    num_vidas = 1;
    danoAtaque = 2;
    tempoMorte = 1.2f;
    inicializa();

}

Boitata::~Boitata() {

}

void Boitata::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Boitata/Anda.png", "ANDANDO", 9, 0.12f, sf::Vector2f(5,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Boitata/Ataca.png", "ATACANDO", 16, 0.12f, sf::Vector2f(5,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Boitata/Parado.png", "PARADO", 9, 0.15f, sf::Vector2f(5,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Boitata/Morre.png", "MORRENDO", 8, 0.15f, sf::Vector2f(5,7));
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Boitata/TomaDano.png", "TOMANDO_DANO", 3, 0.15f, sf::Vector2f(5,7));
    corpo.setOrigin(sf::Vector2f(corpo.getSize().x/ 2.f, corpo.getSize().y / 2.f));

}

void Boitata::mover_se() {
}


void Boitata::atacaJogador(Jogador* jogador) {
    projetil.executar();
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
        float distanciaX = jgdor.x-inimigo.x;
        float distanciaY = jgdor.y-inimigo.y;
        if(std::abs(distanciaY) < raioAtaque.y) {
            if (distanciaX < 0)
                paraEsquerda = true;
            else
                paraEsquerda = false;
            if (std::abs(distanciaX) < raioAtaque.x) {
                atacando = true;
                alvoAtaque = jogador;
            }
        }
        if(atacando) {
            float dt = relogio.getElapsedTime().asSeconds()-tempoEsperaAtaque;
            tempoEsperaAtaque += dt;
            if (tempoEsperaAtaque > tempoAtaque-0.3) {
                if (distanciaX < 0)
                    lancaProjetil(true);
                else
                    lancaProjetil(false);
            }
            if (tempoEsperaAtaque > tempoAtaque) {
                atacando = false;
                permiteAtacar = false;
                tempoEsperaAtaque = 0;
                relogio.restart();
            }
        }
        else{
            atacando= false;
            relogio.restart();
        }
    }
}

void Boitata::atualizarAnimacao() {
    if(morrendo) {
        animacao.atualizar(paraEsquerda, "MORRENDO");
    }
    else if(atacando) {
        animacao.atualizar(paraEsquerda, "ATACANDO");
    }
    else if(noChao && velocidade.x!=0.f){
        animacao.atualizar(paraEsquerda, "ANDANDO");
    }
    else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }

}

void Boitata::lancaProjetil(bool esquerda) {
    sf::Vector2f posicao = corpo.getPosition();
    posicao.y -=15;
    projetil.setDirecao(esquerda);
    projetil.setVelYParaLancamento();
    if(esquerda)
        posicao.x-=corpo.getSize().x/2;
    else
        posicao.x+=corpo.getSize().x/2;
    projetil.setPosicao(posicao);
}

void Boitata::executar() {
    if(morrendo) {
        Entidades::Jogador::alteraPontuacao(pontosAbate);
        falecendo();
    }
    else {
        atacar();
        inimigoTomaDano(jogador1);
        if(jogador2!=NULL)
            inimigoTomaDano(jogador2);
        atualizarAnimacao();
        imprimir_se();
    }
    gravidade();

}

void Boitata::mecanica() {
    mover_se();
    atacar();

}

void Boitata::salvarPosicao() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Boitatas.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<executa<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();
}



