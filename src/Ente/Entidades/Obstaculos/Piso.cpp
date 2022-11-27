#include "../../../../include/Ente/Entidades/Obstaculos/Piso.h"
using namespace Entidades;

Piso::Piso(int comprimento,int largura,int Px,int Py):Obstaculo(comprimento,largura,Px,Py)
{
    danoso = false;
    tamanho = comprimento;
    corpo.setFillColor(sf::Color::White);
    setTextura("C:\\Users\\bruno\\CLionProjects\\jogo-joao\\imagens\\Obstaculos\\Piso.png");
}

void Piso::salvarPosicao() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Pisos.txt", std::ios::app);
    sf::Vector2f posicao = getPosicao();

    arquivo<<tamanho<<" "<<posicao.x<<" "<<posicao.y<<std::endl;
    arquivo.close();

}
