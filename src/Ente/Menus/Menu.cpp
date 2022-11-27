#include "../../../include/Ente/Menus/Menu.h"
#include "../../../include/Ente/Fases/Pantano.h"
#include "../../../include/Ente/Fases/Floresta.h"

Menu::Menu():n(3){
    fase = NULL;
    gerenciador_grafico->limpaJanela();
    if (!font.loadFromFile("C:\\ODIABO\\Jogo-TecProg-main\\arial.TTF")){
        printf("error abrindo fonte");}

    for(int i=0;i<3;i++){text[i].setFont(font);}

    for(int i=0; i<4; i++){opcoes[i].setFont(font);}

    for(int i=0;i<3;i++){fases[i].setFont(font);}

    for(int i=0;i<3;i++){opcoesInGame[i].setFont(font);}

    text[0].setString("Jogar");
    text[1].setString("Rank");
    text[2].setString("Sair");

    opcoes[0].setString("Voltar");
    opcoes[1].setString("1 Jogador");
    opcoes[2].setString("2 Jogadores");
    opcoes[3].setString("Carregar Jogo");

    fases[0].setString("Voltar");
    fases[1].setString("Floresta");
    fases[2].setString("Pantano");

    opcoesInGame[0].setString("Voltar");
    opcoesInGame[1].setString("Salvar");
    opcoesInGame[2].setString("Menu");

    for(int i=0;i<3;i++){
        text[i].setCharacterSize(32);
        text[i].setFillColor(sf::Color::White);
        text[i].setOutlineColor(sf::Color::Red);
        text[i].setPosition(200.f,(1+i)*150.f);
    }

    for(int i=0; i<4; i++){
        opcoes[i].setCharacterSize(28);
        opcoes[i].setFillColor(sf::Color::White);
        opcoes[i].setOutlineColor(sf::Color::Red);
        opcoes[i].setPosition(200.f,50+(1+i)*100.f);
    }

    for(int i=0;i<3;i++){
        fases[i].setCharacterSize(28);
        fases[i].setFillColor(sf::Color::White);
        fases[i].setOutlineColor(sf::Color::Red);
        fases[i].setPosition(200.f,50+(1+i)*100.f);
    }

    for(int i=0;i<3;i++){
        opcoesInGame[i].setCharacterSize(28);
        opcoesInGame[i].setFillColor(sf::Color::White);
        opcoesInGame[i].setOutlineColor(sf::Color::Green);
        opcoesInGame[i].setPosition(200.f,50+(1+i)*100.f);
    }
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
                    mostraOpcoes();
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

void Menu::mostraOpcoes() {
    n.reiniciar();
    n.setMax(4);
    sf::Clock relogio;
    opcoes[n.getContador()].setOutlineThickness(GROSSURA);

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
                opcoes[n.getContador()].setOutlineThickness(0);
                n--;
                opcoes[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                opcoes[n.getContador()].setOutlineThickness(0);
                n++;
                opcoes[n.getContador()].setOutlineThickness(GROSSURA);
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
                        MostraFases(1);
                        break;
                    case 2:
                        MostraFases(2);
                        break;
                    case 3:
                        fase = carregarJogo();
                        if(fase!=NULL) {
                            fase->carregarFase();
                            fase->executar();
                            menuFase();
                        }

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

//=====================================================================================================//

void Menu::MostraFases(unsigned int jogadores){
    n.reiniciar();
    n.setMax(3);
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
                    mostraOpcoes();
                    break;
                case 1:
                    fase = new Floresta(jogadores);
                    fase->gerarMundo();
                    fase->executar();
                    menuFase();
                    break;
                case 2:
                    fase = new Pantano(jogadores);
                    fase->gerarMundo();
                    fase->executar();
                    menuFase();
                    break;

                }
            }
            relogio.restart();
        }
        imprimir_se(2);
        gerenciador_grafico->mostrarConteudo();
    }
    return;
}

void Menu::menuFase() {
    n.reiniciar();
    n.setMax(3);
    sf::Clock relogio;
    opcoesInGame[n.getContador()].setOutlineThickness(GROSSURA);

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
                opcoesInGame[n.getContador()].setOutlineThickness(0);
                n--;
                opcoesInGame[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                opcoesInGame[n.getContador()].setOutlineThickness(0);
                n++;
                opcoesInGame[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                    case 0:
                        fase->executar();
                        break;
                    case 1:
                        fase->salvarJogo();
                        break;
                    case 2:
                        delete fase;
                        executar();
                        break;

                }
            }
            relogio.restart();
        }
        imprimir_se(3);
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
            gerenciador_grafico->desenhaElemento(opcoes,4);
            break;
        case 2:
           gerenciador_grafico->desenhaElemento(fases,4);
           break;
        case 3:
            gerenciador_grafico->desenhaElemento(opcoesInGame, 3);
    }
    return;
}

Fase* Menu::carregarJogo() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Fase.txt", std::ios::in);
    unsigned int fase=-1;
    unsigned int numJogadores=-1;
    arquivo>>fase>>numJogadores;
    if((fase!=1 && fase!=2) || (numJogadores!=1 && numJogadores!=2))
        return NULL;

    if(fase==1)
        return static_cast<Fase*> (new Floresta(numJogadores));
    else if(fase==2)
        return static_cast<Fase*> (new Pantano(numJogadores));
}




