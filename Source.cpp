
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
	Interface* interface = new Interface{ mundo };

	interface->menu();

	// Apagar objetos em memoria dinâmica
	delete mundo;
	delete interface;

	return 0;
}