#include "../../../include/Ente/Entidades/Projetil.h"

using namespace Entidades;

Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f velocidade, int dano,Jogador* jgdor1, Jogador* jgdor2):Entidade(posicao, tamanho),
velocidade(velocidade),
paraEsquerda(false),
dano(dano),
animacao(&corpo),
jogador1(jgdor1),
jogador2(jgdor2){
    inicializa();
}

Projetil::~Projetil() {

}

void Projetil::inicializa() {
    animacao.addAnimacao("C:/Users/bruno/CLionProjects/jogo-joao/imagens/Projetil/Projetil.png", "PROJETIL", 6, 0.12f, sf::Vector2f(5,5));
}

void Projetil::colisao(sf::Vector2f deslocamento, Entidades::Entidade *entidade) {


}

void Projetil::executar() {
    mover_se();
    atualizarAnimacao();
    imprimir_se();
    daDano(jogador1);
    if(jogador2!=NULL)
        daDano(jogador2);
}

void Projetil::atualizarAnimacao() {
    animacao.atualizar(paraEsquerda,"PROJETIL");
}

void Projetil::mover_se() {
        if (paraEsquerda)
            corpo.move(-velocidade.x, 0.f);
        else
            corpo.move(velocidade.x, 0.f);
}

void Projetil::setDirecao(bool esquerda) {
    paraEsquerda= esquerda;
}

void Projetil::daDano(Jogador* jgdor) {
    if(jgdor!=NULL){
        sf::Vector2f posicaoJogador = jgdor->getPosicao();
        sf::Vector2f tamanhoJogador = jgdor->getCorpo().getSize();
        if(std::abs(corpo.getPosition().x-posicaoJogador.x)<tamanhoJogador.x/2.f && std::abs(corpo.getPosition().y-posicaoJogador.y)<tamanhoJogador.y/2.f){
            jgdor->tomaDano(dano);
            corpo.setPosition(9999, 9999);
        }
    }

}
