#include "PilhaAluno.hpp"

PilhaAluno::PilhaAluno() : topo(nullptr), tam(0) {}

PilhaAluno::~PilhaAluno() {
    clear();
}

bool PilhaAluno::empty() {
    return topo == nullptr;
}

void PilhaAluno::push(Aluno x) {
    Nodo* novo = new Nodo{ x, topo };
    topo = novo;
    tam++;
}

void PilhaAluno::pop() {
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

Aluno PilhaAluno::top() {
    if (!empty()) {
        return topo->valor;
    }
    else {
        std::cout << "Pilha vazia!" << std::endl;
        return Aluno();
    }
}

bool PilhaAluno::findByID(int id) {
    Nodo* atual = topo;
    while (atual) {
        if (atual->valor.getNumero() == id)
            return true;
        atual = atual->prox;
    }
    return false;
}

std::string PilhaAluno::getNomeByID(int id) const {
    Nodo* atual = topo;
    while (atual != nullptr) {
        if (atual->valor.getNumero() == id) {
            return atual->valor.getNome();
        }
        atual = atual->prox;
    }
    return ""; // Retorna string vazia se não encontrar
}


void PilhaAluno::clear() {
    while (!empty()) {
        pop();
    }
}
