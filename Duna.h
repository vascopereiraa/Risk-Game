
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
	Duna(const string& nome);

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(int ano, int fase) const;
	int obtemCriacaoOuro(int ano, int fase) const;
};

#endif //__Duna__
