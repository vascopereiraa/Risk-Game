#include "Invasao.h"
#include "Imperio.h"

string Invasao::acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo)
{
	string info{ "Ocorreu o evento \"Invasao\"\n" };
	Territorio* alvo = imperio->procuraTerritorio(imperio->obtemNomeUltimoTerritorio());
	int forcaAtaque;
	int fatorRand = mundo->geraAleatorio(1, 6);

	if (ano == 1)
		forcaAtaque = fatorRand + 2;
	else
		forcaAtaque = fatorRand + 3;

	if (forcaAtaque >= alvo->obtemResistencia() + imperio->verificaExisteTecnologiaImperio("defesas")) {
		if (imperio->removeTerritorio(alvo))
			info += "O territorio " + alvo->obtemNome() + " foi tomado de assalto durante o Evento!\n";
		else
			info += "A tua defesa permaneceu intacta!\n";
	}
	else			
		info += "A invasao fracassou!\n";


	return info;
}
