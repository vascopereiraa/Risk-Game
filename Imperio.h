
#ifndef Jogador_H
#define Jogador_H

#include "Territorio.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Imperio
{
	int capacidadeArmazem;
	int capacidadeCofre;
	int maxForcaMilitar;

	vector<Territorio*> imperio;
	int armazem;
	int cofre;
	int forcaMilitar;

public:
	Imperio();
	int obtemArmazem() const;
	int obtemCofre() const;
	int obtemForcaMilitar() const;
	int obtemCapacidadeArmazem() const;
	int obtemCapacidadeCofre() const;
	int obtemMaxForcaMilitar() const;
	string obtemImperioString() const;
	void adicionaTerritorio(Territorio* novo);
	Territorio* procuraTerritorio(const string& nome);
	void perderForcaMilitar(const int factor);
};


#endif // !Jogador_H


