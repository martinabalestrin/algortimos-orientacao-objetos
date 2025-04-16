#pragma once

#include <string.h>

using namespace std;

// Classe Abstrata (tornar)
class Personagem {

    public:
        // Construtor
        Personagem();
        Personagem(string nome, int habilidade, int energia, int sorte);
        // Destrutor
        ~Personagem();

        // Setters

        // Getters


        // Métodos


    protected:
        // Atributos
        string nome;
        int habilidade;
        int energia;
        int sorte;
};
