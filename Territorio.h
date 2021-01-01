
#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

using std::string;

class Imperio;

class Territorio
{

public:
	// Construtores

	// Obter dados da Classe
	virtual string obtemNome() const = 0;
	virtual int obtemResistencia() const = 0;
	virtual int obtemCriacaoProdutos(const int& ano, const int& fase) const = 0;
	virtual int obtemCriacaoOuro(const int& ano, const int& fase) const = 0;
	virtual int obtemPontosVitoria() const = 0;
	string obtemTerritorioString(int ano, int fase) const;

	// Logica do Jogo
	virtual bool podeConquistar(const Imperio& jogador) = 0;

};


#endif