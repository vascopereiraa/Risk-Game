#ifndef MUNDO_H
#define MUNDO_H

#include <vector>
#include <map>

#include "Jogador.h"

#include "Territorio.h"

using std::vector;
using std::map;


class Mundo{
	
	// Indice para territorio
	map<string, int> indTerr;

	vector<Territorio> territorios;


public:

	Mundo();
	Mundo(const Mundo &outro) = delete;
	void criaTerritorio(string& tipo);
	void criaTerritorioFicheiro(const string& nomeFicheiro);
	string obtemTerritorios() const;
	bool verificaExisteTerritorio(const string& nome) const;
	void conquistaTerritorio(string territorio);
};

#endif 