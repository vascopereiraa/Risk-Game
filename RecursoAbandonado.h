
#ifndef __RECURSO_ABANDONADO__
#define __RECURSO_ABANDONADO__

#include "Evento.h"
#include "Imperio.h"

class RecursoAbandonado : public Evento
{
public:
	string acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo) override;
};

#endif //__RECURSO_ABANDONADO__
