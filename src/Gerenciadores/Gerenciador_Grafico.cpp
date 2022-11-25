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


#define TelaX 1280
#define TelaY 720


Gerenciador_Grafico::Gerenciador_Grafico():
janela(new sf::RenderWindow(sf::VideoMode(TelaX, TelaY), "Jogo")),
view(new sf::View(sf::FloatRect(TelaX/2, TelaY/2, TelaX, TelaY)))
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

void Gerenciador_Grafico::desenhaElemento(sf::Text* conteudo,int n) {
    for(int i=0;i<n;i++){janela->draw(conteudo[i]);}
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

sf::Texture *Gerenciador_Grafico::carregarTextura(const char* caminho) {
    std::map<const char*, sf::Texture*>::iterator it = texturas.begin();
    while (it != texturas.end()) {
        if (!strcmp(it->first, caminho))
            return it->second;
        it++;
    }

    /* If not found, must load it. */
    sf::Texture* tex = new sf::Texture();

    if (!tex->loadFromFile(caminho)) {
        std::cerr << "Erro ao carregar a textura. " << caminho << std::endl;
        exit(1);
    }

    texturas.insert(std::pair<const char*, sf::Texture*>(caminho, tex));

    return tex;
}

void Gerenciador_Grafico::AttView(float Px,float Py,sf::RectangleShape* fundo){
    view->setCenter(Px, Py);
    janela->setView(*view);
    fundo->setPosition(Px,Py);
}
