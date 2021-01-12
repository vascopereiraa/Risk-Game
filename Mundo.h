
#ifndef MUNDO_H
#define MUNDO_H

#include "Territorio.h"
#include "Imperio.h"
#include "Evento.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class Mundo
{
	// Calendario do Jogo
	int ano;
	int turno;
	int fase;

	vector<Territorio*> territorios;
	Imperio* jogador;
	
	int ultimoAleatorio;

private:
	Territorio* procuraTerritorioMundo(const string& nome);
	Territorio* procuraTerritorioImperio(const string& nome);

public:
	// Construtores & Destrutor
	Mundo();
	Mundo(const Mundo& orig);
	~Mundo();
	Mundo& operator=(const Mundo& orig);

	// Dados da classe
	int obtemAno() const;
	int obtemTurno() const;
	int obtemFase() const;

	// Logica do Jogo
	Territorio* criaTerritorio(const string& tipo);
	string obtemTerritoriosMundoString() const;
	string obtemDadosTerritorioMundoString(const string& nome);
	string verificaTerritorioConquista(const string& territorio);
	string obtemTerritoriosImperioString() const;
	string verificaTecnologiaAdquirir(const string& nomeTecno);
	bool adquireForcaMilitar();
	bool adquireOuro();
	bool adquireProduto();
	string avancaTempo();
	string controlaFase();
	string obtemTempo() const;
	string geraEvento();
	string recolheOuroProdutos();
	bool verificaFimJogo() const;
	int geraAleatorio(const int& min, const int& max);

	// Funcoes para Debug
	void acrescentaOuroImperio(const int& valor);
	void acrescentaProdImperio(const int& valor);
	int obtemNumeroTerrImp() const;
};

ostream& operator<<(ostream& out, const Mundo& novoM);

#endif 
