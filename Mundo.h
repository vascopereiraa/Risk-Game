#ifndef MUNDO_H
#define MUNDO_H

#include <vector>
#include <map>

#include "Imperio.h"

#include "Territorio.h"

using std::vector;
using std::map;


class Mundo{
	
	vector<Territorio*> territorios;
public:
	Imperio* jogador;

public:

	Mundo();
	Mundo(const Mundo &outro) = delete;
	Territorio* criaTerritorio(const string& tipo);
	string obtemTerritorios() const;

	//void criaTerritorioFicheiro(const string& nomeFicheiro);
	//bool verificaExisteTerritorio(const string& nome) const;
	//void conquistaTerritorio(string territorio);
};

#endif 