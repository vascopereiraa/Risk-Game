
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
	Duna(const string& nome, int r, int cProd, int cOuro, int ptVit);
	string obtemNome() const;
};

#endif //__Duna__
