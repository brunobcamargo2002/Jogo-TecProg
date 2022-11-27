#include "../../../include/Ente/Fases/Pantano.h"

#define MAX 8
#define MIN 4
#define RANDOM (rand()%(MAX-MIN))+MIN

using namespace Fases;



Pantano::Pantano(unsigned int numJogadores):
Fase( numJogadores)
{
    fase=2;
    setTextura("C:\\ODIABO\\Jogo-TecProg-main\\imagens/Fases/Pantano.png");
    visao=50;
    ninhos=0;
}

Pantano::~Pantano(){}

void Pantano::inserirPisos(){
    inserirPi(tam,1500,TelaY-30);
    inserirPi(tam,3000,TelaY-30);
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,-30,500)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,4530,500)));
    inserirPlataformas(RANDOM);
    inserirEspinhos(RANDOM);
    inserirNinhos(RANDOM);
}

void Pantano::inserirPlataformas(int n){
    int y=TelaY-280;
    int const espaco = tam/n;
    int x,largura_plataforma=200,x_ant=-300;
    for(int i=0;i<tam+500;i+=espaco){
        x = (rand()%(espaco-2*largura_plataforma)+largura_plataforma);
        if((x+espaco)-x_ant<=500){
            inserirPla(x+i,y,1);
            inserirN(x+i+55,y-259);
            ninhos++;
        }
        else
            inserirPla(x+i,y,0);
        x_ant=x;
    }
}

void Pantano::inserirEspinhos(int n){
    int y=TelaY-85;
    int espaco = tam/n;
    int x,largura_Espinho=200,x_ant=-30000;;
    for(int i=0;i<tam+300;i+=espaco){
        x = (rand()%(espaco-2*largura_Espinho)+largura_Espinho);
        if((x+espaco)-x_ant>=600){
            inserirN(x_ant+i-espaco+450,TelaY-99);
            ninhos++;
        }
        inserirE(x+i,y);
        inserirE(x+i+80,y);
        x_ant=x;
    }
}


void Pantano::inserirInimigos(){
    inserirC(4000,300);
    inserirInimigos1(RANDOM);
    inserirInimigos2(RANDOM);
}

void Pantano::inserirInimigos1(int n){
    int y=30,x;
    int espaco = tam/n,largura_Inimigo=40;
    for(int i=espaco;i<tam;i+=espaco){
        x = (rand()%(espaco-2*largura_Inimigo)+largura_Inimigo);
        inserirI1(x+i,y);}
}

void Pantano::inserirInimigos2(int n){
    int y=30,x;
    int espaco = tam/n,largura_Inimigo=40;
    for(int i=espaco;i<tam;i+=espaco){
        x = (rand()%(espaco-2*largura_Inimigo)+largura_Inimigo);
        inserirI2(x+i,y);}
}
