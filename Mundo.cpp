
#include "Mundo.h"
#include "Imperio.h"
#include "TerritorioInicial.h"
#include "Duna.h"
#include "Montanha.h"
#include "Mina.h"
#include "Planicie.h"
#include "Castelo.h"
#include "Fortaleza.h"
#include "Pescaria.h"
#include "Refugio.h"

#include <iostream>
#include <sstream>

using std::endl;
using std::ostringstream;

/* FUNCOES PRIVADAS */
Territorio* Mundo::procuraTerritorioMundo(const string& nome)
{
	// Procura no mundo um territorio com o nome passado por argumento
	for (auto it = territorios.begin(); it != territorios.end(); it++)
		if ((*it)->obtemNome() == nome)
			return (*it);

	// Caso o territorio nao exista no Mundo
	return nullptr;
}

Territorio* Mundo::procuraTerritorioImperio(const string& nome)
{
	return jogador->procuraTerritorio(nome);
}

/* FUNCOES PUBLICAS */
Mundo::Mundo() : ano(1), fase(1), turno(1)
{
	jogador = new Imperio();
	jogador->adicionaTerritorio(criaTerritorio("Territorio Inicial"));
}

Mundo::~Mundo()
{
	// Apagar os territórios que pertencem ao mundo (composição)
	for (int i = 0; i < territorios.size(); i++)
		delete territorios[i];

	// Apagar o jogador
	delete jogador;
}


Territorio* Mundo::criaTerritorio(const string& tipo)
{
	Territorio* novo;
	if (tipo == "Territorio Inicial") {
		novo = new TerritorioInicial;
		territorios.emplace_back(novo);
		return novo;
	}
	//Continentes
	if (tipo == "Duna") {
		novo = new Duna;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Planicie") {
		novo = new Planicie;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Castelo") {
		novo = new Castelo;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Fortaleza") {
		novo = new Fortaleza;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Mina") {
		novo = new Mina;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Montanha") {
		novo = new Montanha;
		territorios.emplace_back(novo);
		return novo;
	}
	//Ilhas
	if (tipo == "Pescaria") {
		novo = new Pescaria;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Refugio") {
		novo = new Refugio;
		territorios.emplace_back(novo);
		return novo;
	}
	else {
		std::cout << "\nTIPO: " << tipo << " AINDA NAO CRIADO\n";
		return nullptr;
	}
}

string Mundo::obtemTerritoriosMundoString() const
{
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); it++) {
		oss << (*it)->obtemTerritorioString(ano, fase) << endl;
	}
	return oss.str();
}

string Mundo::obtemDadosTerritorioMundoString(const string& nome)
{
	Territorio* procura = procuraTerritorioMundo(nome);
	if (procura == nullptr)
		return string{ "Nao existe nenhum territorio com o nome introduzido!\n" };
	else
		return procura->obtemTerritorioString(ano, fase);
}

string Mundo::verificaTerritorioConquista(const string& territorio)
{
	// Se o territorio existir no Mundo
	Territorio* procuraMundo = procuraTerritorioMundo(territorio);
	if (procuraMundo != nullptr) {
		if (jogador->conquistaTerritorio(procuraMundo))
			return string{ "O territorio " + territorio + " foi conquistado!\n" };
		else
			return string{ "Nao foi possivel conquistar o territorio " + territorio + "\n" };
	}
	else
		return string{ "O Territorio " + territorio + " nao existe no mundo\n" };
}

string Mundo::obtemTerritoriosImperioString() const
{
	return jogador->obtemImperioString(ano, turno);
}

string Mundo::verificaTecnologiaAdquirir(const string& nomeTecno)
{
	if (jogador->verificaTecnologia(nomeTecno) == 0) {
		std::cout << "\nENTREI AQUIIIIIII \n\n";
		if(jogador->adquireTecnologia(nomeTecno))
			return string{ "A tecnologia " + nomeTecno + " foi adicionada ao imperio\n" };
	}
	else
		return string{ "A tecnologia " + nomeTecno + " nao foi adicionada ao imperio\n" };
}

void Mundo::avancaTempo()
{
	++fase;
	if (fase == 4) {
		++turno;
		fase = 1;
	}
	if (turno == 6) {
		++ano;
		turno = 1;
	}
}

ostream& operator<<(ostream& out, const Mundo& novoM) {

	out << "\nTerritorios do Mundo: " << endl;
	out << novoM.obtemTerritoriosMundoString();

	out << "-----------------------------------------------------------"
		   "-----------------------------------------------------------\n\n";

	out << "Informacoes sobre o Imperio e seus territorios: " << endl;
	out << novoM.obtemTerritoriosImperioString();

	return out;
}