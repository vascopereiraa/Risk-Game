#include "Imperio.h"
#include <iostream>
#include <sstream>

using std::endl;
using std::ostringstream;

Imperio::Imperio(){}

void Imperio::adicionaTerr(Territorio* novo)
{
	imperio.emplace_back(novo);
}

string Imperio::obtemImperio() const
{
	ostringstream oss;
	for (auto it = imperio.begin(); it != imperio.end(); it++) {
		oss << (*it)->nome << endl;
	}
	return oss.str();
}

