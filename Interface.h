#ifndef INTERFACE_H
#define INTERFACE_H

#include <sstream>

using std::istringstream;

class Interface
{
	Mundo* mundo;
	map<string, Mundo*> gravacoes;

private:
	void cmdCarrega(istringstream& iss);
	void abreFicheiro(const string& nome);
	void cmdCria(istringstream& iss);
	void cmdConquista(istringstream& iss);
	void cmdLista(istringstream& iss);
	void cmdAdquire(istringstream& iss);
	void cmdFevento(istringstream& iss);
	void cmdMaisMilitar();
	void cmdMaisOuro();
	void cmdMaisProd();
	void cmdModifica(istringstream& iss);
	void cmdGrava(istringstream& iss);
	void cmdAtiva(istringstream& iss);
	void cmdListaGravacoes(istringstream& iss);
	bool comandos(const string& iss);

public:
	Interface(Mundo* m);
	void menu();
};


#endif
