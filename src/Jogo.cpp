#include "../include/Jogo.h"


#include <iostream>
#define MAX 5
#define MIN 3
#define RANDOM (rand()%(MAX-MIN))+MIN

Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
menu()
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
