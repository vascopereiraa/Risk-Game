#include "Imperio.h"

#include <sstream>

using std::ostringstream;

int Territorio::numTerritorios = 0;

Territorio::Territorio(const string& territorio, int r, int cProd, int cOuro, int ptVit)
	:  resistencia(r), criacaoProdutos(cProd), criacaoOuro(cOuro), pontosVitoria(ptVit)
{
	ostringstream oss;
	oss << territorio << numTerritorios++;
	nome = oss.str();
}

string Territorio::obtemNome() const
{
	return nome;
}

int Territorio::obtemResistencia() const
{
	return resistencia;
}

int Territorio::obtemCriacaoProdutos() const
{
	return criacaoProdutos;
}

int Territorio::obtemCriacaoOuro() const
{
	return criacaoOuro;
}

int Territorio::obtemPontosVitoria() const
{
	return pontosVitoria;
}

