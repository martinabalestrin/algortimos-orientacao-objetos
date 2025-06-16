#pragma once
#include <iostream>

template <class T>
class Pilha {

public:
    Pilha();
    ~Pilha();

    bool empty(); // Verifica se está vazia
    void push(T x); // Insere no topo
    void pop(); // Remove o topo
    T top(); // Retorna o topo
    bool find(T x); // Verifica se x está presente
    void clear(); // Limpa a pilha

    int getTam() { return tam; }

private:
    struct Nodo {
        T valor;
        Nodo* prox;
    };

    Nodo* topo;
    int tam;
};

template <class T>
Pilha<T>::Pilha() : topo(nullptr), tam(0) {}

template <class T>
Pilha<T>::~Pilha() {
    clear();
}

template <class T>
bool Pilha<T>::empty() {
    return topo == nullptr;
}

template <class T>
void Pilha<T>::push(T x) {
    Nodo* novo = new Nodo{ x, topo };
    topo = novo;
    tam++;
}

template <class T>
void Pilha<T>::pop() {
    if (!empty()) {
        Nodo* temp = topo;
        topo = topo->prox;
        delete temp;
        tam--;
    }
    else {
        std::cout << "Pilha vazia!" << std::endl;
    }
}

template <class T>
T Pilha<T>::top() {
    if (!empty()) {
        return topo->valor;
    }
    else {
        std::cout << "Pilha vazia!" << std::endl;
        return T();
    }
}

template <class T>
bool Pilha<T>::find(T x) {
    Nodo* atual = topo;
    while (atual) {
        if (atual->valor == x) return true;
        atual = atual->prox;
    }
    return false;
}

template <class T>
void Pilha<T>::clear() {
    while (!empty()) {
        pop();
    }
}