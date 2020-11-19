#include "Territorio.h"

Territorio::Territorio(string nome, int resist, int CriaPro, int CriaOu, int PontosV)
	: nome(nome), resist(resist), CriaProd(CriaPro), CriaOuro(CriaOu), PontosVit(PontosV)
{
	
}

string Territorio::obtemNome() const
{
	return nome;
}

