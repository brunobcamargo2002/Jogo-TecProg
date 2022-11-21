#include <iostream>

using namespace std;
#include <SFML/Graphics.hpp>
#include "include/Jogo.h"
int main()
{
    srand((unsigned)time(NULL));
    Jogo teste;
    teste.executar();

    return 0;
}
