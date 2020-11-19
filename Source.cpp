#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

#include "Mundo.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;
using std::tolower;

int main() {

	/* Fase de Configuracao */
	Mundo* mundo = new Mundo();
	
	string linha, comando;
	do {
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

		cout << endl;
		cout << mundo->obtemTerritorios() << endl;

	} while (comando != "sair");


	return 0;
}