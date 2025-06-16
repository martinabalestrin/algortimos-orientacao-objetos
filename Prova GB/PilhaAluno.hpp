#pragma once

#include <iostream>
#include "Aluno.h"

class PilhaAluno {

public:
    PilhaAluno();
    ~PilhaAluno();

    bool empty(); // Verifica se a pilha está vazia
    void push(Aluno x); // Insere um aluno no topo
    void pop(); // Remove o aluno do topo
    Aluno top(); // Retorna o aluno do topo
    bool findByID(int id); // Verifica se há um aluno com o número informado
    std::string getNomeByID(int id) const; // Retorna o nome do aluno com o ID informado
    void clear(); // Esvazia a pilha

    int getTam() const { return tam; }

private:
    struct Nodo {
        Aluno valor;
        Nodo* prox;
    };

    Nodo* topo;
    int tam;
};
