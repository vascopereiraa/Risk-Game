
#include "Mundo.h"
#include "Imperio.h"
#include "TerritorioInicial.h"
#include "Duna.h"
#include "Montanha.h"
#include "Mina.h"
#include "Planicie.h"
#include "Castelo.h"
#include "Fortaleza.h"
#include "Pescaria.h"
#include "Refugio.h"

#include <iostream>
#include <sstream>
#include <random>
#include <memory>

using std::endl;
using std::ostringstream;
using std::istringstream;

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
Mundo::Mundo() : ano(1), fase(0), turno(1), ultimoAleatorio(0)
{
	// Imperio
	jogador = new Imperio();
	jogador->adicionaTerritorio(criaTerritorio("Territorio Inicial"));
}

Mundo::Mundo(const Mundo& orig):ano(orig.ano),turno(orig.turno),fase(orig.fase),ultimoAleatorio(orig.ultimoAleatorio)
{
	*this = orig;
}

Mundo::~Mundo()
{
	// Apagar os territórios que pertencem ao mundo (composição)
	for (unsigned int i = 0; i < territorios.size(); i++)
		delete territorios[i];

	// Apagar o jogador
	delete jogador;
}

Mundo& Mundo::operator=(const Mundo& orig)
{
	// Prevencao de auto-atribuicao
	if (this == &orig)
		return *this;

	// Libertar mem. din. velha
	for (unsigned int i = 0; i < territorios.size(); i++) {
		delete territorios[i];
	}

	// Esvaziar o vector e dados
	territorios.clear();
	delete jogador;

	jogador = new Imperio(*orig.jogador);

	// Copiar a informacao de orig, duplicando o objeto
	for (unsigned int i = 0; i < orig.territorios.size(); i++) {
		Territorio* p = orig.territorios[i]->duplica();
		territorios.emplace_back(p);
		if (orig.jogador->procuraTerritorio(p->obtemNome()) != nullptr)
			jogador->adicionaTerritorio(p);
	}

	return *this;
}

int Mundo::obtemAno() const
{
	return ano;
}

int Mundo::obtemTurno() const
{
	return turno;
}

int Mundo::obtemFase() const
{
	return fase;
}

int Mundo::obtemUltimoAleatorio() const
{
	return ultimoAleatorio;
}


Territorio* Mundo::criaTerritorio(const string& tipo)
{
	Territorio* novo;
	if (tipo == "Territorio Inicial") {
		novo = new TerritorioInicial;
		territorios.emplace_back(novo);
		return novo;
	}
	
	//Continentes
	if (tipo == "Duna") {
		novo = new Duna;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Planicie") {
		novo = new Planicie;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Castelo") {
		novo = new Castelo;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Fortaleza") {
		novo = new Fortaleza;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Mina") {
		novo = new Mina;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Montanha") {
		novo = new Montanha;
		territorios.emplace_back(novo);
		return novo;
	}
	
	//Ilhas
	if (tipo == "Pescaria") {
		novo = new Pescaria;
		territorios.emplace_back(novo);
		return novo;
	}
	if (tipo == "Refugio") {
		novo = new Refugio;
		territorios.emplace_back(novo);
		return novo;
	}
	else {
		std::cout << "\nTipo " << tipo << " inexistente!\n";
		return nullptr;
	}
}

string Mundo::obtemTerritoriosMundoString() const
{
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); it++) {
		oss << (*it)->obtemTerritorioString(ano, fase) << endl;
	}
	return oss.str();
}

string Mundo::obtemDadosTerritorioMundoString(const string& nome)
{
	Territorio* procura = procuraTerritorioMundo(nome);
	if (procura == nullptr)
		return string{ "Nao existe nenhum territorio com o nome introduzido!\n" };
	else
		return procura->obtemTerritorioString(ano, fase);
}

string Mundo::verificaTerritorioConquista(const string& territorio)
{
	// Se o territorio existir no Mundo
	Territorio* procuraMundo = procuraTerritorioMundo(territorio);
	if (procuraMundo != nullptr) {
		if (jogador->conquistaTerritorio(procuraMundo, this))
			return string{ "\nO territorio " + territorio + " foi conquistado!\n" };
		else
			return string{ "\nNao foi possivel conquistar o territorio " + territorio + "\n" };
	}
	else
		return string{ "\nO Territorio " + territorio + " nao existe no mundo\n" };
}

string Mundo::obtemTerritoriosImperioString() const
{
	return jogador->obtemImperioString(ano, turno);
}

string Mundo::verificaTecnologiaAdquirir(const string& nomeTecno)
{
	switch (jogador->verificaExisteTecnologiaImperio(nomeTecno))
	{
	case 0: 
		if (jogador->adquireTecnologia(nomeTecno))
			return string{ "A tecnologia " + nomeTecno + " foi adquirida pelo imperio\n" };
		else
			return string{ "O imperio nao conseguiu adquirir a tecnologia " + nomeTecno + "\n" };
	
	case 1:
		return string{ "A tecnologia " + nomeTecno + " ja tinha sido adquirida pelo imperio\n" };
	}

	return string{ "A tecnologia " + nomeTecno + " nao existe no jogo!\n" };
}

