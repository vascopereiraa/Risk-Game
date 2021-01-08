#include "Castelo.h"

int Castelo::numCastelo = 0;

Castelo::Castelo()
{
	nome = "Castelo" + std::to_string(++numCastelo);
}

string Castelo::obtemNome() const
{
	return nome;
}

int Castelo::obtemResistencia() const
{
	return 7;
}

int Castelo::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return turno <= 2 ? 3 : 0;
}

int Castelo::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 1;
}

Territorio* Castelo::duplica() const
{
	return new Castelo(*this);
}
