#include "../../include/Gerenciadores/Gerenciador_Grafico.h"
using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::instancia = NULL;
Gerenciador_Grafico* Gerenciador_Grafico::getInstancia()
{
    if(instancia==NULL)
    {
        instancia = new Gerenciador_Grafico;
    }
    return instancia;
}



Gerenciador_Grafico::Gerenciador_Grafico()
{
    //ctor
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
    //dtor
}
