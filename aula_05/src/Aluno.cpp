#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno() {

}

Aluno::Aluno(Pessoa *pessoa, double nota):
    pessoa(pessoa), nota(nota) {

}

Aluno::~Aluno() {

}

void Aluno::setNota(double nota) {
    this->nota=nota;
}

double Aluno::getNota() const {
    return nota;
}

void Aluno::imprime_dados() {
    pessoa->imprime_dados();
    cout << "Nota: " << getNota() << endl;
}
