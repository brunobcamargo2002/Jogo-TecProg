#include "../../../../include/Ente/Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades;


Obstaculo::Obstaculo(sf::Vector2f posicao, sf::Vector2f tamanho, const char *caminho):Entidade(posicao, tamanho) {
   setTextura(caminho);
}

Obstaculo::~Obstaculo()
{
    //dtor
}

void Obstaculo::executar() {
    Entidade::imprimir_se();
}

void Obstaculo::setTextura(const char* caminho) {
    textura = Gerenciadores::Gerenciador_Grafico::getInstancia()->carregarTextura(caminho);
    corpo.setTexture(textura);
}





