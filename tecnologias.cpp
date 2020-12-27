#include "tecnologias.h"
#include <iostream>

using std::cout;

Tecnologias::Tecnologias()
{
	tecnologias["drones"] = 0;
	tecnologias["misseis"] = 0;
	tecnologias["defesas"] = 0;
	tecnologias["bolsa"] = 0;
	tecnologias["banco"] = 0;

}

void Tecnologias::percorreMapa() const
{
	for (auto tecnologia : tecnologias)
	{
		std::cout << tecnologia.first << " "
			<< tecnologia.second << std::endl;
	}
}