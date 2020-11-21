
#include "Mundo.h"
#include "Imperio.h"

#include <iostream>
#include <sstream>
#include <random>

using std::endl;
using std::ostringstream;

/* FUNCOES PRIVADAS */
Territorio* Mundo::procuraTerritorioMundo(const string& nome)
{
	// Procura no mundo um territorio com o nome passado por argumento
	for (auto it = territorios.begin(); it != territorios.end(); it++)
		if ((*it)->obtemNome() == nome)
			return (*it);

	// Caso o territorio nao exista no Mundo
	return nullptr;
}

Territorio* Mundo::procuraTerritorioImperio(const string& nome)
{
	return jogador->procuraTerritorio(nome);
}

/* FUNCOES PUBLICAS */
Mundo::Mundo(){
	jogador = new Imperio();
	jogador->adicionaTerritorio(criaTerritorio("Territorio Inicial"));
}

Territorio* Mundo::criaTerritorio(const string& tipo)
{
	Territorio* novo = new Territorio(tipo,1,1,1,1);
	territorios.emplace_back(novo);
	return novo;
}

string Mundo::obtemTerritoriosMundoString() const
{
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); it++) {
		oss << (*it)->obtemNome() << (*it)->obtemResistencia() <<
			(*it)->obtemCriacaoProdutos() << (*it)->obtemCriacaoOuro() <<
			(*it)->obtemPontosVitoria() << endl;
	}
	return oss.str();
}

void Mundo::conquistaTerritorio(const string& territorio)
{
	// Se o territorio existir no Mundo
	Territorio* procuraMundo = procuraTerritorioMundo(territorio);
	if (procuraMundo != nullptr) {
		// Se o territorio nao pertencer ao imperio
		if (jogador->procuraTerritorio(territorio) == nullptr) {
			int resAtacado = procuraMundo->obtemResistencia();
			
			// Inicia o gerador aleatorio entre 1 e 6
			std::default_random_engine gerador;
			std::uniform_int_distribution<int> randomInt(1, 6);
			int forcaAtaque = randomInt(gerador) + jogador->obtemForcaMilitar();

			if (forcaAtaque >= resAtacado) {
				// Conquista o territorio
				jogador->adicionaTerritorio(procuraMundo);
			}
			else
				jogador->perderForcaMilitar(1);
		}
	}
}

string Mundo::obtemTerritoriosImperioString() const
{
	return jogador->obtemImperioString();
}

