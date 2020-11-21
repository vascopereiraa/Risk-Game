
#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

using std::string;

class Territorio
{
	static int numTerritorios;

	// Caracteristicas do Territorio
	string nome;
	int resistencia;
	int criacaoProdutos;
	int criacaoOuro;
	int pontosVitoria;

public:
	Territorio(const string& territorio, int resist, int CriaPro, int CriaOu, int PontosV);
	Territorio(const Territorio& copia) = delete;
	string obtemNome() const;
	int obtemResistencia() const;
	int obtemCriacaoProdutos() const;
	int obtemCriacaoOuro() const;
	int obtemPontosVitoria() const;
	string obtemTerritorioString() const;
};


#endif 