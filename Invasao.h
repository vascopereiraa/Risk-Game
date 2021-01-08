
#ifndef __INVASAO__
#define __INVASAO__

#include "Eventos.h"

class Invasao : public Eventos
{
public:
	bool acaoEvento(Imperio* imp, const int& ano);

};

#endif //__INVASAO__
