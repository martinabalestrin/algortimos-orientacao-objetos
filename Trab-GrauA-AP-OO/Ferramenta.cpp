#include "Ferramenta.hpp"

// COnstrutores
Ferramenta::Ferramenta() {

}

Ferramenta::Ferramenta(const std::string& nome, char tipo, bool combate, int bonusFA, int dano)
    : Item(nome), tipo(tipo), combate(combate), bonusFA(bonusFA), dano(dano) {
}

// Métodos
void Ferramenta::usar() {
    std::cout << "Usando ferramenta: " << getNome() << "\n";
    if (combate) {
        std::cout << "Bonus de Ataque: " << bonusFA << ", Dano: " << dano << std::endl;
    }
}

// Getters
char Ferramenta::getTipo() const { return tipo;}

bool Ferramenta::isCombate() const { return combate;}

int Ferramenta::getBonusFA() const { return bonusFA;}

int Ferramenta::getDano() const { return dano;}

// DEBUG
void Ferramenta::debugItem() const {
    std::cout << "=== DEBUG FERRAMENTA ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: " << tipo << " (esperado: 'w' ou 'r')" << std::endl;
    std::cout << "Combate: " << combate << std::endl;
    std::cout << "FA: " << bonusFA << std::endl;
    std::cout << "Dano: " << dano << std::endl;
    std::cout << "========================" << std::endl;
}
