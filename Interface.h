#ifndef INTERFACE_H
#define INTERFACE_H



class Interface
{


public:

	void mostraTerritoriosMundo(Mundo & mundo) const;
	void mostraTerritoriosImperio(Mundo& mundo) const;

	//comandos
	void inicio(Mundo& mundo);
	void cmdCarrega(string linha,Mundo& mundo) ;
	void cmdCria(string linha, Mundo& mundo) ;
	void cmdConquista(string linha, Mundo& mundo) ;
	void cmdLista(string linha, Mundo& mundo) ;

};


#endif
