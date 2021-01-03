#include "Pescaria.h"

int Pescaria::numPescaria = 0;

Pescaria::Pescaria()
{
	nome = "Pescaria" + std::to_string(++numPescaria);
}

string Pescaria::obtemNome() const
{
	return nome;
}

int Pescaria::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return ano == 1 ? 2 : 4;
}

int Pescaria::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 1;
}