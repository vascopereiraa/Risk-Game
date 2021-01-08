
#ifndef __Castelo__
#define __Castelo__ 

#include "Continente.h"
#include <string>

using std::string;

class Castelo : public Continente
{
	static int numCastelo;
	string nome;

public:
	// Construtores
	Castelo();
	

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& turno) const;
	int obtemCriacaoOuro(const int& ano, const int& turno) const;
	Territorio* duplica() const;
};

#endif //__Castelo__
