#pragma once
#include <map>
#include <string>

using std::string;
using std::map;

class Tecnologias
{
	map<string, bool> tecnologias;

public:
	// Construtores
	Tecnologias();

	// Obter dados da Classe
	bool verificaTecnologia(const string& nomeTecno) const;
	string obtemNomeTecnologias() const;

	// Logica do Jogo
};

