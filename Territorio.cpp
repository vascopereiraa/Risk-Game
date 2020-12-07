
#include "Imperio.h"

#include <sstream>

using std::ostringstream;
using std::endl;

int Territorio::numTerritorios = 0;

Territorio::Territorio(const string& territorio, int r, int cProd, int cOuro, int ptVit)
	:  resistencia(r), criacaoProdutos(cProd), criacaoOuro(cOuro), pontosVitoria(ptVit)
{
	ostringstream oss;
	numTerritorios++;
	oss << territorio << numTerritorios;
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

string Territorio::obtemTerritorioString() const
{
	ostringstream oss;
	oss << "Nome: " << obtemNome() << endl 
		 << "Resistencia: " << obtemResistencia() << 
		"    Criacao Produtos: " << obtemCriacaoProdutos() << 
		"    Criacao Ouro: " << obtemCriacaoOuro() << 
		"    Pontos Vitoria: " << obtemPontosVitoria() << endl;
	return oss.str();
}

