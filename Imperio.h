
#ifndef Jogador_H
#define Jogador_H

#include "Territorio.h"
#include "Tecnologias.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Mundo;

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

	/*
	*		O Construtor por Cópia do Imperio apenas faz sentido no conceito do Mundo,
	*	nao por si proprio, visto que a sua copia exata iria copiar ponteiros para territorios
	*	idesejados no vetor criado pela copia, que seriam correspondentes ao mundo antigo, nao ao
	*	novo copiado, assim sendo, a copia os territorios apontados pelo imperio e' uma das 
	*	resposabilidades do Mundo.
	*/

	Imperio(const Imperio& original);
	Imperio& operator=(const Imperio& outro);

	// Obter dados da Classe
	int obtemArmazem() const;
	int obtemCofre() const;
	int obtemForcaMilitar() const;
	int obtemCapacidadeArmazem() const;
	int obtemCapacidadeCofre() const;
	int obtemMaxForcaMilitar() const;
	int obtemNumeroTerritorios() const;
	bool verificaTecnologia(const string& nomeTecno) const;
	string obtemImperioString(const int& ano, const int& fase) const;
	string obtemNomeUltimoTerritorio() const;

	// Logica do Jogo
	Territorio* procuraTerritorio(const string& nome);
	void adicionaTerritorio(Territorio* novo);
	bool removeTerritorio(Territorio* apaga);
	void perderForcaMilitar(const int factor);
	bool conquistaTerritorio(Territorio* territorioConquista, Mundo* mundo);
	bool adquireTecnologia(const string& nomeTecno);
	void alteraImperio(const string& nomeTecno);
	int acrescentaOuro(const int& ouro);
	int acrescentaProduto(const int& produto);
	int acrescentaForcaMilitar(const int& forca);
	int recolheProdutos(const int& ano, const int& turno);
	int recolheOuro(const int& ano, const int& turno);
	bool maisMilitar();
	bool maisProduto();
	bool maisOuro();
};


#endif // !Jogador_H


