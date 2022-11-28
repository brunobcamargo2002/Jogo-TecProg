#include "../../../include/Ente/Menus/Menu.h"
#include "../../../include/Ente/Fases/Pantano.h"
#include "../../../include/Ente/Fases/Floresta.h"

Menu::Menu():n(3){
    fase = NULL;
    gerenciador_grafico->limpaJanela();
    if (!font.loadFromFile("04B_30__.TTF")){
        printf("error abrindo fonte");}

    for(int i=0;i<3;i++){text[i].setFont(font);}

    for(int i=0; i<4; i++){opcoes[i].setFont(font);}

    for(int i=0;i<3;i++){fases[i].setFont(font);}

    for(int i=0;i<3;i++){opcoesInGame[i].setFont(font);}

    Ranking[0].setFont(font);

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

    Ranking[0].setString("Voltar");

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
    Ranking[0].setCharacterSize(28);
    Ranking[0].setFillColor(sf::Color::White);
    Ranking[0].setOutlineColor(sf::Color::Red);
    Ranking[0].setPosition(600.f,650.f);
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
                    mostraRanking();
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
        int acao;
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
                            acao = fase->executarFase();
                            acoesFase(acao);
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
        int acao;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                case 0:
                    mostraOpcoes();
                    break;
                case 1:
                    fase = new Floresta(jogadores);
                    fase->gerarMundo();
                    acao = fase->executarFase();
                    acoesFase(acao);
                    break;
                case 2:
                    fase = new Pantano(jogadores);
                    fase->gerarMundo();
                    acao = fase->executarFase();
                    acoesFase(acao);
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
        int acao;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                switch(n.getContador()){
                    case 0:
                        acao = fase->executarFase();
                        acoesFase(acao);
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
        case 4:
            gerenciador_grafico->desenhaElemento(Ranking, 1);
    }
    return;
}

Fase* Menu::carregarJogo() {
    std::ifstream arquivo("save/Fase.txt", std::ios::in);
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

std::string Menu::setNome() {
    sf::RenderWindow* window = gerenciador_grafico->getWindow();
    std::string input_text;
    sf::Font font;
    font.loadFromFile("04B_30__.TTF");
    sf::Text text("", font);

    sf::Clock clock;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::TextEntered) {
                if (std::isprint(event.text.unicode))
                    input_text += event.text.unicode;
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::BackSpace) {
                    if (!input_text.empty())
                        input_text.pop_back();
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            return input_text;
        }

        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        text.setString(input_text + (show_cursor ? '_' : ' '));

        window->clear();
        window->draw(text);
        window->display();
    }

}

/**Todos os creditos ao ex-monitor Mateus Burda**/
void Menu::salvarRanking() {
    std::string nome= setNome();
    int pontos = Entidades::Jogador::getPontos();
    std::ifstream arquivo("Ranking.txt", std::ios::in);

    std::multimap<int, std::string> pontosENomes;

    if (arquivo) {
        unsigned int pontos2;
        std::string nome2;
        std::string stringPontos;

        for (int i = 0; i < 10; i++) {
            std::getline(arquivo, stringPontos);
            std::getline(arquivo, nome2);
            if (stringPontos.length() > 0)
                pontosENomes.insert(std::pair<int, std::string>(std::stoi(stringPontos), nome2));
        }
        arquivo.close();
    }

    if (pontos != 0 && nome.length() > 1)
        pontosENomes.insert(std::pair<int, std::string>(pontos, nome));

    std::ofstream arquivoSaida("Ranking.txt", std::ios::trunc);

    if (!arquivoSaida) {
        std::cout << "Erro ao escrever o arquivo ranking" << std::endl;
        exit(1);
    }

    while (pontosENomes.size() > 10)
        pontosENomes.erase(pontosENomes.begin());

    for (auto itr = pontosENomes.rbegin(); itr != pontosENomes.rend(); ++itr) {
        arquivoSaida << (*itr).first << std::endl;
        arquivoSaida << (*itr).second << std::endl;
    }

    arquivoSaida.close();
}

void Menu::acoesFase(int action) {
    if(action==1)
        menuFase();
    else if(action==2)
        salvarRanking();
    else if(action==3){
        if(fase->getFase()==1){
            int numJogadores=fase->getNumJogadores();
            delete fase;
            fase = new Pantano(numJogadores);
            fase->gerarMundo();
            action = fase->executarFase();
            if(action==1)
                menuFase();
            else if(action==2 || action==3)
                salvarRanking();
        }
        else{
            salvarRanking();
            delete fase;
        }

    }

}

void Menu::mostraRanking() {
    std::string aux;
    sf::Text posicoes[10];
    sf::Text nomes[10];
    sf::Text pontuacao[10];
    for(int i=0; i<10; i++) {
        posicoes[i].setFont(font);
        nomes[i].setFont(font);
        pontuacao[i].setFont(font);
        aux=i+48;
        posicoes[i].setString(aux);
    }
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\Ranking.txt", std::ios::in);

    std::string pontos;
    std::string nome;
    int i=0;
    while(arquivo>>pontos){
        arquivo>>nome;
        aux= pontos;
        pontuacao[i].setString(aux);
        nomes[i].setString(nome);
        i++;
    }
    for(i ; i<10 ; i++){
        pontuacao[i].setString("---");
        nomes[i].setString("-----");
    }
    for(i=0 ; i<10; i++) {
        posicoes[i].setCharacterSize(28);
        posicoes[i].setFillColor(sf::Color::Yellow);
        posicoes[i].setOutlineColor(sf::Color::White);
        posicoes[i].setPosition(50.f, 200.f+i*50);
    }

    for(i=0 ; i<10; i++) {
        nomes[i].setCharacterSize(28);
        nomes[i].setFillColor(sf::Color::Yellow);
        nomes[i].setOutlineColor(sf::Color::White);
        nomes[i].setPosition(200.f, 200.f+i*50);
    }

    for(i=0 ; i<10; i++) {
        pontuacao[i].setCharacterSize(28);
        pontuacao[i].setFillColor(sf::Color::Yellow);
        pontuacao[i].setOutlineColor(sf::Color::White);
        pontuacao[i].setPosition(500.f, 200.f+i*50);
    }

    sf::Clock relogio;
    Ranking[0].setOutlineThickness(GROSSURA);
    while(gerenciador_grafico->verificaJanelaAberta()) {
        gerenciador_grafico->limpaJanela();
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (relogio.getElapsedTime().asSeconds() > INTERVALO)
                executar();
            relogio.restart();
        }
        imprimir_se(4);
        gerenciador_grafico->desenhaElemento(posicoes, 10);
        gerenciador_grafico->desenhaElemento(nomes, 10);
        gerenciador_grafico->desenhaElemento(pontuacao, 10);
        gerenciador_grafico->mostrarConteudo();

    }
}




