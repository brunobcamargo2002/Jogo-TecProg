#ifndef ENTE_H
#define ENTE_H

#include "../Gerenciadores/Gerenciador_Grafico.h"
class Ente
{
    protected:
            unsigned int id;
            static Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        virtual void imprimir_se();
};




#endif // ENTE_H
