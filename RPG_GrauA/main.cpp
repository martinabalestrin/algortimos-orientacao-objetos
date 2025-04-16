#include <iostream>
#include <locale.h>

#include "Jogo.hpp"
#include "ArquivoCena.hpp"
#include "Cena.hpp"
#include "Personagem.hpp"

using namespace std;



int main() {

    setlocale(LC_ALL, "");

    Jogo jogo;
    ArquivoCena arqCena;

    arqCena.carregarCena(1);

/*
    while(jogo.getJogando()) {
        jogo.menuInicial();
    }
*/

    return 0;
}
