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
			menu(linha);
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
	if (iss.fail()) {
		cout << "Territorios do Mundo: " << endl;
		cout << mundo->obtemTerritoriosMundoString() << endl;
		
		cout << "Territorios do Imperio: " << endl;
		cout << mundo->obtemTerritoriosImperioString() << endl;
	}
	else
		cout << mundo->obtemDadosTerritorioMundoString(nome) << endl;
}

Interface::Interface(Mundo* m) : mundo(m)
{
}

void Interface::menu(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;

	if (comando == "carrega") { cmdCarrega(iss); }

	if (comando == "cria") { cmdCria(iss); }

	if (comando == "conquista") { cmdConquista(iss); }

	if (comando == "lista") { cmdLista(iss); }

}