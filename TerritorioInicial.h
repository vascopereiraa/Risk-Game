
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
	int obtemCriacaoProdutos(const int& ano, const int& fase) const;
	int obtemCriacaoOuro(const int& ano, const int& fase) const;
	int obtemPontosVitoria() const;

	// Logica do Jogo
	bool podeConquistar(const Imperio& jogador);
	Territorio* duplica() const;
};


#endif // TERRITORIO_INICIAL_H
