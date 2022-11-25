#ifndef FASE_H
#define FASE_H

#include "../Ente.h"
#include "SFML/Graphics.hpp"

#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"
#include "../Entidades/Obstaculos/Ninho.h"
#include "../Entidades/Obstaculos/Piso.h"
#include "../Entidades/Personagens/Caveira.h"
#include "../Entidades/Personagens/Boitata.h"
#include "../Entidades/Personagens/Cogumalefico.h"

namespace Fases {

    class Fase : public Ente {
    protected:
        int fase;
        sf::RectangleShape fundo;
        sf::Texture* tfundo;
        Entidades::Jogador* jogador1;
        Entidades::Jogador* jogador2;
        Listas::ListaEntidades personagens;
        Listas::ListaEntidades obstaculos;
        Gerenciadores::Gerenciador_Colisoes* gerenciador_colisoes;
        int visao;
    public:
        Fase();

        Fase(Entidades::Jogador* jg,Entidades::Jogador* jg2,Gerenciadores::Gerenciador_Colisoes* gc);

        virtual ~Fase();

        void executar();

        virtual void inserirPisos();

        virtual void inserirPlataformas(int n);

        virtual void inserirEspinhos(int n);

        virtual void inserirNinhos(int n);

        void inserirPi(int tam,int x,int y);

        void inserirPla(int x,int y,int nivel);

        void inserirE(int x,int y);

        void inserirN(int x,int y);

        virtual void inserirInimigos();

        virtual void inserirInimigos1(int n);

        virtual void inserirInimigos2(int n);

        virtual void inserirChefes(int n);

        void inserirI1(int x,int y);

        void inserirI2(int x,int y);

        void inserirC(int x,int y);

        void getNome();

        void setTextura(const char* caminho);
    };
}
#define TelaX 1280
#define TelaY 720

#endif // FASE_H
