#include "../../include/Ente/Ente.h"


/**static**/
unsigned int Ente::geraId=0;

Ente::Ente()
{
    id = geraId;
    geraId++;
}

Ente::~Ente()
{

}

void Ente::executar()
{

}

void Ente::imprimir_se()
{

}
