
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
	// Inicializar o gerador de numeros aleatorios
	srand(static_cast<unsigned int> (time(NULL)));

	// Inicializacao dos objetos do jogo
	Mundo* mundo = new Mundo();
	Interface* interface = new Interface{ mundo };

	// Chamada a interface
	interface->menu();

	// Apagar objetos em memoria dinâmica
	delete mundo;
	delete interface;

	return 0;
}
