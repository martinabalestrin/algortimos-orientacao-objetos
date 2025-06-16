#pragma once
#include <iostream>

using namespace std;

template <class T>
class Fila {

public:
    Fila();
    ~Fila();

    bool empty() const;
    void push_back(const T& x);
    void pop_front();
    T front() const;
    T back() const;
    int find_ReturnId(const T& x) const;
    void pop_ByElement(const T& x);
    void clear();

    int getTam() const { return tam; }

private:
    struct Nodo {
        T dado;
        Noo* prox;
    };

    Nodo* inicio;
    Nodo* fim;
    int tam;
};

template <class T>
Fila<T>::Fila() {
    inicio = nullptr;
    fim = nullptr;
    tam = 0;
}

template <class T>
Fila<T>::~Fila() {
    clear();
}

template <class T>
bool Fila<T>::empty() const {
    return tam == 0;
}

template <class T>
void Fila<T>::push_back(const T& x) {
    Nodo* novo = new Nodo { x, nullptr };
    if (empty()) {
        inicio = fim = novo;
    }
    else {
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

template <class T>
void Fila<T>::pop_front() {

    if (!empty()) {

        Nodo* temp = inicio;
        inicio = inicio->prox;
        delete temp;
        tam--;

        if (tam == 0) fim = nullptr;
    }

    else {
        cout << "A fila está vazia!" << endl;
    }
}

template <class T>
T Fila<T>::front() const {

    if (!empty()) return inicio->dado;

    cout << "A fila está vazia!" << endl;
    return T();
}

template <class T>
T Fila<T>::back() const {

    if (!empty()) return fim->dado;
    
    cout << "A fila está vazia!" << endl;
    return T();
}

template <class T>
int Fila<T>::find_ReturnId(const T& x) const {

    Nodo* atual = inicio;
    int index = 0;

    while (atual != nullptr) {
        if (atual->dado == x) return index;
        atual = atual->prox;
        index++;
    }
    return -1;
}

template <class T>
void Fila<T>::pop_ByElement(const T& x) {

    if (empty()) {
        cout << "A fila está vazia!" << endl;
        return;
    }

    Nodo* atual = inicio;
    Nodo* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->dado == x) {
            if (anterior == nullptr) {
                // É o primeiro elemento
                inicio = atual->prox;
                if (fim == atual) fim = nullptr;
            }
            else {
                anterior->prox = atual->prox;
                if (fim == atual) fim = anterior;
            }
            delete atual;
            tam--;
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    cout << "O elemento não está na fila!" << endl;
}

template <class T>
void Fila<T>::clear() {

    while (!empty()) {
        pop_front();
    }
}