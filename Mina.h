
#ifndef __Mina__
#define __Mina__ 

#include "Continente.h"
#include <string>

using std::string;

class Mina : public Continente
{
	static int numMina;
	string nome;

public:
	// Construtores
	Mina();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& fase) const;
	int obtemCriacaoOuro(const int& ano, const int& fase) const;
};

#endif //__Mina__
