#include "TerritorioInicial.h"

string TerritorioInicial::obtemNome() const
{
    return "Territorio Inicial";
}

int TerritorioInicial::obtemResistencia() const
{
    return 9;
}

int TerritorioInicial::obtemCriacaoProdutos(int ano, int fase) const
{
    return 1;
}

int TerritorioInicial::obtemCriacaoOuro(int ano, int fase) const
{
    return 1;
}

int TerritorioInicial::obtemPontosVitoria() const
{
    return 0;
}
