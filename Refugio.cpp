#include "Refugio.h"

int Refugio::numRefugio = 0;

Refugio::Refugio()
{
	nome = "Refugio" + std::to_string(++numRefugio);
}

string Refugio::obtemNome() const
{
	return nome;
}

int Refugio::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return 0;
}

int Refugio::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 1;
}

Territorio* Refugio::duplica() const
{
	return new Refugio(*this);
}
