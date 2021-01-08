#pragma once
#include "Eventos.h"
#include "Imperio.h"

class RecursoAbandonado : public Eventos
{
public:
	bool acaoEvento(Imperio* imp, const int& ano);
};

