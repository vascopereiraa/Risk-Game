
#ifndef Jogador_H
#define Jogador_H

#include "Territorio.h"
#include "Tecnologias.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Imperio
{
	int capacidadeArmazem;
	int capacidadeCofre;
	int maxForcaMilitar;
	Tecnologias* tecno;

	vector<Territorio*> imperio;
	int armazem;
	int cofre;
	int forcaMilitar;
	
public:
	// Construtores
	Imperio();

	// Obter dados da Classe
	int obtemArmazem() const;
	int obtemCofre() const;
	int obtemForcaMilitar() const;
	int obtemCapacidadeArmazem() const;
	int obtemCapacidadeCofre() const;
	int obtemMaxForcaMilitar() const;
	int obtemNumeroTerritorios() const;
	int verificaTecnologia(const string& nomeTecno) const;
	string obtemImperioString(const int& ano, const int& fase) const;
	string obtemNomeUltimoTerritorio() const;

	// Logica do Jogo
	Territorio* procuraTerritorio(const string& nome);
	void adicionaTerritorio(Territorio* novo);
	bool removeTerritorio(Territorio* apaga);
	void perderForcaMilitar(const int factor);
	bool conquistaTerritorio(Territorio* territorioConquista);
	bool adquireTecnologia(const string& nomeTecno);
	void alteraImperio(const string& nomeTecno);
	void acrescentaOuro(const int& ouro);
	void acrescentaProduto(const int& produto);
};


#endif // !Jogador_H


