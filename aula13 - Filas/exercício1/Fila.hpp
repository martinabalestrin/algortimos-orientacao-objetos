#pragma once
#include <iostream>
#define TAM_MAX 100

using namespace std;

template<class T>
class Fila {

	public:
		// Construtor
		Fila();
		// Destrutor
		~Fila();

		// Métodos
		bool empty(); // Verifica se a pilha está vazia
		bool full(); // Verifica se a pilha está cheia
		void push_back(T x); // Insere um elemento no final da fila
		void pop_front(); // Remove o elemento do início da fila
		T front(); // Retorna o elemento do início da fila
		T back(); // Retorna o elemento do final da fila
		void clear(); // Limpa a fila

		// Getter
		int getTam() { return tam; }

	private:
		T dados[TAM_MAX];
		int tam;
};

template<class T>
Fila<T>::Fila() {
	tam = 0;
}

template<class T>
Fila<T>::~Fila() {
	
}

template<class T>
bool Fila<T>::empty() {
	return tam == 0;
}

template<class T>
bool Fila<T>::full() {
	return tam == TAM_MAX;
}

template<class T>
void Fila<T>::push_back(T x) {
	if (!full()) {
		dados[tam] = x;
		tam++;
	}
	else {
		cout << "A fila está cheia!" << endl;
	}
}

template<class T>
void Fila<T>::pop_front() {
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
T Fila<T>::front() {
	if (!empty()) {
		return dados[0];
	}
	else {
		cout << "A fila está vazia!" << endl;
		return T();
	}
}

template<class T>
T Fila<T>::back() {
	if (!empty()) {
		return dados[tam - 1];
	}
	else {
		cout << "A fila está vazia!" << endl;
		return T();
	}
}

template<class T>
void Fila<T>::clear() {
	while(!empty()) {
		pop_front();
	}
}