#pragma once
#include "Eventos.h"
#include "Imperio.h"

class Alianca : public Eventos
{
public:
	bool acaoEvento(Imperio* imp, const int& ano);
};

