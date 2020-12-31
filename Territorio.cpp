
#include "Imperio.h"

#include <sstream>

using std::ostringstream;
using std::endl;

Territorio::Territorio(int r, int cProd, int cOuro, int ptVit)
	:  resistencia(r), criacaoProdutos(cProd), criacaoOuro(cOuro), pontosVitoria(ptVit)
{

}

string Territorio::obtemTerritorioString() const
{
	ostringstream oss;
	oss << "Resistencia: " << obtemResistencia() << 
		"    Criacao Produtos: " << obtemCriacaoProdutos() << 
		"    Criacao Ouro: " << obtemCriacaoOuro() << 
		"    Pontos Vitoria: " << obtemPontosVitoria() << endl;
	return oss.str();
}

