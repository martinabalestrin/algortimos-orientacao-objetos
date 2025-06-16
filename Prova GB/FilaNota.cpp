#include "FilaNota.hpp"

FilaNota::FilaNota() : inicio(nullptr), fim(nullptr), tam(0) {}

FilaNota::~FilaNota() {
    clear();
}

bool FilaNota::empty() const {
    return tam == 0;
}

void FilaNota::push_back(const Nota& x) {
    Nodo* novo = new Nodo{ x, nullptr };
    if (empty()) {
        inicio = fim = novo;
    }
    else {
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

void FilaNota::pop_front() {
    if (!empty()) {
        Nodo* temp = inicio;
        inicio = inicio->prox;
        delete temp;
        tam--;
        if (tam == 0) fim = nullptr;
    }
    else {
        std::cout << "A fila está vazia!" << std::endl;
    }
}

const Nota& FilaNota::front() const {

    if (!empty()) {
        return inicio->dado;
    }

    std::cout << "A fila está vazia!" << std::endl;
    static Nota notaVazia;

    return notaVazia;
}

Nota FilaNota::back() const {
    if (!empty()) {
        return fim->dado;
    }
    std::cout << "A fila está vazia!" << std::endl;
    return Nota();
}

bool FilaNota::findByNumAluno(int numAluno) const {
    Nodo* atual = inicio;
    while (atual != nullptr) {
        if (atual->dado.getNumAluno() == numAluno) {
            return true;
        }
        atual = atual->prox;
    }
    return false;
}

void FilaNota::pop_ByNumAluno(int numAluno) {
    if (empty()) {
        std::cout << "A fila está vazia!" << std::endl;
        return;
    }

    Nodo* atual = inicio;
    Nodo* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->dado.getNumAluno() == numAluno) {
            if (anterior == nullptr) {
                // Primeiro elemento
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

    std::cout << "Nota do aluno não encontrada!" << std::endl;
}

void FilaNota::clear() {
    while (!empty()) {
        pop_front();
    }
}
