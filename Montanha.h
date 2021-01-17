
#ifndef __Montanha__
#define __Montanha__ 

#include "Continente.h"
#include <string>

using std::string;

class Montanha : public Continente
{
	static int numMontanha;
	string nome;

public:
	// Construtores
	Montanha();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& turno) const;
	int obtemCriacaoOuro(const int& ano, const int& turno) const;
	Territorio* duplica() const;
};

#endif //__Montanha__
