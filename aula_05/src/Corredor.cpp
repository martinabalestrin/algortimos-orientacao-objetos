#include "Corredor.hpp"
#include <iostream>

using namespace std;

Corredor::Corredor() {

}

Corredor::Corredor(Atleta *atleta, float peso, Competicao *competicao):
    atleta(atleta), peso(peso), competicao(competicao) {

}

Corredor::~Corredor() {

}

float Corredor::getPeso() {
    return peso;
}

void Corredor::imprime_info() {
    atleta->imprime_info();
    cout << "Peso: " << getPeso() << endl;
    competicao->imprime_competicao();
}
