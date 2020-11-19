#include "Mundo.h"
#include "Territorio.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

Mundo::Mundo()
{
	indTerr["planicie"] = 0;
	indTerr["montanha"] = 0;
	indTerr["fortaleza"] = 0;
	indTerr["mina"] = 0;
	indTerr["duna"] = 0;
	indTerr["castelo"] = 0;
	indTerr["refpiratas"] = 0;
	indTerr["pescaria"] = 0;
}

void Mundo::criaTerritorio(string tipo)
{
	ostringstream oss;
	for (auto it = indTerr.begin(); it != indTerr.end(); it++) {
		if (it->first == tipo) {
			it->second++;
			oss << tipo << it->second;
			territorios.emplace_back(Territorio(oss.str(), 1, 1, 1, 1));
		}
	}
}

string Mundo::obtemTerritorios() const
{
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); it++) {
		oss << it->nome << " " << it->resist << " " << it->CriaOuro <<
			" " << it->CriaProd << " " << it->PontosVit << endl;
	}
	return oss.str();
}
