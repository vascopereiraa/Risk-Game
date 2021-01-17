
#ifndef __Fortaleza__
#define __Fortaleza__ 

#include "Continente.h"
#include <string>

using std::string;

class Fortaleza : public Continente
{
	static int numFortaleza;
	string nome;

public:
	// Construtores
	Fortaleza();

	// Obter dados da Classe
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos(const int& ano, const int& fase) const;
	int obtemCriacaoOuro(const int& ano, const int& fase) const;

	// Logica do Jogo
	Territorio* duplica() const;
};

#endif //__Fortaleza__
