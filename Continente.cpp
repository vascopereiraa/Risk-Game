#include "Continente.h"

Continente::Continente(int r, int cProd, int cOuro, int ptVit)
	: Territorio(r, cProd, cOuro, ptVit)
{
}

int Continente::obtemPontosVitoria() const
{
	return 1;
}
