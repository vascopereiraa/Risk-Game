#include "Invasao.h"
#include "Imperio.h"

bool Invasao::acaoEvento(Imperio* imp, const int& ano)
{
	Territorio* alvo = imp->procuraTerritorio(imp->obtemNomeUltimoTerritorio());
	int forcaAtaque;
	int fatorRand = rand() % (6 - 1 + 1) + 1;

	if (ano == 1)
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
