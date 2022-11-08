#include "../include/Jogo.h"


#include <iostream>
Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia())
{
    jogador1.setVelocidade(sf::Vector2f(0.2, 0.2));
    inimigo1.setJogador(&jogador1);
    inimigo1.setRaio(sf::Vector2f(200.f, 200.f));
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
        gerenciador_grafico->mostrarConteudo();

    }

}
