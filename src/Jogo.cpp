#include "../include/Jogo.h"


#include <iostream>
Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
personagens(),
gerenciador_colisoes(&personagens, &obstaculos),
plataforma(sf::Vector2f(500, 500), sf::Vector2f(1000, 100), "C:/Users/bruno/CLionProjects/Jogo/imagens/Plataforma.png"),
jogador(sf::Vector2f(20, 20), sf::Vector2f(20, 20), sf::Vector2f(0.1, 0.1))
{
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(&plataforma));
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(&jogador));
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
