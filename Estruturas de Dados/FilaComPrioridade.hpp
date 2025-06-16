#pragma once
#include <iostream>
#define TAM_MAX 100

using namespace std;

template<class T>
struct Elemento {
	T valor;
	int prioridade;
};

template<class T>
class FilaComPrioridade {

	public:
		// Construtor
		FilaComPrioridade();
		// Destrutor
		~FilaComPrioridade();

		// Métodos
		bool empty(); // Verifica se a fila está vazia
		bool full(); // Verifica se a fila está cheia
		void push_back(T x, int prioridade); // Insere um elemento na posição correta com base na prioridade
		void pop_front(); // Remove o elemento do início da fila
		T front(); // Retorna o elemento do início da fila
		T back(); // Retorna o elemento do final da fila
		void clear(); // Limpa a fila

		// Getter
		int getTam() { return tam; }
		T getDados_Valor(int i) { return dados[i].valor; } // Permite acessar os elementos da fila por índice

	private:
		Elemento<T> dados[TAM_MAX];
		int tam;
};

template<class T>
FilaComPrioridade<T>::FilaComPrioridade() {
	tam = 0;
}

template<class T>
FilaComPrioridade<T>::~FilaComPrioridade() {
	
}

template<class T>
bool FilaComPrioridade<T>::empty() {
	return tam == 0;
}

template<class T>
bool FilaComPrioridade<T>::full() {
	return tam == TAM_MAX;
}

template<class T>
void FilaComPrioridade<T>::push_back(T x, int prioridade) {

	//	0 - Normal
	//	1 - Importante
	//	2 - Urgente

	if (!full()) {

		int i = tam - 1;

		// Quanto maior o número da prioridade, mais a frente fica!
		while (i >= 0 && dados[i].prioridade < prioridade) {
			dados[i + 1] = dados[i];
			i--;
		}

		dados[i + 1].valor = x;
		dados[i + 1].prioridade = prioridade;
		tam++;		
	}
	else {
		cout << "A fila está cheia!" << endl;
	}
}

template<class T>
void FilaComPrioridade<T>::pop_front() {
	if (!empty()) {
		for (int i = 0; i < tam - 1; i++) {
			dados[i] = dados[i + 1];
		}
		tam--;
	}
	else {
		cout << "A fila está vazia!" << endl;
	}
}

template<class T>
T FilaComPrioridade<T>::front() {
	if (!empty()) {
		return dados[0].valor;
	}
	else {
		cout << "A fila está vazia!" << endl;
		return T();
	}
}

template<class T>
T FilaComPrioridade<T>::back() {
	if (!empty()) {
		return dados[tam - 1].valor;
	}
	else {
		cout << "A fila está vazia!" << endl;
		return T();
	}
}

template<class T>
void FilaComPrioridade<T>::clear() {
	while(!empty()) {
		pop_front();
	}
}