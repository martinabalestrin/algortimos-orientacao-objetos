#pragma once

using namespace std;

class Jogo {

    public:
        // Construtor
        Jogo();
        // Destrutor
        ~Jogo();

        // Setters

        // Getters
        bool getJogando();

        // M�todos
        int menuInicial();

    private:
        // Atributos
        int escolha;
        bool jogando;

};
