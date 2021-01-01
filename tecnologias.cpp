
#include "Tecnologias.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::ostringstream;
using std::endl;

Tecnologias::Tecnologias()
{
	tecnologias["drones"] = false;
	tecnologias["misseis"] = false;
	tecnologias["defesas"] = false;
	tecnologias["bolsa"] = false;
	tecnologias["banco"] = false;
}

bool Tecnologias::verificaTecnologia(const string& nomeTecno) const
{
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		if (it->first == nomeTecno)
			return it->second;
	return false;
}

string Tecnologias::obtemNomeTecnologias() const
{
	ostringstream oss;
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		oss << "Tecnologia: " << it->first << endl;

	return oss.str();
}