bool Mundo::adquireForcaMilitar()
{
	if (jogador->maisMilitar())
		return true;
	return false;
}

bool Mundo::adquireOuro()
{
	if (jogador->maisOuro())
		return true;
	return false;
}

bool Mundo::adquireProduto()
{
	if (jogador->maisProduto())
		return true;
	return false;
}

string Mundo::avancaTempo()
{
	ostringstream out;

	++fase;
	if (fase > 4) {
		++turno;
		fase = 1;
	}
	if (turno > 6) {
		++ano;
		turno = 1;
	}

	if(ano < 3)
		out << obtemTempo();
	if (fase == 2 || fase == 4) {
		out << controlaFase();
	}
	return out.str();
}

string Mundo::controlaFase() 
{
	ostringstream out;

	// Fases do Jogo
	if (fase == 2) {
		int ouro, prod;
		out << "\nRecolha de Produtos!" << endl;
		istringstream iss{ recolheOuroProdutos() };
		iss >> ouro >> prod;
		out << "Ouro recolhido: " << ouro << "\tProdutos recolhidos: " << prod << endl;
		if (jogador->verificaExisteTecnologiaImperio("bolsa"))
			return out.str();
		out << "As trocas nao sao permitidas pois nao possui a tecnologia \"Bolsa de Valores\"\n"<< avancaTempo();
	}
	if (fase == 4) {
		out << "\nFase aleatoria dos eventos!" << endl;
		out << geraEvento();
		if(verificaFimJogo() == 0)
			out << avancaTempo();

	}
	return out.str();
}

string Mundo::obtemTempo() const 
{
	return string{ "\nFase: " + std::to_string(fase) + "\tAno: " + std::to_string(ano) + "\tTurno: " + std::to_string(turno) };
}

string Mundo::geraEvento()
{
	std::unique_ptr<Evento> e{ Evento::sorteiaEvento(this) };
	return e->acaoEvento(jogador, ano, this);
}

string Mundo::acionaEvento(const string& evento)
{
	std::unique_ptr<Evento> e{ Evento::lancaEvento(evento) };
	return e->acaoEvento(jogador, ano, this);
}

string Mundo::recolheOuroProdutos()
{
	ostringstream oss;
	oss << jogador->recolheOuro(ano,turno) << " ";
	oss << jogador->recolheProdutos(ano,turno);
	return oss.str();
}

int Mundo::verificaFimJogo() const
{
	if (jogador->obtemNumeroTerritorios() == 0)
		return 1;
	if (jogador->obtemNumeroTerritorios() == territorios.size() && fase > 0)
		return 2;
	if (ano == 3)
		return 3;
	return 0;
}

int Mundo::calculaPontuacao()
{
	int pontuacao = 0;
	return pontuacao = jogador->obtemPontuacaoTerritorios(this) + jogador->obtemPontuacaoTecnologias();
}

int Mundo::obtemNumeroTerritoriosMundo() const
{
	return static_cast<unsigned int>(territorios.size());
}

int Mundo::geraAleatorio(const int& min, const int& max)
{
	ultimoAleatorio = rand() % max + min;
	return ultimoAleatorio;
}

void Mundo::acrescentaOuroImperio(const int& valor)
{
	jogador->acrescentaOuro(valor);
}

void Mundo::acrescentaProdImperio(const int& valor)
{
	jogador->acrescentaProduto(valor);
}

int Mundo::obtemNumeroTerrImp() const
{
	return jogador->obtemNumeroTerritorios();
}

string Mundo::adicionaTerritorioImperio(const string& nome)
{
	Territorio* alvo = procuraTerritorioMundo(nome);
	if (alvo != nullptr) {
		if (procuraTerritorioImperio(nome) == nullptr) {
			jogador->adicionaTerritorio(procuraTerritorioMundo(nome));
			return string{ "O territorio " + nome + " foi adicionado ao Imperio\n" };
		}
		else
			return string{ "O territorio " + nome + " ja faz parte do Imperio\n" };
	}
	else
		return string{ "O territorio " + nome + " nao existe no mundo\n" };
}

string Mundo::adicionaTecnologiaImperio(const string& nomeTecno)
{
	if (jogador->verificaExisteTecnologiaImperio(nomeTecno))
		return string{ "O jogador ja obteve a tecnologia " + nomeTecno + "\n" };
	if (!jogador->verificaExisteTecnologia(nomeTecno))
		return string{ "Nao existe a tecnologia com o nome: " + nomeTecno + "\n" };
	jogador->adicionaTecnologia(nomeTecno);
	jogador->alteraImperio(nomeTecno);
	return string{ "\nA tecnologia " + nomeTecno + " foi adicionada ao Imperio\n" };
}

ostream& operator<<(ostream& out, const Mundo& novoM) {

	out << "\nUltimo Aleatorio: " << novoM.obtemUltimoAleatorio() << endl;
	out << "Territorios do Mundo: " << endl;
	out << novoM.obtemTerritoriosMundoString();

	out << "-----------------------------------------------------------"
		   "-----------------------------------------------------------\n\n";

	out << "Informacoes sobre o Imperio e seus territorios: " << endl;
	out << novoM.obtemTerritoriosImperioString();

	return out;
}