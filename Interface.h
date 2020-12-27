#ifndef INTERFACE_H
#define INTERFACE_H

#include <sstream>

using std::istringstream;

class Interface
{
	Mundo* mundo;
	int turno;
	int fases;

private:
	void cmdCarrega(istringstream& iss);
	void abreFicheiro(const string& nome);
	void cmdCria(istringstream& iss);
	void cmdConquista(istringstream& iss);
	void cmdLista(istringstream& iss);
	bool comandos(const string& iss);

public:
	Interface(Mundo* m);
	void menu();
};


#endif
