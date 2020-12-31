
#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "Territorio.h"

class Continente : public Territorio
{

public:
	// Construtores
	Continente(int r, int cProd, int cOuro, int ptVit);

	// Obter dados da Classe
	int obtemPontosVitoria() const;
};

#endif //CONTINENTE_H
