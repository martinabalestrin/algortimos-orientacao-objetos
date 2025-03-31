#include "Banana.hpp"
#include <iostream>

using namespace std;

Banana::Banana() {

}

Banana::Banana(double preco, string tipo):
    Fruta(preco), tipo(tipo) {

}

Banana::~Banana() {

}

void Banana::SetTipo(string t) {
    tipo = t;
}

string Banana::getTipo() {
    return tipo;
}

