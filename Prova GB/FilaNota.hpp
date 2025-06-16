#pragma once

#include <iostream>
#include "Nota.h"

class FilaNota {

public:
    FilaNota();
    ~FilaNota();

    bool empty() const;
    void push_back(const Nota& x);
    void pop_front();
    const Nota& front() const;
    Nota back() const;
    bool findByNumAluno(int numAluno) const;
    void pop_ByNumAluno(int numAluno);
    void clear();

    int getTam() const { return tam; }

private:
    struct Nodo {
        Nota dado;
        Nodo* prox;
    };

    Nodo* inicio;
    Nodo* fim;
    int tam;
};
