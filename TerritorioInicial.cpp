#include "TerritorioInicial.h"

string TerritorioInicial::obtemNome() const
{
    return "Territorio Inicial";
}

int TerritorioInicial::obtemResistencia() const
{
    return 9;
}

int TerritorioInicial::obtemCriacaoProdutos(const int& ano, const int& fase) const
{
    return 1;
}

int TerritorioInicial::obtemCriacaoOuro(const int& ano, const int& fase) const
{
    return 1;
}

int TerritorioInicial::obtemPontosVitoria() const
{
    return 0;
}
