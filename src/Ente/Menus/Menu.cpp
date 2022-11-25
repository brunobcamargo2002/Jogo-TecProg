#include "../../../include/Ente/Menus/Menu.h"

Menu::Menu(Fase* f1,Fase* f2):n(3){
    fase1= f1;
    fase2= f2;
    gerenciador_grafico->limpaJanela();
    if (!font.loadFromFile("C:\\ODIABO\\Jogo-TecProg-main\\arial.TTF")){
        printf("error abrindo fonte");}

    for(int i=0;i<3;i++){text[i].setFont(font);}

    for(int i=0;i<4;i++){fases[i].setFont(font);}

    text[0].setString("Jogar");
    text[1].setString("Rank");
    text[2].setString("Sair");

    fases[0].setString("Voltar");
    fases[1].setString("Pantano");
    fases[2].setString("Floresta");
    fases[3].setString("Carregar Jogo");

    for(int i=0;i<3;i++){
        text[i].setCharacterSize(32);
        text[i].setFillColor(sf::Color::White);
        text[i].setOutlineColor(sf::Color::Red);
        text[i].setPosition(200.f,(1+i)*150.f);}
    for(int i=0;i<4;i++){
        fases[i].setCharacterSize(28);
        fases[i].setFillColor(sf::Color::White);
        fases[i].setOutlineColor(sf::Color::Red);
        fases[i].setPosition(200.f,50+(1+i)*100.f);}
}

Menu::~Menu(){
}

//=====================================================================================================//

#define INTERVALO 0.02
#define GROSSURA 2
//=====================================================================================================//

void Menu::executar(){
    n.reiniciar();
    n.setMax(3);
    sf::Clock relogio;
    text[n.getContador()].setOutlineThickness(GROSSURA);
    while(gerenciador_grafico->verificaJanelaAberta()){
        gerenciador_grafico->limpaJanela();
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n--;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n++;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                case 0:
                    MostraFases();
                    break;
                case 1:
                    printf("ranking");
                    break;
                case 2:
                    exit(0);
                    break;
                }
            }
            relogio.restart();
        }
        imprimir_se(0);
        gerenciador_grafico->mostrarConteudo();
    }
    return;
}

//=====================================================================================================//

void Menu::MostraFases(){
    n.reiniciar();
    n.setMax(4);
    sf::Clock relogio;
    fases[n.getContador()].setOutlineThickness(GROSSURA);

    gerenciador_grafico->limpaJanela();
    while(gerenciador_grafico->verificaJanelaAberta()){
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        gerenciador_grafico->limpaJanela();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
               n--;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
                n++;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                case 0:
                    executar();
                    break;
                case 1:
                    fase2->executar();
                    break;
                case 2:
                    fase1->executar();
                    break;
                case 3:
                    printf("carregar");
                    break;
                }
            }
            relogio.restart();
        }
        imprimir_se(1);
        gerenciador_grafico->mostrarConteudo();
    }
    return;
}

void Menu::imprimir_se(int tela){
   switch(tela){
        case 0:
            gerenciador_grafico->desenhaElemento(text,3);
            break;
        case 1:
            gerenciador_grafico->desenhaElemento(fases,4);
            break;
    }
    return;
}
