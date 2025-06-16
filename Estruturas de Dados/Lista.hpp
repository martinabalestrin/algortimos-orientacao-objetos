#pragma once

#include <iostream>

#define TAM_MAX 100

template <class T>
class Lista {

public:
    Lista();
    ~Lista();

    bool inserir(T valor);
    bool remover(int id);

    T get(int id) const;
    int getTam() const { return tam; }

    void imprimir() const;

private:
    T dados[TAM_MAX];
    int tam;
};

template <class T>
Lista<T>::Lista() : tam(0) {}

template <class T>
Lista<T>::~Lista() {}

template <class T>
bool Lista<T>::inserir(T valor) {
    if (tam < TAM_MAX) {
        dados[tam] = valor;
        tam++;
        return true;
    }
    return false; // Lista cheia
}

template <class T>
bool Lista<T>::remover(int id) {
    if (id < 0 || id >= tam) return false; // Índice inválido

    for (int i = id; i < tam - 1; ++i) {
        dados[i] = dados[i + 1];
    }
    tam--;

    return true;
}

template <class T> 
T Lista<T>::get(int id) const {
    if (id < 0 || id >= tam) {
        std::cout << "Índice fora dos limites da lista" << std::endl;
        return T();
    }
    else {
        return dados[id];
    }
}

template <class T>
void Lista<T>::imprimir() const {

    if (tam == 0) {
        std::cout << "Lista vazia" << std::endl;
        return;
    }

    for (int i = 0; i < tam; ++i) {
        std::cout << dados[i] << " ";
    }
    std::cout << std::endl;
}