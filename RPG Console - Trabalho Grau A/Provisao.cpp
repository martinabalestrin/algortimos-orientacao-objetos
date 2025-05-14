#include "Provisao.hpp"

// Construtores
Provisao::Provisao(const std::string& nome, int energia)
    : Item(nome), energiaGanhar(energia) {
}

Provisao::Provisao() {

}

// Getters
int Provisao::energia() const {
    return energiaGanhar;
}

// Métodos
void Provisao::usar() {
    std::cout << "Usando provisao: " << getNome() << " -> Energia recuperada: " << energiaGanhar << std::endl;
}

// DEBUG
void Provisao::debugItem() const {
    std::cout << "=== DEBUG PROVISAO ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: c" << std::endl;
    std::cout << "Energia: " << energiaGanhar << std::endl;
    std::cout << "======================" << std::endl;
}
