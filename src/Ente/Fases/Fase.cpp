#include "../../../include/Ente/Fases/Fase.h"

using namespace Fases;


Fase::Fase(unsigned int numJogadores){
    this->numJogadores=numJogadores;
    fundo.setSize(sf::Vector2f(1280.f,720.f));
    fundo.setOrigin(sf::Vector2f(1280/2.f,720/2.f));
    this->carregar = carregar;
    jogador1= NULL;
    jogador2= NULL;
}




Fase::~Fase()
{
    personagens.limparLista();
    obstaculos.limparLista();
    jogador1=NULL;
    jogador2=NULL;
}

void Fase::executar()
{
        gerenciador_grafico->limpaJanela();
        while (gerenciador_grafico->verificaJanelaAberta()) {
            sf::Event evento;
            if (gerenciador_grafico->getWindow()->pollEvent(evento)) {
                if (evento.type == sf::Event::Closed)
                    gerenciador_grafico->fecharJanela();

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                gerenciador_grafico->viewMenu();
                return;
            }
            gerenciador_grafico->limpaJanela();
            gerenciador_grafico->desenhaElemento(fundo);
            personagens.executarEntidades();
            obstaculos.executarEntidades();
            gerenciador_colisoes.executar();
            gerenciador_grafico->AttView(jogador1->getPosicao().x + 150, jogador1->getPosicao().y + visao, &fundo);
            gerenciador_grafico->mostrarConteudo();

        }
}

void Fase::gerarMundo() {
    getNome();
    gerenciador_colisoes.setListaPersonagens(&personagens);
    gerenciador_colisoes.setListaObstaculos(&obstaculos);

    inserirJogadores();
    if (jogador2 != NULL)
        personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador2));
    personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador1));
    inserirPisos();
    inserirInimigos();
}

void Fase::salvarJogo() {
    limpaArquivos();
    salvarFase();
}

void Fase::limpaArquivos() {
    std::ofstream arquivoFase("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Fase.txt");
    arquivoFase.clear();
    arquivoFase.close();

    std::ofstream arquivoJogadores("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Jogadores.txt");
    arquivoJogadores.clear();
    arquivoJogadores.close();

    std::ofstream arquivoBoitatas("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Boitatas.txt");
    std::ofstream arquivoCaveiras("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Caveiras.txt");
    std::ofstream arquivoCogumalefico("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Cogumalefico.txt");
    arquivoBoitatas.clear();
    arquivoCaveiras.clear();
    arquivoCogumalefico.clear();
    arquivoBoitatas.clear();
    arquivoCaveiras.clear();
    arquivoCogumalefico.clear();

    std::ofstream arquivoEspinhos("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Espinhos.txt");
    std::ofstream arquivoNinhos("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Ninhos.txt");
    std::ofstream arquivoPisos("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Pisos.txt");
    std::ofstream arquivoPlataformas("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Plataformas.txt");
    arquivoEspinhos.clear();
    arquivoNinhos.clear();
    arquivoPisos.clear();
    arquivoPlataformas.clear();
    arquivoEspinhos.close();
    arquivoNinhos.close();
    arquivoPisos.close();
    arquivoPlataformas.close();

    std::ofstream arquivoProjeteis("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Projeteis.txt");
    arquivoProjeteis.clear();
    arquivoProjeteis.close();
}


void Fase::salvarFase() {
    std::ofstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Fase.txt", std::ios::out);

    arquivo<<fase<<" "<<numJogadores;
    arquivo.close();

    salvarPersonagens();
    salvarObstaculos();
}

void Fase::salvarPersonagens() {
    int i;
    for(i=0; i<personagens.getTamanho(); i++){
        personagens[i]->salvarPosicao();
    }
}

void Fase::salvarObstaculos() {
    int i;
    for(i=0; i<obstaculos.getTamanho(); i++){
        obstaculos[i]->salvarPosicao();
    }
}

