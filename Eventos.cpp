#include "Eventos.h"
#include "RecursoAbandonado.h"
#include "Alianca.h"
#include "Invasao.h"
#include "Imperio.h"

#include <iostream>
#include <random>


using std::string;

string Eventos::lancaEvento(Imperio* imp, const int& ano)
{
	Eventos* novo;
	int numEvento = rand() % (4 - 1 + 1) + 1;
	switch (numEvento)
	{
	case 1:
		novo = new RecursoAbandonado();
		novo->acaoEvento(imp, ano);
		delete novo;
		return string{ "Ocorreu o evento \"Recurso Abandonado\"\n" };
		break;
	case 2:
		novo = new Alianca();
		novo->acaoEvento(imp, ano);
		delete novo;
		return string{ "Ocorreu o evento \"Alianca Diplomatica\"\n" };
		break;
	case 3:
		novo = new Invasao();
		novo->acaoEvento(imp, ano);
		delete novo;
		return string{ "Ocorreu o evento \"Invasao\"\n" };
		break;
	default:
		return string{ "Nao ocorreu nenhum evento neste turno!\n" };
		break;
	}
}

bool Eventos::acaoEvento(Imperio* imp, const int& ano)
{
	return true;
}
