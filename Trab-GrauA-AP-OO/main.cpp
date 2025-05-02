#include <iostream>
#include <locale.h>

#include "Jogo.hpp"

using namespace std;

void formatacao() {

    // Forçar UTF-8 no terminal (para Windows)
    #ifdef _WIN32
        system("chcp 65001"); // Alterar a página do terminal para UTF-8
        system("cls"); // Limpar a tela
    #endif

    setlocale(LC_ALL, "pt_BR.UTF-8");
}

int main() {

    formatacao();

    Jogo jogo;
    jogo.menuInicial();

    return 0;
}
