#include "Nadador.hpp"
#include <iostream>

using namespace std;

Nadador::Nadador() {

}

Nadador::Nadador(Atleta *atleta, string categoria):
    atleta(atleta), categoria(categoria) {

}

Nadador::~Nadador() {

}

string Nadador::getCategoria() {
    return categoria;
}

void Nadador::imprime_info() {
    atleta->imprime_info();
    cout << "Categoria: " << getCategoria() << endl;
}
