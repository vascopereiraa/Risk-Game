#include "Mundo.h"
#include "Interface.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;
using std::endl;
using std::ifstream;

void Interface::cmdCarrega(istringstream& iss) 
{
	string nomeFicheiro;
	iss >> nomeFicheiro;
	if (iss.fail()) {
		std::cerr << "[FAIL] Impossivel obter nome de ficheiro" << endl;
		return;
	}
	//Abertura de ficheiro para leitura linha a linha
	abreFicheiro(nomeFicheiro);
}

void Interface::abreFicheiro(const string& nome)
{
	ifstream ficheiro(nome);
	string linha, tipo;

	if (ficheiro.is_open() && ficheiro.good())
		while (getline(ficheiro, linha)) {
			comandos(linha);
		}
	else
		cout << "Nao existe nenhum ficheiro com esse nome" << endl;
	ficheiro.close();
}

void Interface::cmdCria(istringstream& iss)
{
	string tipo;
	int num;
	iss >> tipo >> num;
	for (int i = 0; i < num; i++)
		//Evita escrita da mensagem "tipo ... nao existe" num vezes
		if (mundo->criaTerritorio(tipo) == nullptr)
			break;
}

void Interface::cmdConquista(istringstream& iss)
{
	string nome;
	iss >> nome;
	cout << mundo->verificaTerritorioConquista(nome);
	cout << mundo->avancaTempo();
}

void Interface::cmdLista(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) 
		cout << *mundo << endl;
	else
		cout << mundo->obtemDadosTerritorioMundoString(nome) << endl;
}

void Interface::cmdAdquire(istringstream& iss)
{
	string nome;
	iss >> nome;
	cout << mundo->verificaTecnologiaAdquirir(nome) << endl;
}

void Interface::cmdFevento(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) {
		cout << "Nao foi inserido o nome do evento a ocorrer" << endl;
		return;
	}
	cout << mundo->acionaEvento(nome) << endl;
}

void Interface::cmdToma(istringstream& iss)
{
	string qual, nome;
	iss >> qual >> nome;
	if (iss.fail()) {
		cout << "Tem que inserir o que quer tomar de assalto e o seu nome" << endl;
		return;
	}
	if (qual == "terr")
		cout << mundo->adicionaTerritorioImperio(nome);
	if (qual == "tec")
		cout << mundo->adicionaTecnologiaImperio(nome);
	return;
}

void Interface::cmdMaisMilitar()
{
	if (mundo->adquireForcaMilitar())
		cout << "Forca Militar aumentada!" << endl;
	else
		cout << "Nao foi possivel aumentar a forca militar" << endl;
	cout << mundo->avancaTempo();
}

void Interface::cmdMaisOuro()
{
	if (mundo->adquireOuro())
		cout << "Ouro adquirido!" << endl;
	else
		cout << "Nao foi possivel adquirir ouro" << endl;
	cout << mundo->avancaTempo();
}

void Interface::cmdMaisProd()
{
	if (mundo->adquireProduto())
		cout << "Produto adquirido!" << endl;
	else
		cout << "Nao foi possivel adquirir produto" << endl;
	cout << mundo->avancaTempo();
}

void Interface::cmdModifica(istringstream& iss)
{
	string tipo;
	int n;
	iss >> tipo >> n;

	if (tipo == "ouro")
		mundo->acrescentaOuroImperio(n);
	
	if (tipo == "prod")
		mundo->acrescentaProdImperio(n);

}

void Interface::cmdGrava(istringstream& iss)
{
	string nome;
	iss >> nome;

	if (iss.fail()) 
	{
		cout << "Introduza o nome pelo qual pretende guardar o jogo" << endl;
		return;
	}
	if(gravacoes.find(nome) != gravacoes.end()) 
	{
		cout << "Ja existe uma gravacao com esse nome" << endl;
		return;
	}

	Mundo* novo = new Mundo(*mundo);
	gravacoes.insert(std::pair<string, Mundo*>(nome, novo));

	cout << "\nFoi gravada uma copia do jogo segundo o nome: " << nome << endl;

	for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
		cout << "A gravacao \"" << it->first << "\" foi gravada com os seguintes dados: \n" 
		<< *(it->second) << endl;
}

