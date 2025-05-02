#include "ItemComum.hpp"

// Construtores
ItemComum::ItemComum(const std::string& nome)
    : Item(nome) {
}

ItemComum::ItemComum() {

}

// Métodos
void ItemComum::usar() {
    std::cout << "Observando " << getNome() << "..." << std::endl;
}

// DEBUG
void ItemComum::debugItem() const {
    std::cout << "=== DEBUG ITEMCOMUM ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: c" << std::endl;
    std::cout << "======================" << std::endl;
}

