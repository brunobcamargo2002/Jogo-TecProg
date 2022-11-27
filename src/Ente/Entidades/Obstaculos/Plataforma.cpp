#include "../../../../include/Ente/Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(int Px,int Py,int nvl):Obstaculo(150,30,Px,Py)
{
    danoso =false;
    nivel = nvl;
    corpo.setFillColor(sf::Color::White);
    setTextura("C:\\Users\\bruno\\CLionProjects\\jogo-joao\\imagens\\Obstaculos\\Plataforma.png");
}


Plataforma::~Plataforma()
{}

void Plataforma::salvarPosicao() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Plataformas.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<nivel<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}
