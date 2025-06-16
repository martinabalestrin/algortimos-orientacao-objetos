#pragma once
#include <iostream>

template <class T>
class Lista {

public:
    Lista();
    ~Lista();

    void inserirOrdenado(T valor); // Insere mantendo a lista ordenada
    bool remover(int id); // Remove pelo índice
    bool remover_por_valor(T valor); // Remove primeiro valor encontrado
    void clear(); // Limpa toda a lista

    T get(int id) const; // Retorna valor por índice
    int find(T valor) const; // Retorna índice de valor
	bool empty() const; // Retorna se a lista está vazia
    int size() const;  // Quantidade de elementos
    void imprimir() const; // Imprime os elementos

private:
    struct Nodo {
        T valor;
        Nodo* prox;
    };

    Nodo* inicio;
    int tam;

    Nodo* getNodo(int id) const;
};

template <class T>
Lista<T>::Lista() : inicio(nullptr), tam(0) {}

template <class T>
Lista<T>::~Lista() {
    clear();
}

template <class T>
void Lista<T>::inserirOrdenado(T valor) {

    Nodo* novo = new Nodo{ valor, nullptr };

    if (!inicio || valor < inicio->valor) {
        novo->prox = inicio;
        inicio = novo;
    }

    else {
        Nodo* atual = inicio;

        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }

    tam++;
}

template <class T>
bool Lista<T>::remover(int id) {

    if (id < 0 || id >= tam) return false;

    Nodo* temp;
    if (id == 0) {
        temp = inicio;
        inicio = inicio->prox;
    }

    else {
        Nodo* anterior = getNodo(id - 1);
        temp = anterior->prox;
        anterior->prox = temp->prox;
    }

    delete temp;
    tam--;
    return true;
}

template <class T>
bool Lista<T>::remover_por_valor(T valor) {

    Nodo* atual = inicio;
    Nodo* anterior = nullptr;

    while (atual) {
        if (atual->valor == valor) {

            if (!anterior) {
                inicio = atual->prox;
            }
            else {
                anterior->prox = atual->prox;
            }

            delete atual;
            tam--;

            return true;
        }

        anterior = atual;
        atual = atual->prox;
    }
    return false;
}

template <class T>
void Lista<T>::clear() {

    while (inicio) {
        Nodo* temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
    tam = 0;
}

template <class T>
T Lista<T>::get(int id) const {

    Nodo* nodo = getNodo(id);

    if (!nodo) {
        std::cout << "Índice inválido!" << std::endl;
        return T();
    }

    return nodo->valor;
}

template <class T>
int Lista<T>::find(T valor) const {

    Nodo* atual = inicio;
    int i = 0;
    while (atual) {
        if (atual->valor == valor) return i;
        atual = atual->prox;
        i++;
    }

    return -1;
}

template <class T>
bool Lista<T>::empty() const {
    return tam == 0;
}

template <class T>
int Lista<T>::size() const {
    return tam;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getNodo(int id) const {

    if (id < 0 || id >= tam) return nullptr;

    Nodo* atual = inicio;
    for (int i = 0; i < id; ++i) {
        atual = atual->prox;
    }

    return atual;
}

template <class T>
void Lista<T>::imprimir() const {

    if (empty()) {
        std::cout << "Lista vazia!" << std::endl;
        return;
    }

    Nodo* atual = inicio;
    int i = 0;
    while (atual) {

        std::cout << "[" << i << "] " << atual->valor << std::endl;
        atual = atual->prox;
        i++;
    }
}
