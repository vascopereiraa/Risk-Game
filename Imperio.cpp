
#include "Imperio.h"

#include <iostream>
#include <sstream>
#include <random>

using std::endl;
using std::ostringstream;

Imperio::Imperio() : armazem(0), cofre(0), forcaMilitar(0),
		capacidadeArmazem(3), capacidadeCofre(3), maxForcaMilitar(3)
{
	Tecnologias* novo = new Tecnologias();
	tecno = novo;
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

int Imperio::obtemNumeroTerritorios() const
{
	return imperio.size();
}

int Imperio::verificaTecnologia(const string& nomeTecno) const
{
	return tecno->verificaTecnologia(nomeTecno);
}

string Imperio::obtemImperioString(const int& ano, const int& fase) const
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
		oss << (*it)->obtemTerritorioString(ano, fase) << endl;
	}

	return oss.str();
}

string Imperio::obtemNomeUltimoTerritorio() const
{
	return imperio[imperio.size() - 1]->obtemNome();
}

void Imperio::adicionaTerritorio(Territorio* novo)
{
	imperio.emplace_back(novo);
}

bool Imperio::removeTerritorio(Territorio* apaga)
{
	vector<Territorio*>::iterator it;

	it = imperio.begin();
	while (it != imperio.end()) {
		if ((*it)->obtemNome() == apaga->obtemNome()) {
			it = imperio.erase(it);
			std::cout << "Foi Eliminado o: " << (*it)->obtemNome();
			return true;
		}
		else {
			it++;
		}
	}
	std::cout << "Nao foi eliminado territorio: " << apaga->obtemNome() << endl;

	return false;
}

Territorio* Imperio::procuraTerritorio(const string& nome)
{
	// Procura no Imperio um territorio com o nome passado por argumento
	for (auto it = imperio.begin(); it != imperio.end(); it++)
		if ((*it)->obtemNome() == nome)
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
		if (territorioConquista->podeConquistar(*this) == true) {
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
	}
	else
		return false;
}

bool Imperio::adquireTecnologia(const string& nomeTecno)
{
	int preco = tecno->obterPrecoTecnologia(nomeTecno);
	if (preco == -1) return false;
	if (cofre >= preco) {
		tecno->adicionaTecnologia(nomeTecno);
		cofre -= preco;
		alteraImperio(nomeTecno);
		return true;
	}
	return false;
}

void Imperio::alteraImperio(const string& nomeTecno)
{
	if (nomeTecno == "drones") { maxForcaMilitar = 5; }
	if (nomeTecno == "banco") { capacidadeArmazem = 5; capacidadeCofre = 5; }
}

void Imperio::acrescentaOuro(const int& ouro)
{
	if (cofre + ouro >= capacidadeCofre)
		cofre = capacidadeCofre;
	else
		cofre += ouro;
}

void Imperio::acrescentaProduto(const int& produto)
{
	if (armazem + produto >= capacidadeArmazem)
		armazem = capacidadeArmazem;
	else
		armazem += produto;
}