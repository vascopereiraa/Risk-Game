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
	Mundo(const Mundo& copia) = delete;
	Territorio* criaTerritorio(const string& tipo);
	string obtemTerritorios() const;
	
	bool verificaConq(const string& ataque) const;
	void conquistaTerr(const string& ataque);
	Territorio* obtemTerritorio(const string& tipo);
	

	//void criaTerritorioFicheiro(const string& nomeFicheiro);
};

#endif 