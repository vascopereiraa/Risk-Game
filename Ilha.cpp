#include "Ilha.h"

int Ilha::obtemResistencia() const
{
    return 9;
}

int Ilha::obtemPontosVitoria() const
{
    return 2;
}

bool Ilha::podeConquistar(const Imperio& jogador)
{
    // Possuir pelo menos 5 territorios e tecnologia misseis
    
    return false;
}
