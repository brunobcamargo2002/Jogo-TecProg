//
// Created by bruno on 14/11/2022.
//

#include "../../include/Animacao/Animacao.h"

Animacao::Animacao(sf::RectangleShape* corpo):
corpo(corpo), imagens(), imgAtual(""), relogio()
{
}

Animacao::~Animacao(){
    std::map<std::string, Imagem*>::iterator it = imagens.begin();
    while(it != imagens.end()){
        if(it->second){
            delete(it->second);
            it->second = nullptr;
        }
        it++;
    }
    imagens.clear();
}

void Animacao::atualizar(const bool paraEsquerda, std::string imgAtual){
    if(this->imgAtual != imgAtual){
        if(!this->imgAtual.empty()){
            imagens[this->imgAtual]->resetar();
        }
        this->imgAtual = imgAtual;
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();

    Imagem* img = imagens[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2f escala = img->getEscala();

    img->atualizar(paraEsquerda, dt);
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(escala.x, escala.y);
}

void Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroca, escala);
    imagens.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}