void Fase::carregarFase() {

    gerenciador_colisoes.setListaPersonagens(&personagens);
    gerenciador_colisoes.setListaObstaculos(&obstaculos);

    carregarJogadores();
    if (jogador2 != NULL)
        personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador2));
    personagens.inserirEntidade(static_cast<Entidades::Entidade *>(jogador1));

    carregarObstaculos();
    carregarPersonagens();
}

void Fase::carregarPersonagens() {
    carregarCaveiras();
    carregarBoitatas();
    carregarCogumalefico();
}

void Fase::carregarJogadores() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Jogadores.txt", std::ios::in);
    bool executa;
    int pontuacao;
    float pX, pY;
    arquivo>>pontuacao;
    arquivo>>executa>>pX>>pY;
    jogador1 = new Entidades::Jogador1(pX, pY);
    jogador1->setExecutar(executa);
    jogador1->setPontos(pontuacao);

    if(arquivo>>executa>>pX>>pY){
        jogador2 = new Entidades::Jogador2(pX, pY);
        jogador2->setExecutar(executa);
   }

}

void Fase::carregarCaveiras(){
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Caveiras.txt", std::ios::in);
    bool executa;
    int pX, pY;

    while(arquivo>>executa>>pX>>pY){
        Entidades::Entidade* entidade = static_cast<Entidades::Entidade*>(new Entidades::Caveira(pX,pY,jogador1,jogador2));
        entidade->setExecutar(executa);
        personagens.inserirEntidade(entidade);
    }

}
void Fase::carregarBoitatas(){
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Boitatas.txt", std::ios::in);
    bool executa;
    int pX, pY;

    while(arquivo>>executa>>pX>>pY){
        Entidades::Entidade* entidade = static_cast<Entidades::Entidade*>(new Entidades::Boitata(pX,pY,jogador1,jogador2));
        entidade->setExecutar(executa);
        personagens.inserirEntidade(entidade);
    }

}
void Fase::carregarCogumalefico(){
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Cogumalefico.txt", std::ios::in);
    bool executa;
    int pX, pY;

    if(arquivo>>executa>>pX>>pY){
        Entidades::Entidade* entidade = static_cast<Entidades::Entidade*>(new Entidades::Cogumalefico(pX,pY,jogador1,jogador2));
        entidade->setExecutar(executa);
        personagens.inserirEntidade(entidade);
    }

}

void Fase::carregarObstaculos() {
    carregarPisos();
    carregarPlataformas();
    carregarEspinhos();
    carregarNinhos();
}

void Fase::carregarPisos() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Pisos.txt", std::ios::in);
    int tamanho;
    int pX, pY;

    while(arquivo>>tamanho>>pX>>pY){
        inserirPi(tamanho, pX, pY);
    }

}

void Fase::carregarPlataformas() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Plataformas.txt", std::ios::in);
    int nivel;
    int pX, pY;

    while(arquivo>>nivel>>pX>>pY){
        obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(pX,pY,nivel)));
    }

}

void Fase::carregarEspinhos() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Espinhos.txt", std::ios::in);
    int pX, pY;

    while(arquivo>>pX>>pY){
        inserirE(pX,pY);
    }
}

void Fase::carregarNinhos() {
    std::ifstream arquivo("C:\\Users\\bruno\\github\\Jogo-TecProg\\save\\Ninhos.txt", std::ios::in);
    bool executa;
    int pX, pY;

    while(arquivo>>executa>>pX>>pY){
        Entidades::Entidade* entidade = static_cast<Entidades::Entidade*>(new Entidades::Ninho(pX,pY,jogador1,jogador2));
        entidade->setExecutar(executa);
        obstaculos.inserirEntidade(entidade);
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


void Fase::inserirJogadores(){
    jogador1=  new Entidades::Jogador1(50, 120);
    if(numJogadores==2) {
        jogador2 = new Entidades::Jogador2(60, 120);
    }
}

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
















