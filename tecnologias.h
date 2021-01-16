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
	bool verificaTecnologiaImperio(const string& nomeTecno) const;
	bool verificaTecnologiaExiste(const string& nomeTecno) const;
	string obtemNomeTecnologias() const;
	string obtemObjetivoTecnologias(const string& nome) const;
	int obtemPrecoDrone() const;
	int obtemPrecoMisseis() const;
	int obtemPrecoDefesas() const;
	int obtemPrecoBolsa() const;
	int obtemPrecoBanco() const;
	int obterPrecoTecnologia(const string& nomeTecno) const;

	//Fim de jogo
	int obtemNumeroTecnologias() const;

	// Logica do Jogo
	void adicionaTecnologia(const string& nomeTecno);

};

