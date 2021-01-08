#include "RecursoAbandonado.h"

bool RecursoAbandonado::acaoEvento(Imperio* imp, const int& ano)
{
	if (ano == 1)
		imp->acrescentaProduto(1);
	else
		imp->acrescentaOuro(1);
	return true;
}
