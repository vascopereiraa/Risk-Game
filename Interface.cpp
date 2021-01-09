#include "Mundo.h"
#include "Interface.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;
using std::ifstream;

void Interface::cmdCarrega(istringstream& iss) 
{
	string nomeFicheiro;
	iss >> nomeFicheiro;
	if (iss.fail()) {
		std::cerr << "[FAIL] Impossivel obter nome de ficheiro" << endl;
		return;
	}
	// ABRIR FICHEIRO E LER LINHA A LINHA
	abreFicheiro(nomeFicheiro);
}

void Interface::abreFicheiro(const string& nome)
{
	ifstream ficheiro(nome);
	string linha, tipo;

	if (ficheiro.is_open() && ficheiro.good())
		while (getline(ficheiro, linha)) {
			comandos(linha);
		}
	ficheiro.close();
}

void Interface::cmdCria(istringstream& iss)
{
	string tipo;
	int num;
	iss >> tipo >> num;
	for (int i = 0; i < num; i++)
		mundo->criaTerritorio(tipo);
}

void Interface::cmdConquista(istringstream& iss)
{
	string nome;
	iss >> nome;
	cout << mundo->verificaTerritorioConquista(nome);
}

void Interface::cmdLista(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) 
		cout << *mundo << endl;
	else
		cout << mundo->obtemDadosTerritorioMundoString(nome) << endl;
	
}

void Interface::cmdAdquire(istringstream& iss)
{
	string nome;
	iss >> nome;
	cout << mundo->verificaTecnologiaAdquirir(nome) << endl;
}

void Interface::cmdFevento(istringstream& iss)
{
	string nome;
	iss >> nome;
}

void Interface::cmdMaisMilitar()
{
	if (mundo->adquireForcaMilitar())
		cout << "Forca Militar aumentada!" << endl;
	else
		cout << "Nao foi possivel aumentar a forca militar" << endl;
}

void Interface::cmdMaisOuro()
{
	if (mundo->adquireOuro())
		cout << "Ouro adquirido!" << endl;
	else
		cout << "Nao foi possivel adquirir ouro" << endl;
}

void Interface::cmdMaisProd()
{
	if (mundo->adquireProduto())
		cout << "Produto adquirido!" << endl;
	else
		cout << "Nao foi possivel adquirir produto" << endl;
}

void Interface::cmdModifica(istringstream& iss)
{
	string tipo;
	int n;
	iss >> tipo >> n;

	if (tipo == "ouro")
		mundo->acrescentaOuroImperio(n);
	
	if (tipo == "prod")
		mundo->acrescentaProdImperio(n);

}

void Interface::cmdGrava(istringstream& iss)
{
	string nome;
	iss >> nome;

	if (iss.fail()) 
	{
		cout << "Introduza o nome pelo qual pretende guardar o jogo" << endl;
		return;
	}
	if(gravacoes.find(nome) != gravacoes.end()) 
	{
		cout << "Ja existe uma gravacao com esse nome" << endl;
		return;
	}

	Mundo* novo = new Mundo(*mundo);
	gravacoes.insert(std::pair<string, Mundo*>(nome, novo));

	cout << "Foi gravada uma copia do jogo segundo o nome " << nome << endl;

	for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
		cout << it->first << " " << *(it->second) << endl;
}

void Interface::cmdAtiva(istringstream& iss)
{
	string nome;
	iss >> nome;

	if (iss.fail()) {
		cout << "Insira o nome da gravacao que pretende ativar" << endl;
		return;
	}

	auto it = gravacoes.find(nome);
	if(it != gravacoes.end())
	{
		delete mundo;
		mundo = (it->second);
		gravacoes.erase(nome);
		return;
	}
	
}

void Interface::cmdListaGravacoes(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) {
		cout << "Gravacoes disponiveis: " << endl;
		for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
			cout << it->first << endl;
	}
	else
		for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
			if(it->first == nome)
				cout << "\n" << *(it->second) << endl;
			
}

bool Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;

	// Comandos de Debug
	if (comando == "modifica") { cmdModifica(iss); return true; }
	
	// Comandos gerais do jogo
	if (comando == "avanca" || comando == "passar") { 
		cout << mundo->avancaTempo();
		return true; 
	}
	if (comando == "lista") { cmdLista(iss); return true; }
	if (comando == "fevento") { cmdFevento(iss); return true; }
	if (comando == "grava") { cmdGrava(iss); return true; }
	if (comando == "mostra") { cmdListaGravacoes(iss); return true; }
	if (comando == "ativa") { cmdAtiva(iss); return true; }
	
	// Seletor de comandos das fases
	switch (mundo->obtemFase()) {
	case 0:
		if (comando == "carrega") { cmdCarrega(iss); return true; }
		if (comando == "cria") { cmdCria(iss); return true; }
		break;
	case 1:
		if (comando == "conquista") { cmdConquista(iss); return true; }
		break;
	case 3:
		if (comando == "maismilitar") { cmdMaisMilitar(); return true; }
		if (comando == "maisouro") { cmdMaisOuro(); return true; }
		if (comando == "maisprod") { cmdMaisProd(); return true; }
		if (comando == "adquire") { cmdAdquire(iss);  return true; }
		break;
	default:
		break;
	}

	return false;
}

Interface::Interface(Mundo* m) : mundo(m)
{
}

void Interface::menu()
{
	string linha;
	cout << mundo->obtemTempo();
	do 
	{
		cout << "\nComando: ";
		getline(cin, linha);
		if (comandos(linha) == false) {
			cout << "[AVISO] O comando que introduziu nao esta disponivel!" << endl;
			cout << "Comando: " << linha << endl << endl;
		}
	} while (!mundo->verificaFimJogo() && linha != "sair");

	return;
}