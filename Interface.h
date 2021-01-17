#ifndef INTERFACE_H
#define INTERFACE_H

#include <sstream>

using std::istringstream;

class Mundo;

class Interface
{
	Mundo* mundo;
	map<string, Mundo*> gravacoes;

private:
	// Comandos
	void cmdCarrega(istringstream& iss);
	void abreFicheiro(const string& nome);
	void cmdCria(istringstream& iss);
	void cmdConquista(istringstream& iss);
	void cmdLista(istringstream& iss);
	void cmdAdquire(istringstream& iss);
	void cmdMaisMilitar();
	void cmdMaisOuro();
	void cmdMaisProd();
	
	//Debug
	void cmdModifica(istringstream& iss);
	void cmdFevento(istringstream& iss);
	void cmdToma(istringstream& iss);
	
	//Gravacoes
	void cmdGrava(istringstream& iss);
	void cmdAtiva(istringstream& iss);
	void cmdApaga(istringstream& iss);
	void cmdListaGravacoes(istringstream& iss);
	void cmdPassa();
	void cmdAvanca();
	
	//Leitura de comandos
	bool comandos(const string& iss);
	void terminaJogo(const int& verificaFim);

public:
	Interface(Mundo* m);
	Mundo* menu();
};


#endif
