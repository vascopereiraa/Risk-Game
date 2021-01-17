
#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "Territorio.h"
#include "Imperio.h"

class Continente : public Territorio
{

public:
	// Obter dados da Classe
	int obtemPontosVitoria() const;

	// Logica do Jogo
	bool podeConquistar(const Imperio& jogador);

	// Destrutor
	virtual ~Continente() = default;
};

#endif //CONTINENTE_H
