#include "Eventos.h"
#include "Imperio.h"
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

	std::default_random_engine gerador;
	std::uniform_int_distribution<int> randomInt(1, 6);
	int random = randomInt(gerador);
	
	if(ano == 1)
		forcaAtaque = randomInt(gerador) + 2;
	else
		forcaAtaque = randomInt(gerador) + 3;

	if (forcaAtaque > alvo->obtemResistencia() + imp->verificaTecnologia("defesas")) {
		if (imp->removeTerritorio(alvo))
			return true;
		else
			return false;
	}

}

void Eventos::alianca(Imperio* imp)
{
}
