
#ifndef __INVASAO__
#define __INVASAO__

#include "Evento.h"

class Invasao : public Evento
{
public:
	string acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo) override;

};

#endif //__INVASAO__
