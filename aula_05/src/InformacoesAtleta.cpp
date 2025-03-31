#include "InformacoesAtleta.hpp"
#include <iostream>

using namespace std;

InformacoesAtleta::InformacoesAtleta() {

}

InformacoesAtleta::~InformacoesAtleta() {

}

void InformacoesAtleta::imprime_exclusivos_atleta(Atleta *a) {

    if(Nadador *n = dynamic_cast <Nadador*>(a)) {
        cout << "É um nadador, e sua categoria é " << n->getCategoria() << endl;
    }
    else if (Corredor *c = dynamic_cast <Corredor*>(a)) {
        cout << "É um corredor, e o peso deste corredor é " << c->getPeso() << endl;
    }
}

void InformacoesAtleta::imprime_informacoes_atleta(Atleta *a) {
    a->imprime_info();
}
