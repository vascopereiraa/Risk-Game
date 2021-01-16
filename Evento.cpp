#include "Evento.h"
#include "RecursoAbandonado.h"
#include "Alianca.h"
#include "Invasao.h"
#include "Imperio.h"

#include <iostream>
#include <random>

using std::string;

Evento* Evento::sorteiaEvento(Mundo* mundo)
{
	int num = mundo->geraAleatorio(1, 4);

	if (num == 1)
		return lancaEvento("Invasao");

	if (num == 2)
		return lancaEvento("Alianca");

	if (num == 3)
		return lancaEvento("RecursoAbandonado");

	if (num == 4)
		return lancaEvento("Nenhum");
	
	return nullptr;
}

Evento* Evento::lancaEvento(const string& evento)
{
	if (evento == "Invasao")
		return new Invasao;

	if (evento == "Alianca")
		return new Alianca;

	if (evento == "RecursoAbandonado")
		return new RecursoAbandonado;

	if (evento == "Nenhum")
		return new Evento;
	
	return nullptr;
}	

string Evento::acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo)
{
	return string{ "Nao ocorreu nenhum evento!\n" };
}
