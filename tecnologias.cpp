#include "tecnologias.h"
#include <iostream>

using std::cout;

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