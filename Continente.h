
#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "Territorio.h"
#include "Imperio.h"

class Continente : public Territorio
{

public:
	// Construtores

	// Obter dados da Classe
	int obtemPontosVitoria() const;

	// Logica do Jogo
	bool podeConquistar(const Imperio& jogador);
};

#endif //CONTINENTE_H
