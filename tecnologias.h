#pragma once
#include <map>
#include <string>

using std::string;
using std::map;

class Tecnologias
{
	map<string, bool> tecnologias;

public:

	Tecnologias();
	bool verificaTecnologia(const string& nomeTecno) const;

};

