
#ifndef __RECURSO_ABANDONADO__
#define __RECURSO_ABANDONADO__

#include "Eventos.h"
#include "Imperio.h"

class RecursoAbandonado : public Eventos
{
public:
	bool acaoEvento(Imperio* imp, const int& ano);
};

#endif //__RECURSO_ABANDONADO__
