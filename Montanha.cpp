
#include "Montanha.h"
#include <sstream>

using std::ostringstream;

int Montanha::numMontanha = 0;

Montanha::Montanha()
{
	nome = "Montanha" + std::to_string(++numMontanha);
}

string Montanha::obtemNome() const
{
	return nome;
}

int Montanha::obtemResistencia() const
{
	return 6;
}

int Montanha::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	// check
	return 0;
}

int Montanha::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 0;
}
