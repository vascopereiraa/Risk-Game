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

bool Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;
	int a = 0;

	if (comando == "avanca") { ++turno; ++fases; }

	if (comando == "passa") {
		++fases;
		if (fases == 5) {
			++turno;
			fases = 1;
		}
		if (turno == 2) { //Jogo vai terminar, mostrar pontuação
			exit(1);
		}
	}
	if (turno == 0) {
		// Seletor de comandos
		if (comando == "carrega") { cmdCarrega(iss); return true; }

		if (comando == "cria") { cmdCria(iss); return true; }
	} 
	if (fases == 1) {
		if (comando == "conquista") { cmdConquista(iss); return true; }
		if (comando == "passar") { cout << "O jogador passou o turno!" << endl; }
	}
	if (fases == 2) {//Fase de recolha de produtos e ouro criados
	}
	if (fases == 3) {//Fase de compra de unidades militares e de tecnologia
		if(comando == "maismilitar") {}
		if(comando == "adquire") {}
	}
	if (fases == 4) {//Ocorrência de um Evento
	}
		if (comando == "lista") { cmdLista(iss); return true; }

	return false;

}

Interface::Interface(Mundo* m) : mundo(m),turno(0),fases(0)
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