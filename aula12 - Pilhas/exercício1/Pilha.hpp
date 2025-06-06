#pragma once
#include <iostream>
#define TAM_MAX 100

using namespace std;

template <class T>
class Pilha {

    public:
        // Construtor
        Pilha();
        // Destrutor
        ~Pilha();

        // M�todos
		bool empty(); // Verifica se a pilha est� vazia
		bool full(); // Verifica se a pilha est� cheia
		void push(T x); // Insere um elemento na pilha
		void pop(); // Remove o elemento do topo da pilha
		T top(); // Retorna o elemento do topo da pilha
		bool find(T x); // Verifica se um elemento est� na pilha

        // Getter
		int getTam() { return tam; }

    private:
        T dados[TAM_MAX];
        int tam;
};

template <class T>
Pilha<T>::Pilha() {
    tam = 0;
}

template <class T>
Pilha<T>::~Pilha() {

}

// M�todos
template <class T>
bool Pilha<T>::empty() {

    if (tam <= 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
bool Pilha<T>::full() {

    if (tam == TAM_MAX) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void Pilha<T>::push(T x) {

    if (!full()) {
        dados[tam] = x;
        tam++;
    }
    else {
        cout << "Pilha cheia!" << endl;
    }
}

template <class T>
void Pilha<T>::pop() {

    if (!empty()) {
        tam--;
    }
    else {
        cout << "Pilha vazia!" << endl;
    }
}

template <class T>
T Pilha<T>::top() {

    if (!empty()) {
        return dados[tam];
    }
    else {
        cout << "Pilha vazia!" << endl;
        return nullptr;
    }
}

template <class T>
bool Pilha<T>::find(T x) {

    if (!empty()) {
        for (int i = 0; i <= tam; i++) {
            if (dados[i] == x) {
                return true;
            }
        }
        return false;
    }

    else {
        cout << "Pilha vazia!" << endl;
    }
}
