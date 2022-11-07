#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include <iostream>

#include "SFML/Graphics.hpp"
//Foi utilizado o padrão Singleton, ou seja, só haverá 1 instância Gerenciador_grafico e esta terá acesso global.


namespace Gerenciadores {

    class Gerenciador_Grafico {
    private:
        sf::RenderWindow *janela;
        Gerenciador_Grafico();

        //singleton
        static Gerenciador_Grafico *instancia;
    public:
        static Gerenciador_Grafico *getInstancia();

        virtual ~Gerenciador_Grafico();

        sf::RenderWindow* getWindow();
        void desenhaElemento(sf::RectangleShape conteudo);
        void limpaJanela();
        void fecharJanela();
        void mostrarConteudo() const;
        const bool verificaJanelaAberta();
        const bool verificaEvento(sf::Event evento);



    protected:

    private:
    };

}

#endif // GERENCIADOR_GRAFICO_H
