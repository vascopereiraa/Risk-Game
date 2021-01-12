
#ifndef __EVENTO__
#define __EVENTO__

#include "Imperio.h"
#include "Mundo.h"

class Evento
{
public:
	static Evento* sorteiaEvento(Mundo* mundo);
	static Evento* lancaEvento(const string& evento);
	virtual string acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo);
};

#endif //__EVENTO__