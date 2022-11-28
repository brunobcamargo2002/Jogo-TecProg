#include "../../../../include/Ente/Entidades/Personagens/Inimigo.h"

using namespace Entidades;

Inimigo::Inimigo(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed, Jogador *player, Jogador *player2, sf::Vector2f range):
Personagem(posicao, tamanho, speed),
jogador1(player),
jogador2(player2),
alvo(NULL),
tomouDano(false),
deuPontos(false)
{


}

Inimigo::~Inimigo()
{
    //dtor
}

void Inimigo::setRaio(sf::Vector2f range)
{
    raio = range;
}

bool Inimigo::detectaJogador() {
    if (podeAndar) {
        //std::cout<<"TESTE"<<std::endl;
        alvo = NULL;
        sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
        if (std::abs(shapeJogador1.getPosition().x - corpo.getPosition().x) <= raio.x &&
        std::abs(shapeJogador1.getPosition().y - corpo.getPosition().y) <= raio.y) {
            alvo = jogador1;
        }
        if (jogador2 != NULL) {
            sf::RectangleShape shapeJogador2 = jogador2->getCorpo();
            if (std::abs(shapeJogador2.getPosition().x - corpo.getPosition().x) <= raio.x &&
            std::abs(shapeJogador2.getPosition().y - corpo.getPosition().y) <= raio.y) {
                if(alvo==NULL)
                    alvo= jogador2;
                else
                    alvo = jogadorMaisProximo(jogador1, jogador2);
            }
        }
        if (alvo != NULL) {
            velocidade.x = velocidadeTerminal.x;
            return true;
        }
        else{
            velocidade.x = 0.f;
            return false;
        }

    }
    else
        velocidade.x = 0.f;
}

void Inimigo::atacar() {

    if (atacando)
        atacaJogador(alvoAtaque);
    else {
        atacaJogador(jogadorMaisProximo(jogador1, jogador2));
    }
}

void Inimigo::inimigoTomaDano(Jogador* jgdor) {
    if(jgdor!=NULL){
        if(jgdor->getAtacando()){
            sf::Vector2f rangeAtaque = jgdor->getRangeAtaque();
            sf::Vector2f posicaoJogador = jgdor->getPosicao();
            if (std::abs(corpo.getPosition().x - posicaoJogador.x) <= rangeAtaque.x &&
                std::abs(corpo.getPosition().y - posicaoJogador.y) <= rangeAtaque.y){

                if(jgdor->getTempoEsperaAtaque()>(jgdor->getTempoAtaque()-400)) {
                    if(!tomouDano){
                        tomaDano(jgdor->getDano());
                        tomouDano=true;
                    }
                }
                else
                    tomouDano=false;
            }
    }
    }

}

void Inimigo::daDano(Jogador *jgdor) {
    jgdor->tomaDano(danoAtaque);
}


Jogador *Inimigo::jogadorMaisProximo(Jogador* jgdor1, Jogador* jgdor2) {
    if(jgdor2==NULL)
        return jgdor1;
    if(jgdor1==NULL)
        return jgdor2;

    sf::Vector2f posicaoInim = getPosicao();
    sf::Vector2f posicao1= jgdor1->getPosicao(),posicao2= jgdor2->getPosicao();

    float distanciaX1, distanciaY1;
    distanciaX1= posicao1.x-posicaoInim.x;
    distanciaY1= posicao1.y-posicaoInim.y;

    float distanciaX2, distanciaY2;
    distanciaX2= posicao2.x-posicaoInim.x;
    distanciaY2= posicao2.y-posicaoInim.y;

    float distancia1= std::sqrt(distanciaX1*distanciaX1+distanciaY1*distanciaY1);
    float distancia2= std::sqrt(distanciaX2*distanciaX2+distanciaY2*distanciaY2);

    return ((distancia2<distancia1)?  jogador2:jogador1);
}











