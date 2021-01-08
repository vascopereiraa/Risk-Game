#ifndef __Planicie__
#define __Planicie__ 

#include "Continente.h"
#include <string>

using std::string;

class Planicie : public Continente
{
	static int numPlanicie;
	string nome;

public:
	// Construtores
	Planicie();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& turno) const;
	int obtemCriacaoOuro(const int& ano, const int& turno) const;
	Territorio* duplica() const;
};

#endif //__Planicie__
