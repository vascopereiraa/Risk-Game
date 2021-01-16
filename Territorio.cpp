
#include "Territorio.h"

#include <sstream>

using std::ostringstream;
using std::endl;

string Territorio::obtemTerritorioString(int ano, int fase) const
{
	ostringstream oss;
	oss << "Nome: " << obtemNome() <<
		"    Resistencia: " << obtemResistencia() << 
		"    Criacao Produtos: " << obtemCriacaoProdutos(ano, fase) << 
		"    Criacao Ouro: " << obtemCriacaoOuro(ano, fase) << 
		"    Pontos Vitoria: " << obtemPontosVitoria();
	return oss.str();
}

