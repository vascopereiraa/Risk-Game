
#include "Mundo.h"
#include "Interface.h"

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;

int main() 
{
	/* Fase de Configuracao */
	Mundo* mundo = new Mundo();
	Interface teste;

	mundo->criaTerritorio("Portugal");
	mundo->criaTerritorio("Espanha");
	mundo->criaTerritorio("Franca");
	mundo->criaTerritorio("Italia");

	cout << "Todos os territorios" << endl;
	cout << mundo->obtemTerritoriosMundoString() << endl;

	cout << "Territorios do imperio" << endl;
	cout << mundo->obtemTerritoriosImperioString() << endl;

	mundo->conquistaTerritorio("Portugal2");
	cout << mundo->obtemTerritoriosImperioString() << endl;

	cout << endl << endl << endl;

	teste.inicio(*mundo);

	return 0;
}