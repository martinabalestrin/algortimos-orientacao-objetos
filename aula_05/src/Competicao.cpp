#include "Competicao.hpp"
#include <iostream>

using namespace std;

Competicao::Competicao() {

}

Competicao::Competicao(string nome, Data *data, string local):
    nome(nome), data(data), local(local) {

}


Competicao::~Competicao() {

}

string Competicao::getNome() {
    return nome;
}

string Competicao::getLocal() {
    return local;
}

void Competicao::imprime_competicao() {
    cout << "Competição: " << getNome() << endl;
    cout << "Local: " << getLocal() << endl;
    data->imprime_info();
}
