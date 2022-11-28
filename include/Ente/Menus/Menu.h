#ifndef MENU_H
#define MENU_H
#include "../../Ente/Ente.h"
#include "../Fases/Fase.h"
using namespace Gerenciadores;
using namespace Fases;

class Menu:protected Ente
{
    private:
    sf::Text text[3];
    sf::Text opcoes[4];
    sf::Text fases[4];
    sf::Text opcoesInGame[3];
    sf::Text Ranking[1];
    sf::Font font;
    Fase* fase;
    class Contador{
        private:
            int numero;
            int Max;
        public:
            Contador(int Max){numero=0; this->Max= Max-1;};
            ~Contador(){};
            void reiniciar(){numero=0;};
            void operator++(int){
                numero++;
                if(numero>Max)
                    numero=0;};
            void operator--(int){
                numero--;
                if(numero<0)
                    numero=Max;};
            int getContador(){return numero;};
            int setMax(int M){Max = M-1;};
    };
    Contador n;
    public:
    Menu();
    ~Menu();
    void executar();
    void mostraOpcoes();
    void MostraFases(unsigned int jogadores);
    void menuFase();
    void acoesFase(int action);
    void imprimir_se(int tela);
    std::string setNome();
    void salvarRanking();
    void mostraRanking();



    Fase* carregarJogo();
};

#endif // MENU_H
