#ifndef INTERFACE_H
#define INTERFACE_H

#include <sstream>

using std::istringstream;

class Interface
{
	Mundo* mundo;

private:
	void cmdCarrega(istringstream& iss);
	void abreFicheiro(const string& nome);
	void cmdCria(istringstream& iss);
	void cmdConquista(istringstream& iss);
	void cmdLista(istringstream& iss);

public:
	Interface(Mundo* m);
	void menu(const string& linha);
};


#endif
