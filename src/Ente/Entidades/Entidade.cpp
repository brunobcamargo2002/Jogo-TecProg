#include "../../../include/Ente/Entidades/Entidade.h"

using namespace Entidades;

Entidade::Entidade()
{
    //ctor
}

Entidade::~Entidade()
{
    //dtor
}

void Entidade::imprimir_se() {
    gerenciador_grafico->desenhaElemento(corpo);
}

