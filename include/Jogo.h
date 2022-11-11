#ifndef JOGO_H
#define JOGO_H

#include "SFML/Graphics.hpp"

#include "Ente/Entidades/Personagens/Jogador.h"
#include "Ente/Entidades/Personagens/Inimigo.h"
#include "Ente/Entidades/Obstaculos/Obst_TipoA.h"
#include "Listas/ListaEntidades.h"

#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
class Jogo
{
    private:
        Entidades::Jogador jogador1;
        Entidades::Inimigo inimigo1;
        Entidades::Obst_TipoA obstaculo;
        Listas::ListaEntidades personagens;
        Listas::ListaEntidades obstaculos;


        Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
        Gerenciadores::Gerenciador_Colisoes gerenciador_colisoes;
    public:
        Jogo();
        virtual ~Jogo();

        void executar();
};

#endif // JOGO_H
