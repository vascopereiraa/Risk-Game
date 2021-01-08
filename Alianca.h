
#ifndef __ALIANCA__
#define __ALIANCA__


#include "Eventos.h"
#include "Imperio.h"

class Alianca : public Eventos
{
public:
	bool acaoEvento(Imperio* imp, const int& ano);
};

#endif //__ALIANCA__ 

