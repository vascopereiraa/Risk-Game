#include "Mundo.h"
#include "Imperio.h"

#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::ostringstream;
using std::ifstream;
using std::getline;

Mundo::Mundo(){
	Imperio* novoJog = new Imperio();
	jogador = novoJog;
	Territorio* terrInicial = criaTerritorio("Inicial");
	jogador->adicionaTerr(terrInicial);
}

Territorio* Mundo::criaTerritorio(const string& tipo)
{
	Territorio* novo = new Territorio(tipo,1,1,1,1);

	territorios.emplace_back(novo);

	return novo;
}

string Mundo::obtemTerritorios() const
{

	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); it++) {
		oss << (*it)->nome << " " << (*it)->resist << " " << (*it)->CriaOuro <<
			" " << (*it)->CriaProd << " " << (*it)->PontosVit << endl;
	}
	return oss.str();
}


//void Mundo::criaTerritorioFicheiro(const string& nomeFicheiro)
//{
//	ifstream ficheiro(nomeFicheiro);
//	string tipo;
//	if (ficheiro.is_open() && ficheiro.good())
//		while (getline(ficheiro, tipo))
//			criaTerritorio(tipo);
//	ficheiro.close();
//}

//bool Mundo::verificaExisteTerritorio(const string& nome) const
//{
//	for (auto it = territorios.begin(); it != territorios.end(); it++) {
//		if (it->obtemNome() == nome)
//			return true;
//	}
//	return false;
//}

//void Mundo::conquistaTerritorio(string territorio)
//{
//	if (verificaExisteTerritorio(territorio))
//		cout << "Parte a conquista!" << endl;
//	else
//		cout << "Nao existe nenhum territorio com esse nome" << endl;
//}
