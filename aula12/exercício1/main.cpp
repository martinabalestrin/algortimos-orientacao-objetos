#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Pilha.hpp"

using namespace std;

int gerarNumeroAleatorio(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void pratosLavados(Pilha<int>* pilha) {
	
	int qnt = gerarNumeroAleatorio(1, 5);
	cout << "Quantidade de pratos lavados: " << qnt << endl;

	for(int i = 0; i < qnt; i++) {
		if (!pilha->full()) {
			pilha->push(1);
		}
}

void pratosSecados(Pilha<int>* pilha) {
	
	int qnt = gerarNumeroAleatorio(1, 3);
	cout << "Quantidade de pratos secados: " << qnt << endl;

	for(int i = 0; i < qnt; i++) {
		if(!pilha->empty()) {
			pilha->pop();
		}
	}
}

void comecarTurno(Pilha<int>* pilha) {
	
	pratosLavados(pilha);
	pratosSecados(pilha);

	cout << "Pratos na pilha: " << pilha->getTam() << endl;
}

int main() {

	srand(time(nullptr));
	Pilha<int> pilhaDePratos;

	int turnos = gerarNumeroAleatorio(1, 10);
	cout << "Turnos: " << turnos << endl;

	for (int i = 0; i < turnos; i++) {
		cout << "Turno " << (i + 1) << endl;
		comecarTurno(&pilhaDePratos);
	}

	cout << "Pratos que nao foram secados: " << pilhaDePratos.getTam() << endl;

	return 0;
}