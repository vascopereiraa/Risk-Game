
#ifndef __Duna__
#define __Duna__ 

#include "Continente.h"
#include <string>

using std::string;

class Duna : public Continente
{
	static int numDuna;
	string nome;

public:
	// Construtores
	Duna();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& fase) const;
	int obtemCriacaoOuro(const int& ano, const int& fase) const;
};

#endif //__Duna__
