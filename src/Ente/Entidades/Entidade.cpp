#include "../../../include/Ente/Entidades/Entidade.h"

using namespace Entidades;



Entidade::Entidade(sf::Vector2f posicao, sf::Vector2f tamanho):
executa(true){
    textura=NULL;
    corpo.setPosition(posicao);
    corpo.setSize(tamanho);
    corpo.setOrigin(tamanho/2.f);
}

Entidade::~Entidade()
{
    //dtor
}

void Entidade::imprimir_se() {
    gerenciador_grafico->desenhaElemento(corpo);
}

sf::Vector2f Entidade::getPosicao() {
    return corpo.getPosition();
}

sf::Vector2f Entidade::getTamanho() {
    return corpo.getSize();
}
void Entidade::setPosicao(sf::Vector2f pos){
    corpo.setPosition(pos);
}

void Entidade::setTamanho(sf::Vector2f tam){
    corpo.setSize(tam);
}

void Entidade::setTextura(const char* caminho){
    textura = Gerenciadores::Gerenciador_Grafico::getInstancia()->carregarTextura(caminho);
    corpo.setTexture(textura);
}

bool Entidade::getExecuta() {
    return executa;
}


