#ifndef Jogador_H
#define Jogador_H

#include <string>
#include <vector>

#include "Territorio.h"

using std::string;
using std::vector;

class Imperio
{
	vector<Territorio*> imperio;
	int armazem;
	int cofre;

public:
	Imperio();
	void adicionaTerr(Territorio* novo);
	string obtemImperio() const;

};


#endif // !Jogador_H


