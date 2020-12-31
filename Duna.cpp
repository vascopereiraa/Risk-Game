
#include "Duna.h"
#include <sstream>

using std::ostringstream;

int Duna::numDuna = 0;

Duna::Duna()
{
	ostringstream oss;
	++numDuna;
	oss << "Duna" << numDuna;
	nome = oss.str();
}

string Duna::obtemNome() const
{
	return nome;
}

int Duna::obtemResistencia() const
{
	return 4;
}

int Duna::obtemCriacaoProdutos(const int& ano, const int& fase) const
{
	return 0;
}

int Duna::obtemCriacaoOuro(const int& ano, const int& fase) const
{
	return fase >= 3 ? 2 : 0;
}
