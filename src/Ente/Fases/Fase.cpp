#include "../../../include/Ente/Fases/Fase.h"

using namespace Fases;

Fase::Fase(Entidades::Jogador1* jg, Entidades::Jogador2* jg2, Gerenciadores::Gerenciador_Colisoes* gc,int obs1,int obs2,int obs3,int tam):
        espinho(tam/2, 720-60/2-100),
        cogumalefico(sf::Vector2f(80,80),sf::Vector2f(80,80),sf::Vector2f(0.2,0), jg, jg2, sf::Vector2f(600,200)),
        caveira(sf::Vector2f(50,60),sf::Vector2f(50,60),sf::Vector2f(0.1,0), jg, jg2, sf::Vector2f(800,200)),
        boitata(sf::Vector2f(30,30), sf::Vector2f(30,30), sf::Vector2f(0.1,0),jg, jg2, sf::Vector2f(600,50))
{
    jogador1=jg;
    jogador2=jg2;
    gerenciador_colisoes = gc;
    gerenciador_colisoes->setListaPersonagens(&personagens);
    gerenciador_colisoes->setListaObstaculos(&obstaculos);
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Ninho(480,650, jogador1, jogador2)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Piso(tam,60,tam/2,720-60/2)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,-30,500)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,tam+30,500)));
    //obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(&espinho));
    //obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Espinhos(400,640)));
    for(int i=0;i<obs1;i++)
        obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(tam/obs1*i+100,450,3)));
    if(jogador1!=NULL) {
        personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador1));
    }
    else
    {
        std::cerr<<"Player 1 não existente"<<std::endl;
        exit(1);
    }
    if(jogador2!=NULL) {
        personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador2));
    }
    //personagens.inserirEntidade(static_cast<Entidades::Entidade*>(&caveira));
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(&boitata));
    //personagens.inserirEntidade(static_cast<Entidades::Entidade*>(&cogumalefico));



}



Fase::~Fase()
{
    //dtor
}


void Fase::gerenciar_colisoes()
{

}
void Fase::executar()
{
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
        personagens.executarEntidades();
        obstaculos.executarEntidades();
        gerenciador_colisoes->executar();
        gerenciador_grafico->mostrarConteudo();

    }
}
