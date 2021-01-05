
#ifndef MUNDO_H
#define MUNDO_H

#include "Territorio.h"
#include "Imperio.h"
#include "Eventos.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class Mundo
{
	// Calendario do Jogo
	int fase;
	int ano;
	int turno;

	vector<Territorio*> territorios;
	Imperio* jogador;
	Eventos* eventos;

private:
	Territorio* procuraTerritorioMundo(const string& nome);
	Territorio* procuraTerritorioImperio(const string& nome);

public:
	// Construtores & Destrutor
	Mundo();
	Mundo(const Mundo& copia) = delete;		// Apagar o construtor por copia
	~Mundo();
	
	// Logica do Jogo
	Territorio* criaTerritorio(const string& tipo);
	string obtemTerritoriosMundoString() const;
	string obtemDadosTerritorioMundoString(const string& nome);
	string verificaTerritorioConquista(const string& territorio);
	string obtemTerritoriosImperioString() const;
	string verificaTecnologiaAdquirir(const string& nomeTecno);
	void avancaTempo();
	void geraEvento();
	bool verificaFimJogo() const;
};

ostream& operator<<(ostream& out, const Mundo& novoM);

#endif 