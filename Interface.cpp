#include "Mundo.h"
#include "Interface.h"
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;


//void Interface::inicio() const
//{
//	string linha, comando;
//
//	do {
//		cout << "Comando: ";
//		getline(cin, linha);
//		istringstream iss(linha);
//		iss >> comando;
//
//		if (comando == "carrega") {
//			string nomeFicheiro;
//			iss >> nomeFicheiro;
//			mundo->criaTerritorioFicheiro(nomeFicheiro);
//		}
//
//		if (comando == "cria") {
//			string tipo;
//			int num;
//			iss >> tipo >> num;
//			for (int i = 0; i < num; i++)
//				mundo->criaTerritorio(tipo);
//		}
//
//		if (comando == "conquista") {
//			string nome;
//			iss >> nome;
//			mundo->conquistaTerritorio(nome);
//		}
//
//		cout << endl;
//		cout << mundo->obtemTerritorios() << endl;
//
//	} while (comando != "sair");
//
//}
