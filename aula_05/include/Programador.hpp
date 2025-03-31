#pragma once
#include "Pessoa.hpp"
#include <string>

using namespace std;

class Programador: public Pessoa {

    public:
        // Construtor
        Programador();
        Programador(Pessoa *pessoa, string linguagem);
        // Destrutor
        ~Programador();

        // Setters
        void setLinguagem(string linguagem);
        // Getters
        string getLinguagem();

        // Métodos
        void imprime_dados();

    private:
        string linguagem;
        Pessoa *pessoa;
};
