#include "../../include/Gerenciadores/Gerenciador_Grafico.h"
using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::instancia = NULL;
Gerenciador_Grafico* Gerenciador_Grafico::getInstancia()
{
    if(instancia==NULL)
    {
        instancia = new Gerenciador_Grafico;
    }
    return instancia;
}



Gerenciador_Grafico::Gerenciador_Grafico():
janela(new sf::RenderWindow(sf::VideoMode(800.f, 600.f), "Jogo"))
{
    if(janela == NULL)
    {
        std::cerr<<"Falha ao alocar a janela"<<std::endl;
        exit(1);
    }
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
    delete janela;
}

sf::RenderWindow *Gerenciador_Grafico::getWindow() {
    return janela;
}

void Gerenciador_Grafico::desenhaElemento(sf::RectangleShape conteudo) {
    janela->draw(conteudo);
}

void Gerenciador_Grafico::limpaJanela() {
    janela->clear();
}

void Gerenciador_Grafico::fecharJanela() {
    janela->close();
}

const bool Gerenciador_Grafico::verificaJanelaAberta() {
    return janela->isOpen();
}

void Gerenciador_Grafico::mostrarConteudo() const {
    janela->display();
}
