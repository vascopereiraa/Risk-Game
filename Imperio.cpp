
#include "Imperio.h"
#include "Mundo.h"

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

Imperio::Imperio(const Imperio& original)
{
	*this = original;
}

Imperio& Imperio::operator=(const Imperio& outro)
{
	if (this == &outro)
		return *this;
	
	capacidadeArmazem = outro.capacidadeArmazem;
	capacidadeCofre = outro.capacidadeCofre;
	maxForcaMilitar = outro.maxForcaMilitar;
	armazem = outro.armazem;
	cofre = outro.cofre;
	forcaMilitar = outro.forcaMilitar;
	tecno = new Tecnologias(*outro.tecno);

	return *this;
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

bool Imperio::verificaTecnologia(const string& nomeTecno) const
{
	return tecno->verificaTecnologia(nomeTecno);
}

string Imperio::obtemImperioString(const int& ano, const int& fase) const
{
	ostringstream oss;

	oss << "Capacidade do Armazem: " << obtemCapacidadeArmazem()
		<< "    Capacidade do Cofre: " << obtemCapacidadeCofre()
		<< "    Forca Militar Maxima: " << obtemMaxForcaMilitar() << endl
		<< "Armazem: " << obtemArmazem()
		<< "\t\t    Cofre: " << obtemCofre()
		<< "\t\t      Forca Militar: " << obtemForcaMilitar() << endl;

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
			std::cout << "\n\n[DEBUG]Foi Eliminado o territorio " << (*it)->obtemNome() << endl << endl;
			imperio.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
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

bool Imperio::conquistaTerritorio(Territorio* territorioConquista, Mundo* mundo)
{
	// Se o territorio nao pertencer ao imperio
	if (procuraTerritorio(territorioConquista->obtemNome()) == nullptr) {
		if (territorioConquista->podeConquistar(*this) == true) {
			int resAtacado = territorioConquista->obtemResistencia();

			// Gera um numero aleatorio entre 1 e 6
			int fatorRand = mundo->geraAleatorio(1, 6);
			int forcaAtaque = fatorRand + obtemForcaMilitar();

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

int Imperio::acrescentaOuro(const int& ouro)
{
	if (cofre + ouro >= capacidadeCofre) {
		cofre = capacidadeCofre;
		return capacidadeCofre - (cofre - ouro);
	}
	else {
		cofre += ouro;
		return ouro;
	}
}

int Imperio::acrescentaProduto(const int& produto)
{
	if (armazem + produto >= capacidadeArmazem) {
		armazem = capacidadeArmazem;
		return capacidadeArmazem - (armazem - produto);
	}
	else {
		armazem += produto;
		return produto;
	}
}

int Imperio::acrescentaForcaMilitar(const int& forca)
{
	if (forcaMilitar + forca >= maxForcaMilitar) {
		forcaMilitar = maxForcaMilitar;
		return maxForcaMilitar - (forcaMilitar - forca);
	}
	else {
		forcaMilitar += forca;
		return forca;
	}
}

int Imperio::recolheProdutos(const int& ano, const int& turno)
{
	int recolha = 0;
	for (auto it = imperio.begin(); it != imperio.end(); it++)
		recolha += (*it)->obtemCriacaoProdutos(ano,turno);
	return acrescentaProduto(recolha);
}

int Imperio::recolheOuro(const int& ano, const int& turno)
{
	int recolha = 0;
	for (auto it = imperio.begin(); it != imperio.end(); it++)
		recolha += (*it)->obtemCriacaoOuro(ano, turno);
	return acrescentaOuro(recolha);
	
}

bool Imperio::maisMilitar()
{
	if (forcaMilitar + 1 <= maxForcaMilitar) {
		if (cofre >= 1)
			if (armazem >= 1) {
				++forcaMilitar;
				--cofre;
				--armazem;
				return true;
			}
	}
	return false;
}

bool Imperio::maisProduto()
{
	if (armazem + 1 <= capacidadeArmazem) {
		if (cofre >= 2) {
			cofre -= 2;
			++armazem;
			return true;
		}
		return false;
	}
	return false;
}

bool Imperio::maisOuro()
{
	if (cofre + 1 <= capacidadeCofre) {
		if (armazem >= 2) {
			armazem -= 2;
			++cofre;
			return true;
		}
		return false;
	}
	return false;
}
