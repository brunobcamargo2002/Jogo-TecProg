#include "../../../include/Ente/Fases/Floresta.h"

using namespace Fases;


Floresta::Floresta( unsigned int numJogadores):
Fase( numJogadores)
{fase=1;
visao=100;
passou=false;
    setTextura("C:\\ODIABO\\Jogo-TecProg-main\\imagens/Fases/Floresta.png");}

Floresta::~Floresta(){}

void Floresta::inserirPisos(){

    inserirPlataformas(0);
}

void Floresta::inserirPlataformas(int n){
    int x,y,nvl,nvlpassado=0;
    for(int i=0;i<80;i+=4){
        nvl= (rand()%3)-1;
        inserirPla(0+150*i,690,nvlpassado+nvl);
        inserirPla(150+150*i,690,nvlpassado+nvl);
        inserirPla(300+150*i,690,nvlpassado+nvl);
        x=150+150*i + rand()%175;
        y=-200*(nvlpassado+nvl)+690;
        switch (rand()%3){
        case 0:
            inserirE(x - 50,y-40);
            inserirE(x - 100,y-40);
            break;
        case 1:
            inserirI1(x-30,y-35);
            break;
        case 2:
            inserirI2(x-30,y-75);
            break;
        }
        nvlpassado+=nvl;
    }
}

void Floresta::inserirEspinhos(int n){

}

void Floresta::inserirNinhos(int n){
}

void Floresta::inserirInimigos() {

}




