#ifndef __Pescaria__
#define __Pescaria__ 

#include "Ilha.h"
#include <string>

using std::string;

class Pescaria : public Ilha
{
	static int numPescaria;
	string nome;

public:
	// Construtores
	Pescaria();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemCriacaoProdutos(const int& ano, const int& turno) const;
	int obtemCriacaoOuro(const int& ano, const int& turno) const;

	// Logica do Jogo
	Territorio* duplica() const;

};

#endif //__Pescaria__
