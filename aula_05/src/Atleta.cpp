#include "Atleta.hpp"
#include <iostream>

Atleta::Atleta() {

}

Atleta::Atleta(string nome, int idade):
    nome(nome), idade(idade) {

}

Atleta::~Atleta() {

}

string Atleta::getNome() {
    return nome;
}

int Atleta::getIdade() {
    return idade;
}

void Atleta::imprime_info() {
    cout << "Nome: " << getNome() << endl;
    cout << "idade: " << getIdade() << endl;
}
