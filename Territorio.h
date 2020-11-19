#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Territorio{

public:
	// Caracteristicas do Territorio
	string nome;
	int resist;
	int CriaProd;
	int CriaOuro;
	int PontosVit;

public:

	Territorio(string nome, int resist, int CriaPro, int CriaOu, int PontosV);
	string obtemNome() const;
};


#endif 