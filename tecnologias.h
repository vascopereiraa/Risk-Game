#pragma once
#include <map>
#include <string>

using std::string;
using std::map;

class Tecnologias
{
	map<string, int> tecnologias;

public:

	Tecnologias();
	void percorreMapa() const;

};

