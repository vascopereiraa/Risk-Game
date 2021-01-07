#include "Eventos.h"
#include "Imperio.h"

#include <iostream>
#include <random>

void Eventos::recursoAbandonado(Imperio* imp, const int& ano)
{
	if (ano == 1)
		imp->acrescentaProduto(1);
	else
		imp->acrescentaOuro(1);
}

bool Eventos::invasao(Imperio* imp, const int& ano)
{
	Territorio* alvo = imp->procuraTerritorio(imp->obtemNomeUltimoTerritorio());
	int forcaAtaque;
	int fatorRand = rand() % (6 - 1 + 1) + 1;
	
	if(ano == 1)
		forcaAtaque = fatorRand + 2;
	else
		forcaAtaque = fatorRand + 3;

	if (forcaAtaque >= alvo->obtemResistencia() + imp->verificaTecnologia("defesas")) {
		if (imp->removeTerritorio(alvo))
			return true;
		else
			return false;
	}

}

void Eventos::alianca(Imperio* imp)
{
	imp->maisMilitar();
}
