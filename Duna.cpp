#include "Duna.h"
#include <sstream>

using std::ostringstream;

int Duna::numDuna = 0;

Duna::Duna(const string& tipo, int r, int cProd, int cOuro, int ptVit)
	: Continente(r, cProd, cOuro, ptVit)
{
	ostringstream oss;
	++numDuna;
	oss << tipo << numDuna;
	nome = oss.str();
}

string Duna::obtemNome() const
{
	return nome;
}