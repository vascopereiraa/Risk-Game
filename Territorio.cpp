
#include "Imperio.h"

#include <sstream>

using std::ostringstream;
using std::endl;

string Territorio::obtemTerritorioString() const
{
	ostringstream oss;
	oss << "Resistencia: " << obtemResistencia() << 
		"    Criacao Produtos: " << obtemCriacaoProdutos() << 
		"    Criacao Ouro: " << obtemCriacaoOuro() << 
		"    Pontos Vitoria: " << obtemPontosVitoria() << endl;
	return oss.str();
}

