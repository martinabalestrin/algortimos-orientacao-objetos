#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Fila.hpp"
#include "FilaComPrioridade.hpp"

using namespace std;

int gerarNumeroAleatorio(int min, int max) {

    return rand() % (max - min + 1) + min;
}

void pessoasChegando(Fila<int>* fila) {

	int qnt = gerarNumeroAleatorio(2, 5);
	cout << "Quantidade de pessoas chegando na fila: " << qnt << endl;

	for (int i = 0; i < qnt; i++) {
		if (!fila->full()) {
			fila->push_back(1);
		}
	}
}

void pessoasSaindo(Fila<int>* fila) {

	int qnt = gerarNumeroAleatorio(0, 2);
	cout << "Quantidade de pessoas saindo da fila: " << qnt << endl;

	for (int i = 0; i < qnt; i++) {
		if (!fila->empty()) {
			fila->pop_front();
		}
	}
}

void comecarTurno(Fila<int>* fila) {

	pessoasChegando(fila);
	pessoasSaindo(fila);

	cout << "Pessoas na fila: " << fila->getTam() << endl;
}

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));
	Fila<int> fila;

	int turnos = gerarNumeroAleatorio(1, 5);
	cout << "Turnos: " << turnos << endl;

	for (int i = 0; i < turnos; i++) {
		cout << "Turno " << (i + 1) << endl;
		comecarTurno(&fila);
	}

	cout << "Pessoas que permaneceram na fila: " << fila.getTam() << endl;

	return 0;
}