
#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

using std::string;

class Territorio
{
	// Caracteristicas do Territorio
	int resistencia;
	int criacaoProdutos;
	int criacaoOuro;

protected:
	int pontosVitoria;

public:
	Territorio(int r, int cProd, int cOuro, int ptVit);
	Territorio(const Territorio& copia) = delete;
	int obtemResistencia() const;
	int obtemCriacaoProdutos() const;
	int obtemCriacaoOuro() const;
	int obtemPontosVitoria() const;
	string obtemTerritorioString() const;
	virtual ~Territorio() = default;
};


#endif 