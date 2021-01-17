
#ifndef __ALIANCA__
#define __ALIANCA__


#include "Evento.h"

class Alianca : public Evento
{
public:
	string acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo) override;
};

#endif //__ALIANCA__ 

