
#ifndef Jogador_H
#define Jogador_H

#include "Territorio.h"
#include "tecnologias.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Imperio
{
	int capacidadeArmazem;
	int capacidadeCofre;
	int maxForcaMilitar;
	Tecnologias* tecno;

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
	string obtemImperioString(const int& ano, const int& fase) const;
	Territorio* procuraTerritorio(const string& nome);
	void adicionaTerritorio(Territorio* novo);
	void perderForcaMilitar(const int factor);
	bool conquistaTerritorio(Territorio* territorioConquista);
};


#endif // !Jogador_H


