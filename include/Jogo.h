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
#include "Ente/Fases/Pantano.h"
#include "Ente/Fases/Floresta.h"


class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
    Menu menu;
public:
    Jogo();
    virtual ~Jogo();

    void executar();

};

#endif // JOGO_H
