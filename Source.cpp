
#include "Mundo.h"

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

	return 0;
}