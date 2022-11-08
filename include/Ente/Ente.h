#ifndef ENTE_H
#define ENTE_H

#include "../Gerenciadores/Gerenciador_Grafico.h"
class Ente
{
    private:
        static unsigned int geraId;
        unsigned int id;


    protected:
            Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        virtual void imprimir_se()=0;
};




#endif // ENTE_H
