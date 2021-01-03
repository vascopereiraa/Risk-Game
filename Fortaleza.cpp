#include "Fortaleza.h"

int Fortaleza::numFortaleza = 0;

Fortaleza::Fortaleza()
{
	nome = "Fortaleza" + std::to_string(++numFortaleza);
}

string Fortaleza::obtemNome() const
{
	return nome;
}

int Fortaleza::obtemResistencia() const
{
	return 8;
}

int Fortaleza::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return 0;
}

int Fortaleza::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return 0;
}