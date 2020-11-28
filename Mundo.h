
#ifndef MUNDO_H
#define MUNDO_H

#include "Territorio.h"
#include "Imperio.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class Mundo
{
	vector<Territorio*> territorios;
	Imperio* jogador;

private:
	Territorio* procuraTerritorioMundo(const string& nome);
	Territorio* procuraTerritorioImperio(const string& nome);

public:
	Mundo();
	Mundo(const Mundo& copia) = delete;		// Apagar o construtor por copia
	Territorio* criaTerritorio(const string& tipo);

	string obtemTerritoriosMundoString() const;
	string obtemDadosTerritorioMundoString(const string& nome);

	void conquistaTerritorio(const string& territorio);
	string obtemTerritoriosImperioString() const;
};

ostream& operator<<(ostream& out, const Mundo& novoM);

#endif 