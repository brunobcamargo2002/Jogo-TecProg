#include "../include/Jogo.h"


#include <iostream>
#define MAX 5
#define MIN 3
#define RANDOM (rand()%(MAX-MIN))+MIN

Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
jogador(70, 70),
jogador2(80, 70),
fase2(&jogador,&jogador2,&gerenciador_colisoes),
fase1(&jogador,&jogador2,&gerenciador_colisoes),
menu(static_cast <Fases::Fase*>(&fase1),static_cast <Fases::Fase*>(&fase2))
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
