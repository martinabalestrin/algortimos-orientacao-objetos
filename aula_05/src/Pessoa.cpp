#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa() {

}

Pessoa::Pessoa(string nome, int idade):
    nome(nome), idade(idade) {
    contador++;
}

Pessoa::~Pessoa() {

}

void Pessoa::setNome(string nome) {
    this->nome=nome;
}

void Pessoa::setIdade(int idade) {
    this->idade=idade;
}

string Pessoa::getNome() {
    return nome;
}

int Pessoa::getIdade() {
    return idade;
}

void Pessoa::imprime_dados() {
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() << endl;
}

int Pessoa::contador = 0;

int Pessoa::getContador() {
    return contador;
}
