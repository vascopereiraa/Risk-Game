
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

int Tecnologias::verificaTecnologia(const string& nomeTecno) const
{
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		if (it->first == nomeTecno)
			return it->second;
	return 2;
}

string Tecnologias::obtemNomeTecnologias() const
{
	ostringstream oss;
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		oss << "Tecnologia: " << it->first << endl;

	return oss.str();
}

int Tecnologias::obtemPrecoDrone() const
{
	return 3;
}

int Tecnologias::obtemPrecoMisseis() const
{
	return 4;
}

int Tecnologias::obtemPrecoDefesas() const
{
	return 4;
}

int Tecnologias::obtemPrecoBolsa() const
{
	return 2;
}

int Tecnologias::obtemPrecoBanco() const
{
	return 3;
}

int Tecnologias::obterPrecoTecnologia(const string& nomeTecno) const
{
	if(nomeTecno == "drone") return obtemPrecoDrone();
	if(nomeTecno == "misseis") return obtemPrecoMisseis();
	if(nomeTecno == "defesas") return obtemPrecoDefesas();
	if(nomeTecno == "bolsa") return obtemPrecoBolsa();
	if(nomeTecno == "banco") return obtemPrecoBanco();
}

void Tecnologias::adicionaTecnologia(const string& nomeTecno)
{
	for (auto it = tecnologias.begin(); it != tecnologias.end(); ++it)
		if (it->first == nomeTecno)
			it->second = true;
}
