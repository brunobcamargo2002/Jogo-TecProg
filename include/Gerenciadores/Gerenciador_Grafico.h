#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include "SFML/Graphics.hpp"
//Foi utilizado o padrão Singleton, ou seja, só haverá 1 instância Gerenciador_grafico e esta terá acesso global.


namespace Gerenciadores {

    class Gerenciador_Grafico {
    private:
        sf::RenderWindow *window;
        Gerenciador_Grafico();

        //singleton
        static Gerenciador_Grafico *instancia;
    public:
        static Gerenciador_Grafico *getInstancia();

        virtual ~Gerenciador_Grafico();

    protected:

    private:
    };

}

#endif // GERENCIADOR_GRAFICO_H
