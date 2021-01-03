#ifndef __Refugio__
#define __Refugio__ 

#include "Ilha.h"
#include <string>

using std::string;

class Refugio : public Ilha
{
	static int numRefugio;
	string nome;

public:
	// Construtores
	Refugio();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemCriacaoProdutos(const int& ano, const int& turno) const;
	int obtemCriacaoOuro(const int& ano, const int& turno) const;
};

#endif //__Refugio__
