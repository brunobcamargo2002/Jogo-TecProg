#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include <iostream>

#include "SFML/Graphics.hpp"

#include "string.h"
//Foi utilizado o padrão Singleton, ou seja, só haverá 1 instância Gerenciador_grafico e esta terá acesso global.


namespace Gerenciadores {

    class Gerenciador_Grafico {
    private:
        sf::RenderWindow *janela;
        std::map<const char*, sf::Texture*> texturas;
        Gerenciador_Grafico();

        //singleton
        static Gerenciador_Grafico *instancia;
    public:
        static Gerenciador_Grafico *getInstancia();

        virtual ~Gerenciador_Grafico();

        sf::RenderWindow* getWindow();
        void desenhaElemento(sf::RectangleShape conteudo);
        void desenhaElemento(sf::Text* conteudo,int n);
        void limpaJanela();
        void fecharJanela();
        void mostrarConteudo() const;
        const bool verificaJanelaAberta();
        sf::Texture* carregarTextura(const char* caminho);



    protected:

    private:
    };

}

#endif // GERENCIADOR_GRAFICO_H
