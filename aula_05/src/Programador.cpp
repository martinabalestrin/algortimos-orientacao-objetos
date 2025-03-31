#include "Programador.hpp"
#include <iostream>

Programador::Programador() {

}

Programador::Programador(Pessoa *pessoa, string linguagem):
    pessoa(pessoa), linguagem(linguagem) {

}

Programador::~Programador() {

}

void Programador::setLinguagem(string linguagem) {
    this->linguagem=linguagem;
}

string Programador::getLinguagem() {
    return linguagem;
}

void Programador::imprime_dados() {
    pessoa->imprime_dados();
    cout << "Linguagem: " << getLinguagem() << endl;
}
