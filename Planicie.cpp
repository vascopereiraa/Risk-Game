
#include "Planicie.h"
#include <sstream>

using std::ostringstream;

int Planicie::numPlanicie = 0;

Planicie::Planicie()
{
	nome = "Planicie" + std::to_string(++numPlanicie);
}

string Planicie::obtemNome() const
{
	return nome;
}

int Planicie::obtemResistencia() const
{
	return 5;
}

int Planicie::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return ano == 1 ? 1 : 2;
}

int Planicie::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 1;
}

Territorio* Planicie::duplica() const
{
	return new Planicie(*this);
}
