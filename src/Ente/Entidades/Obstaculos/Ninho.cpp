#include "../../../../include/Ente/Entidades/Obstaculos/Ninho.h"

using namespace Entidades;

int Ninho::pontosAbate = 10;

Ninho::Ninho(int Px,int Py,Jogador* jgdor1, Jogador* jgdor2):Obstaculo(90,90,Px,Py),
jogador1(jgdor1),
jogador2(jgdor2)
{
    danoso=false;
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Ninho.png");
}


Ninho::~Ninho()
{}

void Ninho::executar() {
    if(executa) {
        imprimir_se();
        destruirNinho(jogador1);
        if(jogador2!=NULL)
            destruirNinho(jogador2);
    }
}

void Ninho::destruirNinho(Jogador *jgdor) {
    if(jgdor!=NULL){
        if(jgdor->getAtacando()){
            sf::Vector2f rangeAtaque = jgdor->getRangeAtaque();
            sf::Vector2f posicaoJogador = jgdor->getPosicao();
            if (std::abs(corpo.getPosition().x - posicaoJogador.x) <= rangeAtaque.x &&
                std::abs(corpo.getPosition().y - posicaoJogador.y) <= rangeAtaque.y){
                if(jgdor->getTempoEsperaAtaque()>(jgdor->getTempoAtaque()-400)) {
                    Entidades::Jogador::alteraPontuacao(pontosAbate);
                    executa=false;
                    setPosicao(sf::Vector2f(9999, 9999));
                }
            }
        }
    }

}

void Ninho::salvarPosicao() {
    std::ofstream arquivo("save/Ninhos.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<executa<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}
