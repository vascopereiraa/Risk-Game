
#ifndef __EVENTOS__
#define __EVENTOS__

#include "Imperio.h"

class Eventos
{
public:
	string lancaEvento(Imperio* imp, const int& ano);
	virtual bool acaoEvento(Imperio* imp, const int& ano);
};

#endif //__EVENTOS__