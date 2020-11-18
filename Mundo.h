#ifndef MUNDO_H
#define MUNDO_H

#include <vector>

#include "Territorio.h"

using std::vector;


class Mundo{

	vector<Territorio> territorios;


public:

	Mundo();

	Mundo(const Mundo &outro) = delete;
	
	int CriaTerritorio(Territorio novo);


};

#endif 