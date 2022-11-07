#ifndef ENTE_H
#define ENTE_H

#include "../Gerenciadores/Gerenciador_Grafico.h"
class Ente
{
    private:
        Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
        static unsigned int geraId;


    protected:
            unsigned int id;
    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        void imprimir_se();
};




#endif // ENTE_H
