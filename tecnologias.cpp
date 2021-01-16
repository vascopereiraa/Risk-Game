
#include "Tecnologias.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::ostringstream;
using std::endl;

Tecnologias::Tecnologias()
{
	tecnologias["drones"] = false;
	tecnologias["misseis"] = false;
	tecnologias["defesas"] = false;
	tecnologias["bolsa"] = false;
	tecnologias["banco"] = false;
}

bool Tecnologias::verificaTecnologiaImperio(const string& nomeTecno) const
{
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		if (it->first == nomeTecno)
			return it->second;
	return false;
}

bool Tecnologias::verificaTecnologiaExiste(const string& nomeTecno) const
{
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		if (it->first == nomeTecno)
			return true;
	return false;
}

int Tecnologias::obtemNumeroTecnologias() const
{
	int pontuacao = 0;
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it)
		if (it->second)
			++pontuacao;
	if (pontuacao == 5)
		++pontuacao;
	return pontuacao;
}

string Tecnologias::obtemNomeTecnologias() const
{
	ostringstream oss;
	for (auto it = tecnologias.cbegin(); it != tecnologias.cend(); ++it) {
		oss << "\nTecnologia: " << it->first
			<< "\tPreco: " << obterPrecoTecnologia(it->first)
			<< "\nDescricao: " << obtemObjetivoTecnologias(it->first);
		if (it->second == true)
			oss << "Tecnologia ja foi adquirida" << endl;
		else
			oss << "Tecnologia ainda nao foi adquirida" << endl;
	}

	return oss.str();
}
string Tecnologias::obtemObjetivoTecnologias(const string& nome) const{
	if (nome == "drones")
		return string{ "Limite maximo de forca militar aumentado para 5\n" };
	if (nome == "misseis")
		return string{ "Jogador passa a ter a capacidade de atacar ilhas\n" };
	if (nome == "defesas")
		return string{ "Acrescenta 1 unidade de resistencia ao territorio caso seja invadido\n" };
	if (nome == "bolsa")
		return string{ "Torna possivel a troca entre produtos e ouro\n" };
	if (nome == "banco")
		return string{ "A capacidade de armazenar produtos e ouro passa a ter um limite de 5\n" };
	return string{ "" };
}

int Tecnologias::obtemPrecoDrone() const
{
	return 3;
}

int Tecnologias::obtemPrecoMisseis() const
{
	return 4;
}

int Tecnologias::obtemPrecoDefesas() const
{
	return 4;
}

int Tecnologias::obtemPrecoBolsa() const
{
	return 2;
}

int Tecnologias::obtemPrecoBanco() const
{
	return 3;
}

int Tecnologias::obterPrecoTecnologia(const string& nomeTecno) const
{
	if(nomeTecno == "drones") return obtemPrecoDrone();
	if(nomeTecno == "misseis") return obtemPrecoMisseis();
	if(nomeTecno == "defesas") return obtemPrecoDefesas();
	if(nomeTecno == "bolsa") return obtemPrecoBolsa();
	if(nomeTecno == "banco") return obtemPrecoBanco();

	return -1;
}

void Tecnologias::adicionaTecnologia(const string& nomeTecno)
{
	for (auto it = tecnologias.begin(); it != tecnologias.end(); ++it)
		if (it->first == nomeTecno)
			it->second = true;
}
