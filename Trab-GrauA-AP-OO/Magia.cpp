#include "Magia.hpp"
#include <iostream>

// Construtor
Magia::Magia(const std::string& nome, int dano)
    : Item(nome), dano(dano) {
}

// Métodos
void Magia::usar() {
    std::cout << "Voce lancou " << getNome() << "! "
        << "(Dano: " << dano << ")" << std::endl;
}

int Magia::getDano() const {
    return dano;
}

// DEBUG
void Magia::debugItem() const {
    std::cout << "Magia - Nome: " << getNome() << std::endl;
}
