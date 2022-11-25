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
    sf::Text fases[4];
    sf::Font font;
    Fase* fase1;
    Fase* fase2;
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
    Menu(Fase* f1=NULL,Fase* f2=NULL);
    ~Menu();
    void executar();
    void MostraFases();
    void imprimir_se(int tela);
    void setNome();
};

#endif // MENU_H
