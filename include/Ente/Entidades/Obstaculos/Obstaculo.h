#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "../Entidade.h"

namespace Entidades {

class Obstaculo : public Entidade
{
protected:
    sf::Texture* textura;
public:
    Obstaculo(sf::Vector2f posicao, sf::Vector2f tamanho, const char *caminho);
    virtual ~Obstaculo();
    void executar();
    void colisao(sf::Vector2f deslocamento, Entidades::Entidade* entidade){};
    void setTextura(const char* caminho);

};
}

#endif // OBSTACULO_H
