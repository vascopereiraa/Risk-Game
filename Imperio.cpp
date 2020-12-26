
#include "Imperio.h"

#include <iostream>
#include <sstream>
#include <random>

using std::endl;
using std::ostringstream;

Imperio::Imperio() : armazem(0), cofre(0), forcaMilitar(0),
		capacidadeArmazem(0), capacidadeCofre(0), maxForcaMilitar(0)
{

}

int Imperio::obtemArmazem() const
{
	return armazem;
}

int Imperio::obtemCofre() const
{
	return cofre;
}

int Imperio::obtemForcaMilitar() const
{
	return forcaMilitar;
}

int Imperio::obtemCapacidadeArmazem() const
{
	return capacidadeArmazem;
}

int Imperio::obtemCapacidadeCofre() const
{
	return capacidadeCofre;
}

int Imperio::obtemMaxForcaMilitar() const
{
	return maxForcaMilitar;
}

string Imperio::obtemImperioString() const
{
	ostringstream oss;


	oss << "Armazem: " << obtemArmazem()
		<< "   Capacidade do Armazem: " << obtemCapacidadeArmazem()
		<< "   Cofre: " << obtemCofre()
		<< "   Capacidade do Cofre: " << obtemCapacidadeCofre()
		<< "   Forca Militar: " << obtemForcaMilitar()
		<< "   Forca Militar Maxima: " << obtemMaxForcaMilitar() << endl;

	oss << "\nTerritorios do Imperio: " << endl;

	for (auto it = imperio.begin(); it != imperio.end(); it++) {
		oss << (*it)->obtemTerritorioString() << endl;
	}

	return oss.str();
}

void Imperio::adicionaTerritorio(Territorio* novo)
{
	imperio.emplace_back(novo);
}

Territorio* Imperio::procuraTerritorio(const string& nome)
{
	// Procura no Imperio um territorio com o nome passado por argumento
	for (auto it = imperio.begin(); it != imperio.end(); it++)
		if ((*it)-> == nome)
			return (*it);

	// Caso o territorio nao exista no Imperio
	return nullptr;
}

void Imperio::perderForcaMilitar(const int factor)
{
	if (forcaMilitar - factor < 0)
		forcaMilitar = 0;
	else
		forcaMilitar -= factor;
}

bool Imperio::conquistaTerritorio(Territorio* territorioConquista)
{
	// Se o territorio nao pertencer ao imperio
	if (procuraTerritorio(territorioConquista->obtemNome()) == nullptr) {
		int resAtacado = territorioConquista->obtemResistencia();

		// Inicia o gerador aleatorio entre 1 e 6
		std::default_random_engine gerador;
		std::uniform_int_distribution<int> randomInt(1, 6);
		int forcaAtaque = randomInt(gerador) + obtemForcaMilitar();

		if (forcaAtaque >= resAtacado) {
			// Conquista o territorio
			adicionaTerritorio(territorioConquista);
			return true;
		}
		else {
			perderForcaMilitar(1);
			return false;
		}
	}
	else
		return false;
}

