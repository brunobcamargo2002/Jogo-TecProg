#include "../include/Jogo.h"


#include <iostream>
#define MAX 5
#define MIN 3
#define RANDOM (rand()%(MAX-MIN))+MIN

Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
//personagens(),
//gerenciador_colisoes(&personagens, &obstaculos),
jogador(sf::Vector2f(600, 100), sf::Vector2f(70, 70), sf::Vector2f(0.35, 0.35)),
jogador2(sf::Vector2f(600, 100), sf::Vector2f(70, 70), sf::Vector2f(0.35, 0.35)),
fase(&jogador, &jogador2, &gerenciador_colisoes,RANDOM,RANDOM,RANDOM,1280),
menu(&fase)
{
}

Jogo::~Jogo()
{
    //dtor
}

void Jogo::executar()
{
    menu.executar();

}
