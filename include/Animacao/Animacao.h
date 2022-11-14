//
// Created by bruno on 14/11/2022.
//

#ifndef JOGO_ANIMACAO_H
#define JOGO_ANIMACAO_H

#include "Imagem.h"

#include <map>
/*Todos os créditos ao monitor de Técnicas de Programação Giovani
github : https://github.com/Giovanenero
youtube: https://www.youtube.com/channel/UCUa8BOx2F3hlxgPcpZmnBnQ
 */

class Animacao {
private:
    sf::RectangleShape* corpo;
    std::map<std::string, Imagem*> imagens;
    sf::Clock relogio;
    std::string imgAtual;

public:
    Animacao(sf::RectangleShape* corpo=NULL);
    ~Animacao();
    void atualizar(const bool paraEsquerda, std::string imgAtual);
    void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImg, const float tempoTroca, const sf::Vector2f escala);

};


#endif //JOGO_ANIMACAO_H
