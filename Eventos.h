#pragma once
class Imperio;

class Eventos
{
public:
	string lancaEvento(Imperio* imp, const int& ano);
	virtual bool acaoEvento(Imperio* imp, const int& ano);
};

