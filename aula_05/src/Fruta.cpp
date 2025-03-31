#include "Fruta.hpp"
#include <iostream>

using namespace std;

Fruta::Fruta() {

}

Fruta::Fruta(double preco):
    preco(preco) {

}

Fruta::~Fruta() {

}

void Fruta::setPreco(double p) {
    preco = p;
}

double Fruta::getPreco() {
    return preco;
}

double Fruta::calcula_preco(double taxaImposto) {
    // taxa de imposto em >> porcentagem <<
    return preco*(1+(taxaImposto/100));
}
