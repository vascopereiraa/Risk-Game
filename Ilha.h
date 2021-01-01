
#ifndef __ILHA_H__
#define __ILHA_H__

#include "Imperio.h"

class Ilha : public Territorio
{

public:
	// Construtores
	
	// Obter dados das Classes
	int obtemResistencia() const;
	int obtemPontosVitoria() const;

	// Logica do Jogo
	bool podeConquistar(const Imperio& jogador);
};

#endif //__ILHA_H__

