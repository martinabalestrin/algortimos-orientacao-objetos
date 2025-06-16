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

		// M�todos
		bool empty(); // Verifica se a pilha est� vazia
		bool full(); // Verifica se a pilha est� cheia
		void push_back(T x); // Insere um elemento no final da fila
		void pop_front(); // Remove o elemento do in�cio da fila
		T front(); // Retorna o elemento do in�cio da fila
		T back(); // Retorna o elemento do final da fila
		int find_ReturnId(T x); // Verifica se um elemento est� na fila e retorna o �ndice, ou -1 se n�o estiver
		void pop_ByElement(T x); // Remove um elemento espec�fico da fila
		void clear(); // Limpa a fila

		// Getter
		int getTam() { return tam; }
		T getDados(int i) { return dados[i]; }

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
		cout << "A fila est� cheia!" << endl;
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
		cout << "A fila est� vazia!" << endl;
	}
}

template<class T>
T Fila<T>::front() {
	if (!empty()) {
		return dados[0];
	}
	else {
		cout << "A fila est� vazia!" << endl;
		return T();
	}
}

template<class T>
T Fila<T>::back() {
	if (!empty()) {
		return dados[tam - 1];
	}
	else {
		cout << "A fila est� vazia!" << endl;
		return T();
	}
}

template<class T>
int Fila<T>::find_ReturnId(T x) {
	for (int i = 0; i < tam; i++) {
		if (dados[i] == x) {
			return i;
		}
	}
	return -1;
}

template<class T>
void Fila<T>::pop_ByElement(T x) {
	
	int id = find_ReturnId(x);

	if (id != -1) {
		for (int i = id; i < tam - 1; i++) {
			dados[i] = dados[i + 1];
		}
		tam--;
	}
	else {
		cout << "O elemento nao esta na fila!" << endl;
	}
}

template<class T>
void Fila<T>::clear() {
	while(!empty()) {
		pop_front();
	}
}