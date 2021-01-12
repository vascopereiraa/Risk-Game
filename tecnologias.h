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
	int obtemPrecoDrone() const;
	int obtemPrecoMisseis() const;
	int obtemPrecoDefesas() const;
	int obtemPrecoBolsa() const;
	int obtemPrecoBanco() const;
	int obterPrecoTecnologia(const string& nomeTecno) const;

	// Logica do Jogo
	void adicionaTecnologia(const string& nomeTecno);

};

