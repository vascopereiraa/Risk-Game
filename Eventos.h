#pragma once
class Imperio;

class Eventos
{
public:
	void recursoAbandonado(Imperio* imp, const int& ano);
	bool invasao(Imperio* imp, const int& ano);
	void alianca(Imperio* imp);
};

