#include "Mundo.h"
#include "Interface.h"
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;


void Interface::inicio(Mundo& mundo)
{
	string linha, comando;
	do {
		cout << "Comando: ";
		getline(cin, linha);
		istringstream iss(linha);
		iss >> comando;

		if (comando == "carrega") { cmdCarrega(linha,mundo);}

		if (comando == "cria") { cmdCria(linha, mundo); }

		if (comando == "conquista") { cmdConquista(linha,mundo);	}

		if (comando == "lista") { cmdLista(linha,mundo); }

		cout << endl;
		//cout << "Territorios do Imperio " << mundo.obtemTerritoriosImperioString() << endl;

	} while (comando != "sair");

}

void Interface::cmdCarrega(string linha, Mundo &mundo) 
{
	istringstream iss(linha);
	string nomeFicheiro, lixo;
	iss >> lixo >> nomeFicheiro;
	//mundo->criaTerritorioFicheiro(nomeFicheiro);
}

void Interface::cmdCria(string linha, Mundo &mundo) 
{
	istringstream iss(linha);
	string tipo, lixo;
	int num;
	iss >> lixo >> tipo >> num;
	// foi criado lixo pois a funcao recebe a linha desde o inicio
	// ainda com o comando nela como 1º palavra
	for (int i = 0; i < num; i++)
		mundo.criaTerritorio(tipo);
}

void Interface::cmdConquista(string linha, Mundo& mundo) 
{
	istringstream iss(linha);
	string nome, lixo;
	iss >> lixo >> nome;
	mundo.conquistaTerritorio(nome);
}

void Interface::cmdLista(string linha, Mundo& mundo) 
{
	cout << "Territorios do Imperio:" << endl << mundo.obtemTerritoriosImperioString() << endl;
	cout << "Territorios do Mundo:" << endl << mundo.obtemTerritoriosMundoString() << endl;
}

void Interface::mostraTerritoriosMundo(Mundo& mundo) const
{
	cout << "Territórios do Mundo: " << mundo.obtemTerritoriosMundoString() << endl;
}

void Interface::mostraTerritoriosImperio(Mundo& mundo) const
{
	cout << "Territórios do Império: " << mundo.obtemTerritoriosImperioString() << endl;
}

/* Mostrar Territorios
	oss << "Nome: " << (*it)->obtemNome() << endl <<
	"Resistencia: " << (*it)->obtemResistencia() <<
	"Criacao Produtos: " << (*it)->obtemCriacaoProdutos() <<
	"Criacao Outro: " << (*it)->obtemCriacaoOuro() << endl <<
	"Pontos Vitoria" << (*it)->obtemPontosVitoria() << endl << endl;
*/