void Interface::cmdAtiva(istringstream& iss)
{
	string nome;
	iss >> nome;

	if (iss.fail()) {
		cout << "Insira o nome da gravacao que pretende ativar" << endl;
		return;
	}

	auto it = gravacoes.find(nome);
	//Caso o mundo exista, o mundo atual é substituido pelo escolhido, e a gravação deixa de existir
	if(it != gravacoes.end())
	{
		delete mundo;
		mundo = (it->second);
		gravacoes.erase(nome);
		return;
	}
	cout << "Nao existe nenhuma gravacao com esse nome" << endl;
}

void Interface::cmdApaga(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) {
		cout << "Nao foi inserido nome do mundo a apagar" << endl;
		return;
	}
	for (auto it = gravacoes.begin(); it != gravacoes.end(); ++it)
		if (it->first == nome) {
			gravacoes.erase(it);
			cout << "A gravacao " + nome + " foi apagada com sucesso" << endl;
			return;
		}
	cout << "Nao existem gravacoes com esse nome" << endl;
}

void Interface::cmdListaGravacoes(istringstream& iss)
{
	string nome;
	iss >> nome;
	if (iss.fail()) {
		cout << "Gravacoes disponiveis: " << endl;
		for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
			cout << it->first << endl;
		return;
	}
	else
		for (auto it = gravacoes.cbegin(); it != gravacoes.cend(); ++it)
			if (it->first == nome) {
				cout << endl << *(it->second) << endl;
				return;
			}
	cout << "Nao existe uma gravacao com esse nome" << endl;
}

bool Interface::comandos(const string& linha)
{
	string comando;
	istringstream iss(linha);
	iss >> comando;

	// Comandos de Debug
	if (comando == "modifica") { cmdModifica(iss); return true; }
	if (comando == "fevento") { cmdFevento(iss); return true; }
	if (comando == "toma") { cmdToma(iss); return true; }
	// Comandos gerais do jogo
	if (comando == "avanca" && mundo->obtemFase() != 1) {
		cout << mundo->avancaTempo();
		return true; }
	if (comando == "lista") { cmdLista(iss); return true; }
	//Gravações
	if (comando == "grava") { cmdGrava(iss); return true; }
	if (comando == "mostra") { cmdListaGravacoes(iss); return true; }
	if (comando == "ativa") { cmdAtiva(iss); return true; }
	if (comando == "apaga") { cmdApaga(iss); return true; }
	
	// Seletor de comandos das fases
	switch (mundo->obtemFase()) {
	case 0:
		if (comando == "carrega") { cmdCarrega(iss); return true; }
		if (comando == "cria") { cmdCria(iss); return true; }
		break;
	case 1:
		if (comando == "conquista") { cmdConquista(iss); return true; }
		if (comando == "passa") {
			cout << "O jogador decidiu nao conquistar nenhum territorio \n" << mundo->avancaTempo();
			return true;
		}
		break;
	case 2:
		if (comando == "maisouro") { cmdMaisOuro(); return true; }
		if (comando == "maisprod") { cmdMaisProd(); return true; }
		break;
	case 3:
		if (comando == "maismilitar") { cmdMaisMilitar(); return true; }
		if (comando == "adquire") { cmdAdquire(iss);  return true; }
		break;
	default:
		break;
	}

	return false;
}

void Interface::terminaJogo(const int& verificaFim)
{
	if (verificaFim == 1)
		cout << "\nO imperio foi derrotado !" << endl;
	if (verificaFim == 2) {
		cout << "\nO jogador conquistou todos os territorios do mundo!" << endl;
	}
	if (verificaFim == 3 || verificaFim == 0)
		cout << "\nChegou ao fim do jogo " << endl;
	cout << "O jogador obteve a pontuacao " << mundo->calculaPontuacao() << endl;
}

Interface::Interface(Mundo* m) : mundo(m)
{
}

void Interface::menu()
{
	string linha;
	int verificaFim;
	cout << mundo->obtemTempo();
	do 
	{
		cout << "\nComando: ";
		getline(cin, linha);
		if (comandos(linha) == false) {
			cout << "[AVISO] O comando que introduziu nao esta disponivel!" << endl;
			cout << "Comando: " << linha << endl << endl;
		}
		verificaFim = mundo->verificaFimJogo();
	} while (verificaFim == 0 && linha != "sair");

	terminaJogo(verificaFim);
	return;
}