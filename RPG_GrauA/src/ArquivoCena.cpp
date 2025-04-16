#include "ArquivoCena.hpp"

ArquivoCena::ArquivoCena() {

}

ArquivoCena::~ArquivoCena() {

}


Cena ArquivoCena::carregarCena(int id) {

    ifstream arqEntrada;
    stringstream ss;

    ss << id << ".txt";
    string nomeArquivo = ss.str();

    arqEntrada.open(nomeArquivo);

    arqEntrada
}

