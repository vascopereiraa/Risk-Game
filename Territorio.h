#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

using std::string;

class Territorio{

	string nome;
	int resistencia;
	int CriaProd;
	int CriaOuro;
	int PontosVit;


public:

	Territorio(string nNome, int resist, int CriaPro, int CriaOu, int PontosV);

};


#endif 