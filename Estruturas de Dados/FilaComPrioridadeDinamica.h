#pragma once
#include <iostream>

using namespace std;

template<class T>
class FilaComPrioridade {

public:
    FilaComPrioridade();
    ~FilaComPrioridade();

    bool empty() const;
    void push_back(T x, int prioridade);
    void pop_front();
    T front() const;
    T back() const;
    void clear();
    int getTam() const { return tam; }

private:

    struct Nodo {
        T valor;
        int prioridade;
        Nodo* prox;
    };

    Nodo* inicio;
    int tam;
};

template<class T>
FilaComPrioridade<T>::FilaComPrioridade() {
    inicio = nullptr;
    tam = 0;
}

template<class T>
FilaComPrioridade<T>::~FilaComPrioridade() {
    clear();
}

template<class T>
bool FilaComPrioridade<T>::empty() const {
    return tam == 0;
}

template<class T>
void FilaComPrioridade<T>::push_back(T x, int prioridade) {

    Nodo* novo = new Nodo{ x, prioridade, nullptr };

    if (empty() || prioridade > inicio->prioridade) {
        novo->prox = inicio;
        inicio = novo;
    }
    else {
        Nodo* atual = inicio;

        while (atual->prox != nullptr && atual->prox->prioridade >= prioridade) {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }

    tam++;
}

template<class T>
void FilaComPrioridade<T>::pop_front() {

    if (!empty()) {
        Nodo* temp = inicio;
        inicio = inicio->prox;
        delete temp;
        tam--;
    }
    else {
        cout << "A fila está vazia!" << endl;
    }
}

template<class T>
T FilaComPrioridade<T>::front() const {

    if (!empty()) {
        return inicio->valor;
    }

    else {
        cout << "A fila está vazia!" << endl;
        return T();
    }
}

template<class T>
T FilaComPrioridade<T>::back() const {

    if (!empty()) {
        Nodo* atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }

        return atual->valor;
    }

    else {
        cout << "A fila está vazia!" << endl;
        return T();
    }
}

template<class T>
void FilaComPrioridade<T>::clear() {

    while (!empty()) {
        pop_front();
    }
}