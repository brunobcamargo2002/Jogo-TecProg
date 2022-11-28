#include "../../../include/Ente/Entidades/Projetil.h"

using namespace Entidades;

//projetil(sf::Vector2f(0,50), sf::Vector2f(30,30), sf::Vector2f(0.2,0), 5, jogador1, jogador2)

sf::Vector2f Projetil::tamanho=sf::Vector2f(30, 30);
sf::Vector2f Projetil::speed=sf::Vector2f(0.5, -0.2);
int Projetil::damage= 5;



Projetil::Projetil( Jogador* jgdor1, Jogador* jgdor2) :
Entidade(sf::Vector2f(9999, 9999), tamanho),
animacao(&corpo),
velocidade(speed),
paraEsquerda(false),
dano(damage),
jogador1(jgdor1),
jogador2(jgdor2){
    inicializa();
}

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
    animacao.addAnimacao("imagens/Projetil/Projetil.png", "PROJETIL", 6, 0.12f, sf::Vector2f(5,5));
}

void Projetil::colisao(sf::Vector2f deslocamento, Entidades::Entidade *entidade) {


}

void Projetil::executar() {
    gravidade();
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
            corpo.move(-velocidade.x, velocidade.y);
        else
            corpo.move(velocidade.x, velocidade.y);
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

void Projetil::gravidade() {
    velocidade.y+=0.0004;
}

void Projetil::setVelYParaLancamento() {
    velocidade.y= speed.y;
}

void Projetil::salvarPosicao() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Projeteis.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}




