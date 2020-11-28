
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
	Interface interface{ mundo };

	//cout << *mundo << endl;

	string linha, comando;
	do {
		cout << "Comando: ";
		getline(cin, linha);
		interface.menu(linha);
	} while (linha != "sair");

	return 0;
}