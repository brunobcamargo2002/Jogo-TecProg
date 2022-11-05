#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include "../Ente/Entidades/Personagens/Inimigo.h"
#include "../Ente/Entidades/Obstaculos/Obstaculo.h"

#include <vector>
#include <list>

namespace Gerenciadores {

    class Gerenciador_Colisoes {
    public:
        Gerenciador_Colisoes();

        virtual ~Gerenciador_Colisoes();

    protected:

    private:
        std::vector<Entidades::Inimigo *> LIs;
        std::vector<Entidades::Obstaculo *> LOs;
    };

}
#endif // GERENCIADOR_COLISOES_H
