#include "Alianca.h"

bool Alianca::acaoEvento(Imperio* imp, const int& ano)
{
    imp->maisMilitar();
    return true;
}
