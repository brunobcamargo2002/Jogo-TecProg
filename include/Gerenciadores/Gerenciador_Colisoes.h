#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include "../Ente/Entidades/Personagens/Inimigo.h"
#include "../Ente/Entidades/Obstaculos/Obstaculo.h"

#include "../Listas/ListaEntidades.h"
#include <vector>

namespace Gerenciadores {

    class Gerenciador_Colisoes {
    private:
        Listas::ListaEntidades* LPersonagens;
        Listas::ListaEntidades* LObstaculos;
    public:
        Gerenciador_Colisoes();
        Gerenciador_Colisoes(Listas::ListaEntidades* ListaPersonagens ,Listas::ListaEntidades* ListaObstaculos);
        void verificaColisaoEntrePersonagens();
        void verificaColisaoEntrePersonagensEObstaculos();
        const sf::Vector2f calculaColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2);
        void executar();

        virtual ~Gerenciador_Colisoes();

    protected:
    };

}
#endif // GERENCIADOR_COLISOES_H
