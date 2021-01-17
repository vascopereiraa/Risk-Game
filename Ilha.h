
#ifndef __ILHA_H__
#define __ILHA_H__

#include "Imperio.h"

class Ilha : public Territorio
{

public:
	// Obter dados das Classes
	int obtemResistencia() const;
	int obtemPontosVitoria() const;

	// Logica do Jogo
	bool podeConquistar(const Imperio& jogador);

	// Destrutor
	virtual ~Ilha() = default;
};

#endif //__ILHA_H__

