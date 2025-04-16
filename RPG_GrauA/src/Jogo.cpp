#include <iostream>

#include "Jogo.hpp"

// ------------------
// Construtor
// ------------------

Jogo::Jogo() {
    escolha = 0;
    jogando = true;
}

// ------------------
// Destrutor
// ------------------

Jogo::~Jogo() {

}

// ------------------
// Setters
// ------------------



// ------------------
// Getters
// ------------------

bool Jogo::getJogando() {
    return jogando;
}

// ------------------
// M�todos
// ------------------

int Jogo::menuInicial() {

    cout << "Seja bem-vindo ao 'nome do jogo'!\n" << endl;
    cout << ">> 1 - Novo jogo" << endl;
    cout << ">> 2 - Continuar" << endl;
    cout << ">> 3 - Cr�ditos" << endl;
    cout << ">> 4 - Sair" << endl;
    cout << "\nOp��o: ";
    cin >> escolha;
    cout << endl;

    switch(escolha) {

        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            jogando = false;
            break;
        default:
            // implementa��o
            break;
    }
}
