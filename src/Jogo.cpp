#include "../include/Jogo.h"


#include <iostream>
Jogo::Jogo():
jogador1(sf::Vector2f(0.2, 0.2))
{
    inimigo1.setJogador(&jogador1);
    inimigo1.setRaio(sf::Vector2f(200.f, 200.f));


    window.create(sf::VideoMode(1920, 1080), "Choco");
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
}

Jogo::~Jogo()
{
    //dtor
}

void Jogo::executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        jogador1.mover_se();
        inimigo1.mover_se();
        window.draw(inimigo1.getCorpo());
        window.draw(jogador1.getCorpo());
        window.display();

    }

}
