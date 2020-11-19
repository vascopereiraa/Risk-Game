#ifndef Jogador_H
#define Jogador_H

#include <string>
#include <vector>

#include "Territorio.h"

using std::string;
using std::vector;

class Jogador
{
	string nome;
	vector<Territorio*> imperio;

public:
	Jogador(string nome);
};


#endif // !Jogador_H


