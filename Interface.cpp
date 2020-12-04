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
	if (iss.fail())
		std::cerr << "[FAIL] Impossivel obter nome de ficheiro" << endl;

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
	mundo->conquistaTerritorio(nome);
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

void Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;

	// Seletor de comandos
	if (comando == "carrega") { cmdCarrega(iss); }

	if (comando == "cria") { cmdCria(iss); }

	if (comando == "conquista") { cmdConquista(iss); }

	if (comando == "lista") { cmdLista(iss); }
}

Interface::Interface(Mundo* m) : mundo(m)
{
}

void Interface::menu()
{
	string linha;
	do 
	{
		cout << "Comando: ";
		getline(cin, linha);
		comandos(linha);
	} while (linha != "sair");

	return;
}