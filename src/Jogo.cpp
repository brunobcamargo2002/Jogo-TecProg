#include "../include/Jogo.h"


#include <iostream>
Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
personagens(),
gerenciador_colisoes(&personagens, &obstaculos)
{
    jogador1.setVelocidade(sf::Vector2f(0.2, 0));
    inimigo1.setJogador(&jogador1);
    inimigo1.setRaio(sf::Vector2f(200.f, 200.f));
    obstaculos.inserirEntidade(static_cast <Entidades::Entidade*> (&obstaculo));
    personagens.inserirEntidade(static_cast <Entidades::Entidade*> (&jogador1));
    personagens.inserirEntidade(static_cast <Entidades::Entidade*> (&inimigo1));
}

Jogo::~Jogo()
{
    //dtor
}

void Jogo::executar()
{

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
        gerenciador_colisoes.executar();
        gerenciador_grafico->mostrarConteudo();

    }

}
