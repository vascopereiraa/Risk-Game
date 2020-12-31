
#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "Territorio.h"

class Continente : public Territorio
{

public:
	// Construtores

	// Obter dados da Classe
	int obtemPontosVitoria() const;
};

#endif //CONTINENTE_H
