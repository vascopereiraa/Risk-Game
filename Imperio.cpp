
#include "Imperio.h"

#include <iostream>
#include <sstream>

using std::endl;
using std::ostringstream;

Imperio::Imperio() : armazem(0), cofre(0), forcaMilitar(0),
		capacidadeArmazem(0), capacidadeCofre(0), maxForcaMilitar(0)
{

}

int Imperio::obtemArmazem() const
{
	return armazem;
}

int Imperio::obtemCofre() const
{
	return cofre;
}

int Imperio::obtemForcaMilitar() const
{
	return forcaMilitar;
}

int Imperio::obtemCapacidadeArmazem() const
{
	return capacidadeArmazem;
}

int Imperio::obtemCapacidadeCofre() const
{
	return capacidadeCofre;
}

int Imperio::obtemMaxForcaMilitar() const
{
	return maxForcaMilitar;
}

string Imperio::obtemImperioString() const
{
	ostringstream oss;
	for (auto it = imperio.begin(); it != imperio.end(); it++) {
		oss << (*it)->obtemTerritorioString();
	}
	return oss.str();
}

void Imperio::adicionaTerritorio(Territorio* novo)
{
	imperio.emplace_back(novo);
}

Territorio* Imperio::procuraTerritorio(const string& nome)
{
	// Procura no Imperio um territorio com o nome passado por argumento
	for (auto it = imperio.begin(); it != imperio.end(); it++)
		if ((*it)->obtemNome() == nome)
			return (*it);

	// Caso o territorio nao exista no Imperio
	return nullptr;
}

void Imperio::perderForcaMilitar(const int factor)
{
	if (forcaMilitar - factor < 0)
		forcaMilitar = 0;
	else
		forcaMilitar -= factor;
}

