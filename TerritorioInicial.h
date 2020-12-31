
#ifndef TERRITORIO_INICIAL_H
#define TERRITORIO_INICIAL_H

#include "Territorio.h"

class TerritorioInicial : public Territorio
{

public:
	// Construtores

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(int ano, int fase) const;
	int obtemCriacaoOuro(int ano, int fase) const;
	int obtemPontosVitoria() const;
};


#endif // TERRITORIO_INICIAL_H
