#ifndef FASE_H
#define FASE_H

#include "../Ente.h"
#include "SFML/Graphics.hpp"

#include "../Entidades/Personagens/Jogador1.h"
#include "../Entidades/Personagens/Jogador2.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Personagens/Caveira.h"
#include "../Entidades/Personagens/Boitata.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"
#include "../Entidades/Obstaculos/Ninho.h"
#include "../Entidades/Obstaculos/Piso.h"
#include "../Entidades/Projetil.h"

namespace Fases {

    class Fase : public Ente {
    private:
        Entidades::Boitata boitata;
        Entidades::Caveira caveira;
        Entidades::Jogador1* jogador1;
        Entidades::Jogador2* jogador2;
        Listas::ListaEntidades personagens;
        Listas::ListaEntidades obstaculos;
        Gerenciadores::Gerenciador_Colisoes* gerenciador_colisoes;

    public:
        Fase(Entidades::Jogador1* jg, Entidades::Jogador2* jg2, Gerenciadores::Gerenciador_Colisoes* gc,int obs1,int obs2,int obs3,int tam);

        virtual ~Fase();

        void gerenciar_colisoes();

        virtual void executar();
    };

}

#endif // FASE_H
