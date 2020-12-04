
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
	// Inicializacao dos objetos do jogo
	Mundo* mundo = new Mundo();
	Interface* interface = new Interface{ mundo };

	// Chamada a interface
	interface->menu();

	// Apagar objetos em memoria din�mica
	delete mundo;
	delete interface;

	return 0;
}
