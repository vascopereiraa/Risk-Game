#include "Imperio.h"

int Territorio::numTerr = 0;

Territorio::Territorio(const string& nome, int resist, int CriaPro, int CriaOu, int PontosV)
	: nome(nome), resist(resist), CriaProd(CriaPro), CriaOuro(CriaOu), PontosVit(PontosV)
{
	
}

