
#include "Duna.h"

int Duna::numDuna = 0;

Duna::Duna()
{
	nome = "Duna" + std::to_string(++numDuna);
}

string Duna::obtemNome() const
{
	return nome;
}

int Duna::obtemResistencia() const
{
	return 0;
}

int Duna::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return 1;
}

int Duna::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 0;
}

Territorio* Duna::duplica() const
{
	return new Duna(*this);
}
