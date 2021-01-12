#include "RecursoAbandonado.h"


string RecursoAbandonado::acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo)
{
	string info{ "Ocorreu o evento \"Recurso Abandonado\"\n" };
	if (ano == 1) {
		imperio->acrescentaProduto(1);
		info += "Foi acrescentada uma unidade de produto ao Armazem do Imp�rio!\n";
	}
	else {
		imperio->acrescentaOuro(1);
		info += "Foi acrescentada uma unidade de ouro ao Cofre do Imp�rio!\n";
	}

	return info;
}
