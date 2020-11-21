#include <iostream>
#include <string>
#include <sstream>

#include "Mundo.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;

int main() {

	/* Fase de Configuracao */
	Mundo* mundo = new Mundo();
	
	string linha, comando;

	mundo->criaTerritorio("Novo");
	mundo->criaTerritorio("Novo");
	mundo->criaTerritorio("Novo");

	cout << "Todos os territorios" << endl; 

	cout << mundo->obtemTerritorios() << endl;

	cout << "Territorios do imperio" << endl;

	cout << mundo->jogador->obtemImperio() << endl;

	/*do {
		cout << "Comando: ";
		getline(cin, linha);
		istringstream iss(linha);
		iss >> comando;
		
		if (comando == "carrega") {
			string nomeFicheiro;
			iss >> nomeFicheiro;
			mundo->criaTerritorioFicheiro(nomeFicheiro);
		}

		if (comando == "cria") {
			string tipo;
			int num;
			iss >> tipo >> num;
			for (int i = 0; i < num; i++)
				mundo->criaTerritorio(tipo);
		}

		if (comando == "conquista") {
			string nome;
			iss >> nome;
			mundo->conquistaTerritorio(nome);
		}

		cout << endl;
		cout << mundo->obtemTerritorios() << endl;

	} while (comando != "sair");*/


	return 0;
}

// Perguntas:

/*
* 
*  Como guardar os diferentes grupos de territorios?  //class "tipo de territorio"
*  Como gerir o jogador? (Guardar dados do jogador, criação do Terr Ini) // 
*  Como declarar Territorio Inicial ?
*  
*/