#include "Personagem.hpp"

// Construtor
Personagem::Personagem(std::string nome, int habilidade, int energia, int sorte)
    : nome(nome), habilidade(habilidade), energia(energia), sorte(sorte) {
}

Personagem::Personagem() {

}

// Getters
std::string Personagem::getNome() const {
    return nome;
}

int Personagem::getEnergia() const {
    return energia;
}

int Personagem::getHabilidade() const {
    return habilidade;
}

int Personagem::getSorte() const {
    return sorte;
}

// Setters
void Personagem::setEnergia(int novaEnergia) {
    energia = novaEnergia;
}

void Personagem::setHabilidade(int novaHabilidade) {
    habilidade = novaHabilidade;
}

void Personagem::setSorte(int novaSorte) {
    sorte = novaSorte;
}

void Personagem::setNome(std::string nome) {
    this->nome=nome;
}

// Métodos virtuais
int Personagem::atacar() {
    return habilidade;
}

void Personagem::receberDano(int dano) {
    energia -= dano;
    if (energia < 0) energia = 0;
}

