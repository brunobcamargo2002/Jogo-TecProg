#include <cmath>

#include "../../include/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Gerenciadores;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
    LPersonagens = NULL;
    LObstaculos = NULL;
}

Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::ListaEntidades* ListaPersonagens ,Listas::ListaEntidades* ListaObstaculos) {
    LPersonagens = ListaPersonagens;
    LObstaculos = ListaObstaculos;

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    //dtor
}


const sf::Vector2f Gerenciador_Colisoes::calculaColisao(Entidades::Entidade *personagem, Entidades::Entidade *entidade2) {
    sf::Vector2f posicao1=personagem->getPosicao(), posicao2=entidade2->getPosicao();
    float distanciaX = std::fabs(posicao1.x-posicao2.x);
    float distanciaY = std::fabs(posicao1.y-posicao2.y);
    sf::Vector2f tamanho1=personagem->getTamanho(), tamanho2=entidade2->getTamanho();
    sf::Vector2f deslocamento(0,0);

    if((distanciaX<tamanho1.x/2.f+tamanho2.x/2.f) && (distanciaY<tamanho1.y/2.f+tamanho2.y/2.f))
    {
        deslocamento.x=std::fabs(distanciaX-tamanho1.x/2-tamanho2.x/2);
        deslocamento.y=std::fabs(distanciaY-tamanho1.y/2-tamanho2.y/2);
    }
    return deslocamento;
}

void Gerenciador_Colisoes::verificaColisaoEntrePersonagensEObstaculos() {
    int i, j;
    Entidades::Entidade *personagem;
    Entidades::Entidade *obstaculo;
    sf::Vector2f deslocamento;

    for(i=0; i<LPersonagens->getTamanho(); i++ )
    {
        personagem = LPersonagens->operator[](i);
        for(j=0; j<LObstaculos->getTamanho(); j++) {
            obstaculo = LObstaculos->operator[](j);
            deslocamento = calculaColisao(personagem, obstaculo);
            if(deslocamento!=sf::Vector2f(0.f, 0.f))
                personagem->colisao(deslocamento, obstaculo);
        }
    }

}

void Gerenciador_Colisoes::verificaColisaoEntrePersonagens() {
    int i, j;
    Entidades::Entidade *personagem;
    Entidades::Entidade *personagem2;
    sf::Vector2f deslocamento;

    for(i=0; i<LPersonagens->getTamanho(); i++ )
    {
        personagem = LPersonagens->operator[](i);
        for(j=i+1; j<LPersonagens->getTamanho(); j++) {
            personagem2 = LPersonagens->operator[](j);
            deslocamento = calculaColisao(personagem, personagem2);
            if(deslocamento!=sf::Vector2f(0.f, 0.f))
                personagem->colisao(deslocamento, personagem2);
        }
    }

}

void Gerenciador_Colisoes::executar() {
    verificaColisaoEntrePersonagens();
    verificaColisaoEntrePersonagensEObstaculos();

}
