#include "Mina.h"

int Mina::numMina = 0;

Mina::Mina()
{
	nome = "Mina" + std::to_string(++numMina);
}

string Mina::obtemNome() const
{
	return nome;
}

int Mina::obtemResistencia() const
{
	return 5;
}

int Mina::obtemCriacaoProdutos(const int& ano, const int& turno) const
{
	return 0;

}

int Mina::obtemCriacaoOuro(const int& ano, const int& turno) const
{
	return turno <= 3 ? 1 : 2;
}

Territorio* Mina::duplica() const
{
	return new Mina(*this);
}
