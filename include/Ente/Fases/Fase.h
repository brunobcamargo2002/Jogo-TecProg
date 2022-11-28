#ifndef FASE_H
#define FASE_H

#include "../Ente.h"
#include "SFML/Graphics.hpp"

#include <fstream>

#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Jogador1.h"
#include "../Entidades/Personagens/Jogador2.h"
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
        unsigned int numJogadores;
        sf::RectangleShape fundo;
        sf::Texture* tfundo;
        Entidades::Jogador* jogador1;
        Entidades::Jogador* jogador2;
        Listas::ListaEntidades personagens;
        Listas::ListaEntidades obstaculos;
        Gerenciadores::Gerenciador_Colisoes gerenciador_colisoes;
        int visao;
        bool carregar;

        Entidades::Cogumalefico* chefao;
    public:

        Fase(unsigned int numJogadores=1);


        void gerarMundo();

        void limpaArquivos();

        void salvarJogo();
        void salvarFase();
        void salvarPersonagens();
        void salvarObstaculos();
        void carregarFase();

        void carregarJogadores();
        void carregarPersonagens();
        void carregarCaveiras();
        void carregarBoitatas();
        void carregarCogumalefico();

        void carregarObstaculos();
        void carregarPisos();
        void carregarPlataformas();
        void carregarEspinhos();
        void carregarNinhos();

        virtual bool fimDaFase()=0;

        int getFase();
        int getNumJogadores();






        virtual ~Fase();

        void executar();

        int executarFase();

        virtual void inserirPisos();

        virtual void inserirPlataformas(int n);

        virtual void inserirEspinhos(int n);

        virtual void inserirNinhos(int n);

        void inserirPi(int tam,int x,int y);

        void inserirPla(int x,int y,int nivel);

        void inserirE(int x,int y);

        void inserirN(int x,int y);

        void inserirJogadores();

        virtual void inserirInimigos()=0;

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
