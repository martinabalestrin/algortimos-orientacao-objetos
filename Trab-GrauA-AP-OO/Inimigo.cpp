#include "Inimigo.hpp"
#include <iostream>

// Construtores
Inimigo::Inimigo(std::string nome, int hab, int ene, int sorte,
    Item* item, Tesouro t, Provisao p)
    : Personagem(nome, hab, ene, sorte),
    itemDropado(item), tesouro(t), provisao(p) {
}

Inimigo::Inimigo() {

}

// Métodos
int Inimigo::atacar() {
    int dano = habilidade;
    std::cout << nome << " ataca com " << dano << " de dano!\n";
    return dano;
}

bool Inimigo::defender() {
    std::cout << nome << " (Inimigo) tenta se defender." << std::endl;
}

bool Inimigo::temDrop() const {
    return true;
}

void Inimigo::receberDano(int dano) {
    energia -= dano;
    if (energia < 0) energia = 0;
    std::cout << nome << " recebeu " << dano << " de dano! Energia atual: " << energia << "\n";
}

// Setters
void Inimigo::setItem(Item* item) {
    itemDropado = item;
}

void Inimigo::setTesouro(int valor) {
    tesouro.SetValor(valor);
}

void Inimigo::setQntProvisao(int quantidade) {
    this->qntProvisao=quantidade;
}

void Inimigo::setCapSeGanhar(int cap) {
    this->capSeGanhar=cap;
}

void Inimigo::setCapSeperder(int cap) {
    this->capSePerder=cap;
}

// Getters
Item* Inimigo::getItem() const {
    return itemDropado;
}

Tesouro Inimigo::getTesouro() const {
    return tesouro;
}

int Inimigo::getQntProvisao() const {
    return qntProvisao;
}

int Inimigo::getCapSeGanhar() const {
    return capSeGanhar;
}

int Inimigo::getCapSePerder() const {
    return capSePerder;
}
