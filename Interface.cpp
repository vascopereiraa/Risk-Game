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

bool Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;
	int a = 0;

	// Seletor de comandos
	if (comando == "avanca") { return true; }

	if (comando == "passa") { return true; }
	
	if (comando == "carrega") { cmdCarrega(iss); return true; }

	if (comando == "cria") { cmdCria(iss); return true; }
	 
	if (comando == "conquista") { cmdConquista(iss); return true; }
	
	if (comando == "passar") { 
		cout << "O jogador passou o turno!" << endl; 
		return true; 
	}

	if(comando == "maismilitar") { return true; }

	if (comando == "adquire") { cmdAdquire(iss);  return true; }

	if (comando == "lista") { cmdLista(iss); return true; }

	return false;
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
		if (comandos(linha) == false) {
			cout << "[AVISO] O comando que introduziu nao existe!" << endl;
			cout << "Comando: " << linha << endl << endl;
		}
	} while (linha != "sair");

	return;
}