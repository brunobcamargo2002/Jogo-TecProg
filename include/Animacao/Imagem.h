//
// Created by bruno on 14/11/2022.
//

#ifndef JOGO_IMAGEM_H
#define JOGO_IMAGEM_H

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/Gerenciador_Grafico.h"

/*Todos os créditos ao monitor de Técnicas de Programação Giovani
github : https://github.com/Giovanenero
youtube: https://www.youtube.com/channel/UCUa8BOx2F3hlxgPcpZmnBnQ
 */

class Imagem {
private:
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    sf::Texture* textura;
    sf::IntRect tamanho;
    const sf::Vector2f escala;
    const unsigned int qtdImagem;
    unsigned int imgAtual;
    const float tempoTroca;
    float tempoTotal;

public:
    Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
    ~Imagem();
    void atualizar(const bool paraEsquerda, const float dt);
    void resetar();
    const sf::IntRect getTamanho() const;
    const sf::Texture* getTextura() const;
    const sf::Vector2f getEscala() const;


};


#endif //JOGO_IMAGEM_H
