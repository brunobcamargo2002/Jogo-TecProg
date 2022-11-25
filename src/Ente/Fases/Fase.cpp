#include "../../../include/Ente/Fases/Fase.h"

using namespace Fases;


Fase::Fase(Entidades::Jogador* jg,Entidades::Jogador* jg2,Gerenciadores::Gerenciador_Colisoes* gc){

    fundo.setSize(sf::Vector2f(1280.f,720.f));
    fundo.setOrigin(sf::Vector2f(1280/2.f,720/2.f));
    jogador1=jg;
    jogador2=jg2;
    gerenciador_colisoes = gc;
}


Fase::Fase()
{
}

Fase::~Fase()
{
    jogador1=NULL;
    gerenciador_colisoes=NULL;
}

void Fase::executar()
{
    //if(jogador1->getNome())
        getNome();
    gerenciador_colisoes->setListaPersonagens(&personagens);
    gerenciador_colisoes->setListaObstaculos(&obstaculos);
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(jogador1));
    if(jogador2!=NULL)
        personagens.inserirEntidade(static_cast<Entidades::Entidade*>(jogador2));
    inserirPisos();
    inserirInimigos();
    gerenciador_grafico->limpaJanela();
    while (gerenciador_grafico->verificaJanelaAberta())
    {
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        gerenciador_grafico->limpaJanela();
        gerenciador_grafico->desenhaElemento(fundo);
        personagens.executarEntidades();
        obstaculos.executarEntidades();
        gerenciador_colisoes->executar();
        gerenciador_grafico->AttView(jogador1->getPosicao().x+150,jogador1->getPosicao().y+visao,&fundo);
        if(fase && jogador1->getPosicao().x>11500)
            return;
        gerenciador_grafico->mostrarConteudo();
    }
}

void Fase::inserirPisos(){
}

void Fase::inserirPlataformas(int n){
}

void Fase::inserirEspinhos(int n){
}

void Fase::inserirNinhos(int n){
}

void Fase::inserirPi(int tam,int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Piso(tam,60,x,y)));
}

void Fase::inserirPla(int x,int y,int nivel){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(x,y-nivel*200,nivel)));
}

void Fase::inserirE(int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Espinhos(x,y)));
}

void Fase::inserirN(int x,int y){
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Ninho(x,y,jogador1,jogador2)));
}

void Fase::inserirI1(int x,int y){
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Boitata(x,y,jogador1,jogador2)));
}

void Fase::inserirI2(int x,int y){
   personagens.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Caveira(x,y,jogador1,jogador2)));
}

void Fase::inserirC(int x,int y){
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Cogumalefico(x,y,jogador1,jogador2)));
}


void Fase::inserirInimigos(){}

void Fase::inserirInimigos1(int n){}

void Fase::inserirInimigos2(int n){}

void Fase::inserirChefes(int n){}

void Fase::getNome(){
    printf("pega nome");
    gerenciador_grafico->limpaJanela();
}

void Fase::setTextura(const char* caminho){
    tfundo = Gerenciadores::Gerenciador_Grafico::getInstancia()->carregarTextura(caminho);
    fundo.setTexture(tfundo);
}
