#include "Tesouro.hpp"
#include <iostream>

// Construtores
Tesouro::Tesouro(const std::string& nome, int valor)
    : Item(nome), valor(valor) {
}

Tesouro::Tesouro() {

}

// Métodos
void Tesouro::usar() {
    std::cout << "Abrindo tesouro: " << getNome() << ", valor: " << valor << " moedas de ouro." << std::endl;
}

int Tesouro::getValor() const { return valor;}

// Setters
void Tesouro::SetValor(int valor) {
    this->valor=valor;
}

// DEBUG
void Tesouro::debugItem() const{
    std::cout << "Tesouro - Nome: " << getNome()
              << ", Valor: " << valor << std::endl;
}
