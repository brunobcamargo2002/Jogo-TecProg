#ifndef JOGO_H
#define JOGO_H

#include "SFML/Graphics.hpp"

#include "Ente/Entidades/Personagens/Jogador1.h"
#include "Ente/Entidades/Personagens/Jogador2.h"
#include "Ente/Entidades/Personagens/Inimigo.h"
#include "Ente/Entidades/Obstaculos/Plataforma.h"
#include "Ente/Entidades/Obstaculos/Ninho.h"
#include "Ente/Entidades/Obstaculos/Espinhos.h"
#include "Listas/ListaEntidades.h"
#include "Ente/Fases/Fase.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Ente/Menus/Menu.h"
#include "Ente/Fases/Floresta.h"
#include "Ente/Fases/Pantano.h"


class Jogo
{
private:
    Entidades::Jogador1 jogador;
    Entidades::Jogador2 jogador2;

    //Listas::ListaEntidades personagens;
    //Listas::ListaEntidades obstaculos;
    Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
    Gerenciadores::Gerenciador_Colisoes gerenciador_colisoes;
    Fases::Pantano fase2;
    Fases::Floresta fase1;
    Menu menu;
public:
    Jogo();
    virtual ~Jogo();

    void executar();

    void executaFase();
};

#endif // JOGO_H
