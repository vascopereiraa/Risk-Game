
#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

using std::string;

class Territorio
{

public:
	// Construtores

	// Obter dados da Classe
	virtual string obtemNome() const = 0;
	virtual int obtemResistencia() const = 0;
	virtual int obtemCriacaoProdutos(int ano, int fase) const = 0;
	virtual int obtemCriacaoOuro(int ano, int fase) const = 0;
	virtual int obtemPontosVitoria() const = 0;

	string obtemTerritorioString() const;

};


#endif