#include "Alianca.h"

string Alianca::acaoEvento(Imperio* imperio, const int& ano, Mundo* mundo)
{
    imperio->acrescentaForcaMilitar(1);
    return string{ "Ocorreu o evento \"Alianca Diplomatica\"\nFoi acrecentada uma unidade de Forca à Forca Militar\n" };
}
