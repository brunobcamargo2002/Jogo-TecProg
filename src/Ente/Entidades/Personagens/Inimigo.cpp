#include "../../../../include/Ente/Entidades/Personagens/Inimigo.h"

using namespace Entidades;

Inimigo::Inimigo(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Vector2f speed, Jogador *player, Jogador *player2, sf::Vector2f range):
Personagem(posicao, tamanho, speed),
jogador1(player),
jogador2(player2),
alvo(NULL)
{
    raioAtaque= sf::Vector2f(120.f, 120.f);
    setRaio(range);
}

Inimigo::~Inimigo()
{
    //dtor
}

void Inimigo::setRaio(sf::Vector2f range)
{
    raio = range;
}

void Inimigo::setJogador(Jogador* player)
{
    jogador1 = player;
}

bool Inimigo::detectaJogador() {
    if(podeAndar) {

        if (jogador1 != NULL && jogador1->getExecuta()) {
            sf::RectangleShape shapeJogador1 = jogador1->getCorpo();
            if (std::abs(shapeJogador1.getPosition().x - corpo.getPosition().x) <= raio.x &&
                std::abs(shapeJogador1.getPosition().y - corpo.getPosition().y) <= raio.y) {
                velocidade.x = velocidadeTerminal.x;
                return true;
            } else {
                velocidade.x = 0.f;
                return false;
            }

        }
    }
    else
        velocidade.x = 0.f;

}










