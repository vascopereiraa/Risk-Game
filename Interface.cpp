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

void Interface::cmdFevento(istringstream& iss)
{
	string nome;
	iss >> nome;
	//
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
	if (mundo->adquireForcaMilitar())
		cout << "Produto adquirido!" << endl;
	else
		cout << "Nao foi possivel adquirir produto" << endl;
}

void Interface::cmdRecolha()
{
	mundo->recolheProdutosOuro();
}

void Interface::cmdOcorreEvento()
{
	mundo->geraEvento();
}


bool Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;

	// Seletor de comandos
	switch (mundo->obtemFase()) {
		if (comando == "avanca" || comando == "passar") { 
			mundo->avancaTempo();
			cout << "O jogador passou o turno!" << endl;
			return true; 
		}
		if (comando == "lista") { cmdLista(iss); return true; }
		if (comando == "fevento") { cmdFevento(iss); return true; }
	case 0:
		if (comando == "carrega") { cmdCarrega(iss); return true; }
		if (comando == "cria") { cmdCria(iss); return true; }
	case 1:
		if (comando == "conquista") { cmdConquista(iss); return true; }
	case 2:
		cmdRecolha();
		mundo->avancaTempo();
	case 3:
		if (comando == "maismilitar") { cmdMaisMilitar(); return true; }
		if (comando == "maisouro") { cmdMaisOuro(); return true; }
		if (comando == "maisprod") { cmdMaisProd(); return true; }
		if (comando == "adquire") { cmdAdquire(iss);  return true; }
	case 4:
		cmdOcorreEvento();
		mundo->avancaTempo();
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